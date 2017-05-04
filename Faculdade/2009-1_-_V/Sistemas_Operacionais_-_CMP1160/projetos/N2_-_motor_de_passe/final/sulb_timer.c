/*
 * sulb_timer.c  Stupid and Useless Led Board
 *              Device timer related functions.
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

#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/timer.h>
#include <linux/kernel.h>
#include <asm/io.h>

#include "sulb_timer.h"
#include "sulb_main.h"
#include "cfifo.h"

/*
 * Device configuration data.
 
 Dispositivo configuração de dados.
 */
extern unsigned int io_port;	/* device port address - endereço do disposotovo	*/

/*
 * This function is executed when the device timer expires.
 Esta função é executada quando o dispositivo temporizador expire.
 */
void sulb_timer_func(unsigned long data)
{
    // eh enviado como parametro como unsigned long, mas na verdade
    // ele sao a estrutrura sulb_dev que eh chamada pelo metodo sulb_timer_init
	int ret;
	char byte;
	struct sulb_dev *dev = (struct sulb_dev *) data;

	/*
	 * We have to protect the buffer against concurrent accesses.
	 * This may happen in a SMP system if a cpu is executing this function
	 * and other cpu is executing a process context that accesses the same
	 * data.
	 
	 Protejendo o buffer contra acesso instantaneo.
	 Isto pode acontecer em um sistema SMP se uma CPU é executar esta função e 
     outros cpu está executando um processo contexto que acessa os mesmos dados.
	 	 
	 */
	spin_lock(&dev->lock);
	ret = cfifo_read(dev->buf, &byte, 1);
	spin_unlock(&dev->lock);

	/*
	 * Write one byte into the device data port.
	 * Each time the device buffer is found empty we can wake up all 
	 * sleeping processes that were wainting for available free space.
	 
	 Escreve um byte na porta do dispositivo. Cada vez que o dispositivo encontra-se 
	 vazio podemos acordar um processo que estavam esperando o espaço livre
	 */
	 
	 //copy_from_user(buff, numero, 1);
    printk(KERN_INFO "numero %d" , byte);
	 
	 
	if (ret) {
		//escrevendo no dispositivo
		outb(byte, io_port);
		
		/* 
		 * This is a write memory barrier. This barrier instructs the
		 * cpu to finish executing all write instructions that were 
		 * issued until now. This prevents output writes to be preformed 
		 * out of order or out of sync due to compile, cache or pipeline 
		 * optimizations.
		 
		 Esta é uma memória escrita barreira. Esta barreira instrui a CPU para 
         terminar execução escrever todas as instruções que foram emitidos até 
         agora. Isto impede a saída escreve a ser preformado fora de ordem ou fora 
         de sincronia devido a compilar, cache ou gasoduto otimizações.
		 
		 */
		 
		 /*
		 A função wmb() provê uma barreira para escritas. Esta funciona
      da mesma maneira que a função rmb(), assegurando que
      escritas não sejam reordenadas através da barreira.

      A função rmb() provê uma barreira para leituras à memória. Esta
      assegura que nenhuma leitura seja reordenada através da
      chamada rmb(). Isto é, nenhuma leitura antes da chamada será
      reordenada para depois da chamada e vice-versa
		 
		 */
		 
		wmb();

		/* Updates current hardware status.  - Atualiza o estado do hardware atual*/
		dev->hw_status = byte;
	
		/*
		 * Updates the internal timer timestamp. This timestamp
		 * will allow a proccess to know if the timer has been runned.
		 
		 Aatualiza o temporizador interno. Este temporizador permite o processo saber
   se o temporizador foi iiciado
		 */
		sulb_timer_update_ts(dev->timer);

		/* 
		 * The status has changed so let's wake up the processes that 
		 * are waiting for this.
		 
		 Como a comunicação com o dispositivo  jah foi efetuada a porta esta livre
	 portanto podera mudar o estado para liberar os processos que estao esperando
		 
		 */
		wake_up_interruptible(&dev->wait_qr);

		pdebug("Temporizdor expirado- Timer expired! Wrote byte: '%c', '0x%x'.\n", byte, byte);	
	} else
		wake_up_interruptible(&dev->wait_qw);

	/* 
	 * Only reschedule the timer if it's not marked for shutdown.
	 somente reagendara o escalonador quem ainda nao foram marcados par ao desligamento
	 */	
	if (!sulb_timer_is_shutdown(dev->timer))
		sulb_timer_restart(dev->timer);
	else
		pdebug(" TEmporizador esta sendo desligado - Timer is shutting down!\n");	
}
