/*
 * mtdLib_file.c
 *
 *  Created on: 27 de set de 2015
 *      Author: mtuliorbraga
 */

#include <stdlib.h>
#include <stdio.h>

#include <daemon.h>
#include <mtd_lib.h>

/* Check if file exists */
int mtd_lib_fileExist (char *filename)
{
	FILE *fd;
	fd = fopen(filename, "r");
	if (fd) {
		fclose(fd);
		return RET_OK;
	}
	else
		return RET_ERR;
}

