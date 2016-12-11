/*
 * sulb_main.h  Stupid and Useless Led Board
 *		Device headers.
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

#ifndef _SULB_MAIN_H_
#define _SULB_MAIN_H_

#ifdef __KERNEL__

#include <linux/types.h>
#include <linux/cdev.h>
#include <linux/spinlock.h>
#include <linux/wait.h>
#include <linux/sched.h>
#include <linux/timer.h>

#include "cfifo.h"
#include "sulb_timer.h"

/* The device major number is dinamically allocated. 
É o major number do dispositivo dinamicamente alocado
*/
#define SULB_MINOR 0

/* The device default buffer size. 
BUffer do dispositivo padrao
*/
#define BUF_SIZE 32

/* Parallel I/O ports. 
*/
#define IO_BASE_PORT 0x378
#define IO_PORT_NR 1

/* Debug printing macro. */
#ifdef SULB_DEBUG
#	define pdebug(fmt, args...)\
		printk(KERN_DEBUG "sulb: " fmt, ## args)
#else
#	define pdebug(fmt, args...)
#endif


/* Device structure. */
struct sulb_dev {
	dev_t dev_nr;			
    /* device number 
    Dentro do kernel, o tipo dev_t é usado para guardar os números major e
minor dum dispositivo.		*/

	struct cdev cdev;		/* char device structure 
    struct cdev é a estrutura interna do kernel que representa dispositivos do
tipo char.
Este campo contém um apontador para essa estrutura quando o inode é
relativo ao ficheiro dum dispositivo tipo char.	*/

	struct cfifo *buf;		
    /* data buffer - DEfinição da estrutura cfifo para tratamento do buffer			*/
    

	char hw_status;			/* hardware status		*/
	
	//Wait queue sao listas de processos bloqueados
	wait_queue_head_t wait_qw;	
    /* wait queue for writers  - Fila de espera para gravação- 
    Estabelece o inicio de uma wait queue que estao definidas no cabeçalho wait	*/
	wait_queue_head_t wait_qr;	/* wait queue for readers - fila de espera leitor	*/
	
	struct sulb_timer timer;	/* device timer	 - temporizador do dispositivo
    implementando em sulb_timer.h		*/

	spinlock_t lock;		/* device resource lock 
    bloqueia recurso do dispositivo	*/
};

/* Represents an open device context. 
Representao um dispositivo aberto*/
struct sulb_open {
	struct sulb_dev *dev;		/* device pointer		*/

	unsigned long ts;		/* timestamp used in read()	*/
};

int sulb_init_chrdev(struct sulb_dev *dev); //OK ESTUDADO
int sulb_init_dev(struct sulb_dev *dev); 
void sulb_cleanup(struct sulb_dev *dev);
int __init sulb_init(void);
void __exit sulb_exit(void);

#endif /* __KERNEL__ */
#endif /* _SULB_MAIN_H_ */
