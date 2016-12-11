/*
 * sulb_fops.h  Stupid and Useless Led Board
 *              Device file operation method headers.
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

#ifndef _SULB_FOPS_H_
#define _SULB_FOPS_H_

#ifdef __KERNEL__

int sulb_open(struct inode *inode, struct file *filp);
int sulb_release(struct inode *inode, struct file *filp);
ssize_t sulb_read(struct file *filp, char __user *buf, size_t count,
		  loff_t *f_pos);
ssize_t sulb_write(struct file *filp, const char __user *buf, size_t count,
		   loff_t *f_pos);

#endif /* __KERNEL__ */
#endif /* _SULB_FOPS_H_ */
