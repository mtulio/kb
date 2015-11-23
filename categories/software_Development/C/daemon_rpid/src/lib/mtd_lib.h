/*
 * mtdLib.h
 *
 *  Created on: 27 de set de 2015
 *      Author: mtulio
 */

#ifndef SRC_LIB_MTD_LIB_H_
#define SRC_LIB_MTD_LIB_H_

///* API of strings */
//int mtdLib_str_getColNumbers(char *array, char delimiter);
//void mtdLib_str_getColByDelPos_int(char *array_in, char delimiter, int posDel, int *resp);
//void mtdLib_str_getColByDelPos_str(char *array_in, char delimiter, int posDel, char *resp);
//int mtdLib_str_getStrlenByDelPos(char *array_in, char delimiter, int posDel);
//int mtdLib_strings_splitByDelimiter (char *str_buff, char *delimiter, char *str_A, char *str_B);
//int mtdLib_strings_splitByToken (char *str_line, char *delimiter, char *str_A, char *str_B);
//int mtdLib_strings_lineIsComment(char *str_line);
//int mtdLib_strings_lineIsEmpty(char *str_line);
//static int mtd_strings_parsedSetArgs(char *args, char **argv);
//void mtd_strings_parsedArgs(char *args, int *argc, char *av[]);
//void mtd_strings_parsedFree(char **argv);
//void mtd_lib_strings_trimNewLine (char *str);
//void mtd_lib_strings_showIp(int ip, char *str);

/* API of files */
int mtd_lib_fileExist (char *filename);

/* Daemon */
int mtd_lib_daemon_init (int nochdir, int noclose);

#endif /* SRC_LIB_MTD_LIB_H_ */
