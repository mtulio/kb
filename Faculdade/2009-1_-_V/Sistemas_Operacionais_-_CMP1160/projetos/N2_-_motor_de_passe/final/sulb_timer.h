/*
 * sulb_timer.h Stupid and Useless Led Board
 *             	Device timer function headers, timer definitions and helper 
 *             	macros.
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
 
#ifndef _SULB_TIMER_H_
#define _SULB_TIMER_H_

#ifdef __KERNEL__

#include <linux/sched.h>
#include <linux/timer.h>
#include <linux/jiffies.h>

#define SULB_TIMER_HZ	((100*HZ)/1000)		/* frequency base of 100ms */
#define SULB_TIMER_DELAY 10			/* default delay of 1s */

/*
 * Computes the real timer delay in milliseconds using the macro timer 
 * definitions. (minimum delay is SULB_TIMER_HZ value)
 
 Calcula o real timer demora em milissegundos usando a macro temporizador 
 definições. (mínimo de atraso é SULB_TIMER_HZ valor)
 
 */
#define sulb_timer_delay(_delay_)		\
	((_delay_)*SULB_TIMER_HZ) ? ((_delay_)*SULB_TIMER_HZ) : SULB_TIMER_HZ


/*
 * Device timer structure.
 
 Estrutura de tempo do dispositivo
 
 */								
struct sulb_timer {
	struct timer_list timer;        /* kernel timer			*/
        unsigned long delay;      	/* timer delay       		*/
	unsigned int state;		/* defines a timer state        */	
	unsigned long ts;		/* jiffies timestamp		*/
};

/*
 * Device timer states.
 */
enum {
	TIMER_STOPPED,
	TIMER_RUNNING,
	TIMER_SHUTDOWN
};


void sulb_timer_func(unsigned long data);
static void call_sulb_timer_func(unsigned long data){
       sulb_timer_func(data);
}

/**
 * These macros are helpers to work with the sulb_timer structure.
 * These helpers were implemented has macros to exemplify the common 
 * helper macro implementations existant in the kernel.
 
 Estas macros são ajudantes para trabalhar com a estrutura sulb_timer. Estes
  protetores foram implementadas tem macros para exemplificar o comum socorredor
   macro implementações existentes no kernel. 
 
 
 * 	
 * 	  t: A pointer to slub_timer struct.
 *	  delay: Delay time expressed in jiffies (unsigned long).
 *	  data: Pointer to the data you wish to by pass to the timer function.

Inicializa o sulb_timer estrutura e pré temporizador configuração do kernel. 
O cronômetro é deixado em um estado parado.

t: Um ponteiro para slub_timer struct. 
delay: Atraso tempo expresso em jiffies (unsigned long). 
data: Ponteiro para os dados que você deseja passar pelo que o temporizador função.

*/

/*
sulb_timer_init: 
 * 	- Initializes the sulb_timer structure and preforms the kernel timer
 * 	  setup. The timer is left on a stopped state.
Inicializa a estrutura silb_timer e o pre temporizador do kernel.
O  cronometro e deixado em estado parado.
*/

#define sulb_timer_init(_timer_, _delay_, _data_)			\
	do {								\
		(_timer_).delay = (_delay_);				\
		(_timer_).state = (1<<TIMER_STOPPED);			\
		(_timer_).ts = 0;					\
		setup_timer(&(_timer_).timer, (sulb_timer_func),	\
				(unsigned long) (_data_));		\
	} while (0)

/*
sulb_timer_start:
 * 	- Fires the kernel timer.
*/

#define sulb_timer_start(_timer_)					\
	do {								\
		(_timer_).state = (1<<TIMER_RUNNING);			\
		(_timer_).timer.expires = jiffies + (_timer_).delay;	\
		add_timer(&(_timer_).timer);				\
	} while (0)


/*
sulb_timer_shutdown:
 * 	- Shuts down the timer. Shutdown is only finished when no timer's 
 * 	  running.
 
 Desliga o temporizador. Desligamento só está acabado quando nenhuma de funcionamento do temporizador.
 
 */

#define sulb_timer_shutdown(_timer_)			\
	do {						\
		(_timer_).state = (1<<TIMER_SHUTDOWN);	\
		del_timer_sync(&(_timer_).timer);	\
	} while (0)	

/*
sulb_timer_restart:
 * 	- Restarts the timer reschedulling it with the timer defined delay.
 Reinicia o temporizador reschedulling-lo com o temporizador definido atraso.
*/

#define sulb_timer_restart(_timer_)					\
	do {								\
		mod_timer(&(_timer_).timer,				\
			(_timer_).timer.expires + (_timer_).delay);	\
	} while (0)

/*
sulb_timer_is_shutdown:
 * 	- Is 0 if the timer is not schedulled for shutdown.
 É 0 se o temporizador não é schedulled para o desligamento.
 */

#define sulb_timer_is_shutdown(_timer_)		\
	((_timer_).state & (1<<TIMER_SHUTDOWN))

/*
sulb_timer_update_ts:
 * 	- Updates the timer internal timestamp.
 Atualizações do temporizador interno hora.
*/

#define sulb_timer_update_ts(_timer_)		\
	(_timer_).ts = jiffies


/*
 * sulb_timer_get_ts:
 * 	- Copies the timer timestamp into the _ts_ argument.
 Copia o temporizador timestamp no argumento _ts_
 */

#define sulb_timer_get_ts(_timer_, _ts_) \
	(_ts_) = (_timer_).ts

/*
sulb_timer_check_if_run:
 * 	- Evaluates to true if the timer as runned comparing it to the _ts_ value.
 Avalia a verdade se o cronômetro runned como compará-lo ao _ts_ valor.
 */

#define sulb_timer_check_if_run(_timer_, _ts_)	\
	time_after((_timer_).ts, (_ts_))




#endif /* __KERNEL__ */
#endif /* _SULB_TIMER_H_ */
