/*
 * sulb_main.c	Stupid and Useless Led Board
 *		Module init/exit code. 
 *
 * Author:	Artur DAssumpcao <contact@adassumpcao.net>
 *
 * Copyright:	Copyright (C) 2006 Artur DAssumpcao
 *
 *		This file is part of SULB.
 *		
 *		SULB is free software; you can redistribute it and/or modify
 *		it under the terms of the GNU General Public License as 
 *		published by the Free Software Foundation; either version 2 of 
 *		the License, or (at your option) any later version.
 *		
 *		SULB is distributed in the hope that it will be useful,
 *		but WITHOUT ANY WARRANTY; without even the implied warranty of
 *		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *		GNU General Public License for more details.
 *		
 *		You should have received a copy of the GNU General Public 
 *		License along with SULB; if not, write to the Free Software
 *		Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  
 *		02110-1301  USA 
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/spinlock.h>
#include <linux/ioport.h>
#include <asm/io.h>

#include "sulb_main.h"
#include "cfifo.h"
#include "sulb_timer.h"

/* 
 * This is the sulb device structure.
 */
struct sulb_dev dev;

/*
 * This is the sulb supported file operations structure.
 */
extern struct file_operations sulb_fops;

/*
 * Default device configuration.
 * These parameters can be changed at module loading time. 
 */
unsigned int size = BUF_SIZE;			/* device buffer size 	*/
unsigned long delay =  SULB_TIMER_DELAY;	/* device timer delay 	*/
unsigned int io_port = IO_BASE_PORT;		/* device port address	*/

module_param(size, uint, S_IRUGO);
module_param(delay, ulong, S_IRUGO);
module_param(io_port, uint, S_IRUGO);

/**
 * Takes care of sulb char device intialization.
 */
int __init sulb_init_chrdev(struct sulb_dev *dev)
{
    /*
    Tem como principal funlção de criar/alocar o dispositivo/modulo 
    no sistema para que se possa escutar requisições do kernel
    */
	int ret;

	/* 
	 * Requests the kernel to dinamicaly find and allocate an available
	 * device number for us. 
	 
	 */
	ret = alloc_chrdev_region(&dev->dev_nr, SULB_MINOR, 1, "sulbMT");
	/*
	Requisita a atribuição dinâmica de uma gama contígua de char device numbers. O
parâmetro firstminor indica o primeiro minor number atribuído. Em caso de
sucesso o device number inicial será colocado no parâmetro dev.
*/
	if (ret < 0) {
		printk(KERN_ALERT "sulbMT: Falha na alocação do char device - Failed to allocate char device "
			"number.\n");
		goto out;
	}
	
	pdebug("Alocação dinamica do char device na regiao(major_nr=%d) \n- Dinamically allocated char device region (major_nr=%d).\n",
			MAJOR(dev->dev_nr),MAJOR(dev->dev_nr));

	/* 
	 * Initialize the device cdev structure fields and its file operation
	 * methods.
	 Inicializar o dispositivo cdev estrutura campos e seus métodos de funcionamento arquivo
	 */
	/*
	inicializa uma estrutura de dados cdev. Uma das inicializações óbvias consiste na
atribuição do conjunto de operações referenciado pelo apontador fops.
	*/
    
    cdev_init(&dev->cdev, &sulb_fops);
	dev->cdev.owner = THIS_MODULE;

	/* 
	 * This enables the char device (it can fail!).
	 * From this point on the device is enabled and must be able to deal
	 * with incoming userspace requests.
	 PRecisamos informar que o dispositivo esta apto a receber
	 requisições do jkernel, para isto basta executar a função abaixo
	  */
	  /*
	  Informa o kernel que este poderá começar a encaminhar pedidos com destinado ao
char device indicado pelo parâmetro dev. O parâmetro num indica o device number
e o parâmetro count a quantidade de device numbers consecutivos que se
encontram associados ao dispositivo.
	  
      E preciso ter em atencao que, a partir deste momento, o device driver devera ser
capaz de processar todos os pedidos que possam surgir. Nesse sentido, a funcao
devera ser invocada apenas no final da inicializacao do device driver.
. Embora nao seja comum, a funcao pode falhar. E por isso necessario verificar se
esta devolve erro.
      */
	ret = cdev_add(&dev->cdev, dev->dev_nr, 1);
//se o retornofo menor que 0 e pq n foi alocado corretamente e nao podera receber requisições
	if (ret < 0)
		goto fail;

//vai par ao fim	
	goto out;


fail:
     //infomar que o char device nao foi alocado na regiao
	unregister_chrdev_region(dev->dev_nr, 1);
out:
	return ret;
}

//*********************************

/**
 * Takes care of sulb device initialization.
 Cuida da inicialização do dispositivo
 */
int __init sulb_init_dev(struct sulb_dev *dev)
{
	int ret;

	/* 
	 * Allocate and initialize the device internal data buffer.
	 * This is the buffer between the userspace write requests and the 
	 * actual hardware.
	 
	 Alocar e iniciliazr o dispositivos interno de dados do buffer
	 Este é o buffer da userspace escrever as requisições no hardware
	 	 */
	dev->buf = cfifo_alloc(size);
	//apenas cria um buffer e armazena no dispositivo
	
	//informe se  houver falaha na alocação do buffer do dispositivo
	if (!dev->buf) {
		printk(KERN_ALERT "sulbMT: Falha na alocação do buffer do dispositivo\nFailed to allocate the device buffer.\n");
		ret = -ENOMEM;
		goto out;
	}
		
	/*
	 * Initialize the device buffer lock.
	 * This lock protects the buffer from concurrent accesses.
	 Inicializar o dispositivo tampão bloqueio. Este bloqueio protege o buffer de acessos simultâneos.
	 */
	spin_lock_init(&dev->lock);

	/*
	 * Initialize the device wait queues.
	 * These wait queues are used to put a process to sleep if it's trying
	 * to write to or read from the device and there is no space left or 
	 * nothing to read.
	 
	 Inicializar o dispositivo esperar filas. Estes esperar filas são utilizadas 
     para colocar um processo para dormir, se está a tentar escrever ou ler a
      partir do dispositivo e não existe um espaço à esquerda ou nada para ler.
	 */
	init_waitqueue_head(&dev->wait_qw);
	init_waitqueue_head(&dev->wait_qr);
	
	/*
	 * Request the kernel exclusive access to the I/O Parallel Interface 
	 * ports.
	 *
	 * Each parallel interface has three distinct ports available as 8bit
	 * registers: - A bidirectional data register at base address (0x378h);
	 * A read-only satus register at base address+1; And an output control
	 * port at base address+2.
	 *
	 * We'll just use the data lines so we can just ignore the other ports
	 * usage.
	 
	 Pedido de acesso exclusivo para o kernel do I / O interface paralela portos. 
     Cada interface paralela distinta tem três portas disponíveis como 8bit registos: 
          - Um registo na base de dados bidirecional endereço (0x378h); A read-only 
          satus registo no endereço base 1, e uma saída de controlo portuário no 
          endereço base 2. 

Iremos apenas utilizar as linhas de dados para que possamos simplesmente i
gnorar os outros portos uso.	 
	 
	 */
	if (!request_region(io_port, IO_PORT_NR, "sulbMT")) {
		printk(KERN_ALERT "sulbMT: Falha na requisiçãom de acesso a porta de E/S - Failed to request I/O port " 
			"access.\n");
		ret = -ENODEV;
		goto fail;
	}
	
    /* Clean port line status. - zenrando/limpando a porta */
	outb(0, io_port);
	
	pdebug("Acesso de E/S para a porta paralela requisitado - Parallel port I/O access requested. " 
		"(base: 0x%xh num: %d ports)\n", io_port, IO_PORT_NR);
	//Impimi o numeto da porta requiistado e a quantidade de portaas - no caso eh so uma
	
	/* 
	 * Initialize sulb char device.
	 * From this point on the device is active and must be able to handle 
	 * userspace requests.
	 
	 AQUIIII:
             Iniciliza o char dev, a partir desse ponto que o dispositivo
             deve estar pronto para atender requisições	 
	 */
	ret = sulb_init_chrdev(dev);
	if (ret < 0) {
		printk(KERN_ALERT "sulbMT: Falha na inicilizização do char device \n - Failed to initialize char device.\n");
		goto fail_init_chrdev;
	}
	pdebug("Char device HABILITADO - Char device enabled.\n");	


//IMPORTANTE - ONDE SERA INICILIAZADO O TEMPO DE ENVIO DE BITS PARA A PORTA
	/* Inicilizando o temporizador 
    Initialize and fire sulb timer. */
    //O Cronometro e deixado em estado parado
	sulb_timer_init(dev->timer, sulb_timer_delay(delay), dev);
	//inicia o temporizador do kernel
    sulb_timer_start(dev->timer);
	
	//foi criado com sucesso, basta ir pra o fim do metodo - out
	goto out;

	
fail_init_chrdev:
	release_region(io_port, IO_PORT_NR);
fail:
	cfifo_free(dev->buf);
out:
	return ret;
}

/*
 * This function disables the device and releases all resources it's
 * holding. This should be called prior to module removal.
 
 Esta função desabilita o dispositivo e libera todas as funções do mesmo.
 É aconselhavem que ela seja chamada antes da remoção do modulo
 
 */
void __exit sulb_cleanup(struct sulb_dev *dev)
{
	/* Delete / disable char device. */
	cdev_del(&dev->cdev);
	pdebug("Char device desabilitado - Char device disabled.\n");
	
	/* Unregister / release char device number. */
	unregister_chrdev_region(dev->dev_nr, 1);
	pdebug("Char device liberado da regiao major- Released char device region (major_nr=%d).\n",
			MAJOR(dev->dev_nr));

	/* Desligando o temporizador - Shutdown device timer. */
	sulb_timer_shutdown(dev->timer);

	/* Zerando os bits da regiao da porta - Clears output bits and releases I/O region. */
	outb(0, io_port);
	release_region(io_port, IO_PORT_NR);
	
	/* Tree the device's internal buffer. */
	cfifo_free(dev->buf);
	pdebug("Dispositivo Liberado - Freed device's internal buffer.\n");
}

/**
 * Initilizes sulb module.
 */
int __init sulb_init(void)
{
	int ret;
	
	printk(KERN_INFO "sulbMT: Stupid and Useless Led Board (version %s)\n",
			THIS_MODULE->version);
	printk(KERN_INFO "sulbMT: io_port=0x%x, delay=%lu (%lu ms), size=%d "
		"bytes\n",io_port, delay, delay*SULB_TIMER_HZ, size);

	/* Inicializando o dispositivo - initialize sulb device. */
	ret = sulb_init_dev(&dev);
	
	return ret;
}

/**
 * Exits sulb module.
 */
void __exit sulb_exit(void)
{
	sulb_cleanup(&dev);
	
	printk(KERN_INFO "sulbMT: Modulo Descarregad0 - Module unloaded!\n");
}

/* Defines the module init and exit functions. */
module_init(sulb_init);
module_exit(sulb_exit);

/*
 * Module documentation.
 */
MODULE_AUTHOR("Marco Tulio Rodrigues BRaga");
MODULE_VERSION("1.0");
MODULE_DESCRIPTION("Sistemas Operacionais - Device Driver\nIt's a driver for a Stupid and Useless Led Board.");
MODULE_LICENSE("GPL");


