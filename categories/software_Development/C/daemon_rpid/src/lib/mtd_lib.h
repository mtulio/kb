/*
 * mtdLib.h
 *
 *  Created on: 27 de set de 2015
 *      Author: mtulio
 */

#ifndef SRC_LIB_MTD_LIB_H_
#define SRC_LIB_MTD_LIB_H_

/* Lib of strings */
int mtd_lib_strings_splitByToken (char *str_line, char *delimiter, char *str_A, char *str_B);
int mtd_lib_strings_lineIsComment (char *str_line);
int mtd_lib_strings_lineIsEmpty (char *str_line);
void mtd_lib_strings_trimNewLine (char *str);

/* Lib of Files */
int mtd_lib_fileExist (char *filename);

/* Lib of Daemon */
int mtd_lib_daemon_init (int nochdir, int noclose);

#endif /* SRC_LIB_MTD_LIB_H_ */
