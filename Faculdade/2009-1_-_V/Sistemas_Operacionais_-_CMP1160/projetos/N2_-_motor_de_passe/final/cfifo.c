/*
 * cfifo.c  	Stupid and Useless Led Board
 *              Circular FIFO buffer implementation.
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

#include <linux/types.h>
#include <linux/slab.h>
#include <linux/errno.h>

#include "cfifo.h"

/**
 * This allocates and initializes a new fifo with a size byte buffer capacity.
 * Returns null if this fails. (This function can sleep!)
 */
struct cfifo *cfifo_alloc(size_t size)
{
	struct cfifo *t;

	/* Allocates memory for a cfifo structure and fills it with zeros. */
	t = kzalloc(sizeof(*t), GFP_KERNEL);

	if (!t)
		goto out;
	
	/*
	 * Lets give an extra byte so we can end the buffer with a null
	 * byte and print it without concerns if we wish to.
	 */
	t->buf = kzalloc(sizeof(*t->buf)*(size+1), GFP_KERNEL); 

	if (!t->buf)
		goto fail;

	t->size = size;
	goto out;

	
fail:
	kfree(t);
	t = NULL;
out:
	return t;
}

/**
 * Libera a buffer da estrutura passada como parametro
 * Apos o termio desse metodo o ponteiro sera invalido(vazio).
 */
void cfifo_free(struct cfifo *p)
{
	kfree(p->buf);
	kfree(p);
}

/**
 * Grava os dados apontado por buf com tamanho em bytes do buffer FIFO. Retorna 
 o número de bytes que foram escritos efectively. Se você esperar concorrente 
 terá de seguro bloquear esta função.
 */
size_t cfifo_write(struct cfifo *p, const char *buf, size_t size)
{
	int count;

	for (count=0; (p->size - p->count) && (size - count); count++, p->count++) {
		p->buf[p->write] = buf[count];
		p->write = (p->write + 1) % p->size;
	}
	
	return count;
}

/**
 * Lê no máximo tamanho bytes a partir do fifo tampão para o buffer apontado 
 por buf. O ponteiro buf deve ter espaço suficiente para receber o readed data.
 Returns o número de bytes efectively read.
 *
 * If you expect concurrency you must safe lock this function.
 */
size_t cfifo_read(struct cfifo *p, char *buf, size_t size)
{
	int count;

	for (count=0; (p->count) && (size - count); count++, p->count--) {
		buf[count] = p->buf[p->read];
		p->read = (p->read + 1) % p->size;
	}

	/* Reset pointers avoiding extreme pointer wrapping. */
	if (!p->count)
		p->read = p->write = 0;
	
	return count;
}

