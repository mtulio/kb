/*
 * String manipulation functions
 * Created by: Marco Túlio
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ctype.h>  /*isspace()*/

#include <mtd_defs.h>
#include <mtd_lib.h>

/*
* Split a string by token
* @param char str_line is a original string to be splited
* @param delimiter char with a delimiter to split a string
* @param str_A char is a string caught left from delimiter
* @param str_B char is a string caught right from delimiter
* @see
* @return status code
*/
int mtd_lib_strings_splitByToken (char *str_line, char *delimiter, char *str_A, char *str_B)
{

	char *str1, *str2, *token, *subtoken;
	char *saveptr1, *saveptr2;
	int j;

	for (j = 1, str1 = str_line; ; j++, str1 = NULL) {
          token = strtok_r(str1, delimiter, &saveptr1);
          if (token == NULL)
              break;

          if (j == 1)
        	  strncpy(str_A, token, strlen(token));
          else if (j==2)
        	  strncpy(str_B, token, strlen(token));
          else
        	  break;

      }

	if ((strlen(str_A) && strlen(str_B)) > 0)
		return RET_OK;
	else
		return RET_ERR;
}

/*
* Check if line is an comment
* @param str_line is an line to be checked
* @see
* @return OK if is an commented line
*/
int mtd_lib_strings_lineIsComment(char *str_line)
{
	if (strlen(str_line) > 1) {
		/* Check comment */
		if (str_line[0] == '#')
			return RET_OK;
		else if (str_line[0] == '/')
			return RET_OK;
		else if (str_line[0] == ';')
			return RET_OK;
	}

	return RET_ERR;
}

/*
* Check if line is an empty line
* @param str_line is an line to be checked
* @see
* @return OK if is an commented line
*/
int mtd_lib_strings_lineIsEmpty(char *str_line)
{
	if (strlen(str_line) > 1)
		return RET_ERR;

	return RET_OK;
}


/*
* Trim a string (removing new line delimited).
* @param char message is a string to trim
* @see mtd_server_cmd_run_SETPASS()
* @return none
*/
void mtd_lib_strings_trimNewLine (char *str)
{
	  char msgBuff[strlen(str)];
	  memset(msgBuff, '\0', strlen(msgBuff));
	  for (int pos=0; pos<strlen(str); pos++) {
	    /*printf("F[%s] char[%p]\n", __FUNCTION__, str[pos]);*/

	 	/* Check on alphanumeric chars plus '.' on ASCII table */
	 	if ( !(str[pos]==0xA) ) {
	 		msgBuff[pos]=str[pos];
	 	}
	 	else {
	 		msgBuff[pos]='\0';
	 		break;
	 	}
	  }

	  strncpy(str, msgBuff, strlen(str));
}
