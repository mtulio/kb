/*
 * cfifo.h  	Stupid and Useless Led Board
 *              Circular FIFO buffer implementation headers.
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


#ifndef _CFIFO_H_
#define _CFIFO_H_

#ifdef __KERNEL__

#include <linux/types.h>

/*
 * The Circular FIFO structure.
 */
struct cfifo {
	char *buf;		/* Conteudo do buffer */
	
	size_t size;		/* tamanho do buffer */
	unsigned int count;	/* numeros de bytes do buffer */
	
	unsigned int write;	/* buffer para escrever no ponteiro */
	unsigned int read;	/* buffer de leitura do ponteiro */
};

/*
 * Retorna 0 se o buffer esta cheio. Caso o contrario imprimie o espaço
 */
#define cfifo_is_full(cfifo_ptr)			\
	((cfifo_ptr)->size - (cfifo_ptr)->count)

		
struct cfifo *cfifo_alloc(size_t size);
void cfifo_free(struct cfifo *p);
size_t cfifo_write(struct cfifo *p, const char *buf, size_t size);
size_t cfifo_read(struct cfifo *p, char *buf, size_t size);

#endif /* __KERNEL__ */
#endif /* _CFIFO_H_ */
