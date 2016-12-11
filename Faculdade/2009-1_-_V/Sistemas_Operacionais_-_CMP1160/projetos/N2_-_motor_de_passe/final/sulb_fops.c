/*
 * sulb_fops.c  Stupid and Useless Led Board
 *		Device file operation methods.
 *
 * Author:      Artur DAssumpcao <contact@adassumpcao.net>
 *
 * Copyright:   Copyright (C) 2006 Artur DAssumpcao
 *
 *              This file is part of SULB.
 *
 *              SULB is free software; you can redistribute it and/or modify
 *              it under the terms of the GNU General Public License as
 *              published by the Free Software Foundation; either version 2 of
 *              the License, or (at your option) any later version.
 *
 *              SULB is distributed in the hope that it will be useful,
 *              but WITHOUT ANY WARRANTY; without even the implied warranty of
 *              MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *              GNU General Public License for more details.
 *
 *              You should have received a copy of the GNU General Public
 *              License along with SULB; if not, write to the Free Software
 *              Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 *              02110-1301  USA
 */

#include <linux/module.h>
#include <linux/errno.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/types.h>
#include <linux/interrupt.h>
#include <asm/atomic.h>
#include <asm/uaccess.h>

#include "sulb_fops.h"
#include "sulb_main.h"
#include "cfifo.h"

/* 
 * A reference counter for the open file method.
 * The device should only serve one client at a time (policy).
 * 
 * The define OPEN_LIMIT will add this limitation.
 */
#ifdef OPEN_LIMIT
static atomic_t ref_c = ATOMIC_INIT(1);
#endif

/*
 * Device configuration data.
 */
extern unsigned int size;	/* device buffer size */

/*
 * This is the sulb supported file operation methods.
 */
struct file_operations sulb_fops = {
	        .owner = THIS_MODULE,
		.open = sulb_open,
		.release = sulb_release,
		.write = sulb_write,
		.read = sulb_read,
};

/**
 * Implementa o dispositivo método aberto.
 */
int sulb_open(struct inode *inode, struct file *filp)
{
	struct sulb_open *open;
	
#ifdef OPEN_LIMIT
	/*
	 * Permite acesso somente ao processo dentro de um tempo pra o dispositivo
	 */
	if (!atomic_dec_and_test(&ref_c)) {
		atomic_inc(&ref_c);
		//informa se o dispositivo esta ocupado
        pdebug("Device is busy. (pid=%d)\n", current->pid);
		return -EBUSY;
	}
#endif
      //informa que o dispositivo foi aberto e seu pid
	printk(KERN_INFO "Device as been opened by pid=%d.\n", current->pid);

	/*
	 *Aloca uma nova estrutura aberta dispositivo contexto. Esta estrutura é 
* Usado porque existem alguns parâmetros que devem ser definidos em um 
* Open () base. Por exemplo, controlar a ler () para timestamp 
* Cada processo que está a ler a partir do dispositivo. 
     
     Allocates a new open device structure context. This structure is 
	 * used because there are a few parameters that must be set on an
	 * open() basis. For instance, control the read() timestamp for 
	 * each process that is reading from the device.
	 */
	open = kzalloc(sizeof(*open), GFP_KERNEL);
	
	if (!open) {
		printk(KERN_ALERT "sulb: Unable to allocate open device "
			"context.\n");
		return -ENOMEM;		
	}
		
	/*
	 * Saves the open device reference pointer into the filp private data 
	 * pointer. This procedure simplifies later accesses to the device 
	 * structure when the userspace invokes other file methods, requiring 
	 * only to dereference filp->private_data pointer.
	 *
	 * The container_of macro enables you to easly find the container
	 * structure for a given field. This is the best approach to find the 
	 * reference for the sulb device structure only trough the cdev field.
	 */
	open->dev = container_of(inode->i_cdev, struct sulb_dev, cdev);
	filp->private_data = open;
	
	return 0;
}

/**
 * IMplementa o metodo de liberação do dispositivo
 */
int sulb_release(struct inode *inode, struct file *filp)
{
	/*O metodo kfree libera a estrutura. */
	kfree(filp->private_data);
		
#ifdef OPEN_LIMIT 
	/*
	 * Increments the device reference counter enabling other
	 * process to hold the device.
	 */
	atomic_inc(&ref_c);
#endif
	
	printk(KERN_INFO "Device as been closed by pid=%d.\n", current->pid);

	return 0;
}

/**
 * Implements the device write method.
 
   IMplementa o metodo de escrever no dispositivo
   
 * 
 * The write method writes to the device buffer. So if there is more data to 
 * write than the space available on the device buffer the process may have 
 * to try again later for the missing data.
 
 Este metodo escreve o buffer no dispositivo
 Se há mais dados para escrever do que ele suporta 
 o processo pode ter que tentar novamente mais tarde
 
 */
ssize_t sulb_write(struct file *filp, const char __user *buf, size_t count,
		loff_t *f_pos)
{
	int ret;
	size_t real_count;
	
	/* 
	 * Obtains the device structure referece pointer as explained on the 
	 * open method. 
	 
	 Obtendo(abrindo) a estrutura do dispositivo enviado como parametro
	 
	 Antes disso o abre o o alocaem um novo objeto sul_dev(definido em main,h)
	 
	 */
	struct sulb_open *open = filp->private_data;
	struct sulb_dev *dev = open->dev;	

	/* 
	 * Local temporary buffer to safely preform userspace copy.
	 * It only makes sense to copy at most the device buffer size lenght.

	 Cria um buffer temporario
	 
	 */
	char tmp_buf[size];

	
	/*
	 * Read at most the device buffer size lenght which is the best we can
	 * handle. The userspace will have to re-issue the rest later.
	 * 
	 * We must do this now because we can't sleep inside the mutual 
	 * exclusion section that needs to shut down soft irqs.
	 *
	 * We could also optimize this code doing it only if strictly 
	 * necessary. For instance, if the buffer was full and O_NONBLOCK
	 * flag was present we could return imediatly without preforming 
	 * the costly copy_from_user(). We've choose not to do it for the sake
	 * of simplicity (learning purposes).
	 
	 Leia mais no tamanho do dispositivo tampão comprimento que é o melhor que 
     podemos lidar. O userspace terá de voltar a emitir o resto mais tarde. 
  * 
  Temos que fazer isso agora, porque não podemos dormir no interior da mútua 
  exclusão seção que precisa fechar o soft IRQs. 
* 
  Poderíamos também otimizar esse código fazê-lo apenas quando estritamente 
  necessário. Por exemplo, se a memória estava cheia e O_NONBLOCK pavilhão esteve 
  presente pudéssemos voltar imediatly pré sem a dispendiosa copy_from_user (). 
  Temos optar por não fazê-lo por razões de simplicidade (fins educativos). 
	 
	 
	 */
	if (count > size)
		real_count = size;
	else
		real_count = count;
	
	/* Copies the data from the user space to the kernel space. 
       
       copia os dados dousuario para o kernel
    
    */
	ret = copy_from_user(tmp_buf, buf, real_count);

	if (ret)
		return -EFAULT;

	/* 
	 * Write userspace data into the device buffer. 
	 * 
	 * This buffer may also be accessed through the routine responsible to 
	 * send data from the device buffer into the hardware. This routine is 
	 * scheduled through a Kernel Timer task. Because Kernel Timer tasks 
	 * are executed in software interrupt context the only safe way to 
	 * prevent a dead lock while concurrently accessing the buffer is to 
	 * disable soft irqs on the local cpu.
	 
	 Este tampão pode também ser acedida através do responsável rotina para 
     enviar os dados do buffer para o dispositivo de hardware. Esta rotina 
     isscheduled através de um Kernel Temporizad tarefa. Porque Kernel Temporizad 
     tarefas são executadas no contexto do software interromper a única forma segura 
     de evitar um bloqueio morto enquanto simultaneamente acessando o tampão é para 
     desativar soft IRQs no local cpu. 
 
	 
	 */
	
	/* 
	 * If the buffer is full there's no use to go any further and lets 
	 * just put the process to sleep or exit if O_NONBLOCK flag is present.
	 
	 Se a memória está cheia não há necessidade de utilizar a ir mais longe e 
     deixa basta colocar o processo de dormir ou sair se O_NONBLOCK bandeira está presente.
	 
	 */
	spin_lock_bh(&dev->lock);
	while (! (ret = cfifo_write(dev->buf, tmp_buf, real_count))) {
		/* no data was written */
		spin_unlock_bh(&dev->lock);
		
		//caso o dispositivo esteja ocupado vai informar que o buffer esta cheio
		if (filp->f_flags & O_NONBLOCK) {
			pdebug("The buffer is full. Try again. (O_NONBLOCK)\n");
			return -EAGAIN;
		}
//e o fará esperar
		pdebug("The buffer is full. Sleeping... (pid=%d)\n", 
			current->pid);
		
		/* 
		 * Send the process to sleep until the buffer has free space.
		 
		 
		 */
		 
		 //o mertodo cfifo fica verificando se esta ocupado
		 
		if (wait_event_interruptible(dev->wait_qw,
						cfifo_is_full(dev->buf)))
			return -ERESTARTSYS;
		
		
		//o processo acordou
		pdebug("Process (pid=%d) was wakened!\n", current->pid);

		/* We must reacquire the lock before terminating the loop. */
		spin_lock_bh(&dev->lock);
	}
	spin_unlock_bh(&dev->lock);
	
	//informa quantos bytes fora gravados no dispositivo
	pdebug("Wrote %d bytes into the device buffer...\n", ret);

	/*
	 * This device doesn't need to update the f_pos value since we don't 
	 * use it as a reference.
	 
	 Este dispositivo não é necessário atualizar o valor f_pos pois não utilizá-lo como uma referência.
	 
	 */
	
	return ret;
}

/**
 * IMplementa o metodo de ler o dispositivo
 *
 * The read method returns the device hardware status. This method allways
 * return 1 byte, since it's a fixed status word size. It also checks if 
 * the processes has already read this status under the current open context.
 * If it did the process is put to sleep until the status has changed.
 
 O método Read retornará o dispositivo de hardware estado. Este método allways 
 return 1 byte, já que é um estado fixo palavra tamanho. Ele também verifica se 
 os processos já leu esse estatuto ao abrigo do actual contexto aberto. Se fez o
  processo é colocado para dormir até que a situação mudou.
 
 */
ssize_t sulb_read(struct file *filp, char __user *buf, size_t count, 
		loff_t *f_pos)
{
	int ret = 0;
	char hw_status;
	
	/*
	 * Obtains the device structure referece pointer as explained on the
	 * open method.
	 
	 Primiera verifica s o dispositivo esta aberto
	 Logo apos cria um objeto main para ele ocm endereço dele(filp) passado como paramentro
     
     */
	struct sulb_open *open = filp->private_data;
	struct sulb_dev *dev = open->dev;


	/*
	 * We're shure that there were no status changes if the timer hasn't 
	 * run. In this case we must put the process to sleep until there is.
	 * The process should be wakened when the status changes.
	 
	 Faz com que o processo durma enquanto o dispositivo nao e liberado
     
     */
	while (! sulb_timer_check_if_run(dev->timer, open->ts)) {
		if (filp->f_flags & O_NONBLOCK) {
			pdebug("The device status hasn't changed. Try again. (O_NONBLOCK)\n");
			return -EAGAIN;
		}

		pdebug("The device status has not changed. Sleeping... "
			"(pid=%d)\n", current->pid);
		
		/* 
		 * Send the process to sleep until the device status has changed.
		 
		   Faz o processo esperar qte que o dispositivo mude de estado
		 */
		if (wait_event_interruptible(dev->wait_qr,
			sulb_timer_check_if_run(dev->timer, open->ts)))
			return -ERESTARTSYS;
		
		pdebug("Process (pid=%d) was wakened!\n", current->pid);
	}

	/* 
	 * If the process was awaked is because there was a status change. 
	 * We must save that status change, update the context timestamp and
	 * copy the status to the userspace.
	 
	 Se o processo foi awaked é porque houve uma mudança de status,. Temos de 
     salvar esse status mudar, atualizar o contexto temporal e cópia do estatuto 
     para o userspace.
	 
	 */
	hw_status = dev->hw_status;
	sulb_timer_get_ts(dev->timer, open->ts);

	ret = copy_to_user(buf, &hw_status, sizeof(hw_status));
	if(ret)
		return -EFAULT;

	return sizeof(hw_status);
}


