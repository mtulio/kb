/* 
 * String manipulation functions
 * Created by: Marco Túlio
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to get number of Columns by delimiter from an string */
int mtdLib_str_getColNumbers(char *array, char delimiter)
{
	int pos, count;
	pos = count = 0;
	for (pos=0; array[pos]!='\0'; pos++)
		if (array[pos] == delimiter)
			count++;

	// check line is not finishing with delimiter. Eg. delimiter=',': [A,B,]
	if (array[pos-1]!=delimiter)
		count++;

	return count;
}

/* Get integer value from column by position of delimiter - number of
 * column could be get by function mtdLib_str_getColNumbers() */
void mtdLib_str_getColByDelPos_int(char *array_in, char delimiter, int posDel, int *resp)
{
	int count=1; // considering that exist at least delimiter

	char *buff;
	buff = malloc(sizeof(char *)*strlen(array_in));
	memset(buff,strlen(buff),'\0');

	for (int posA=0, posB=0; posA<strlen(array_in); posA++) {
		if (array_in[posA]==delimiter)
			count++;
		else
			if (count==posDel) { // save data of Column
				buff[posB]=array_in[posA];
				posB++;
			}
	}
	*resp=atoi(buff);
	//printf("%s(resp[%d]) buff(%s)\n", __FUNCTION__, resp, buff);
	if (buff) free(buff);

	return;
}




/***********************************************************/
/* INCOMPLETE
 * array_out Array with new string without delimiter
 * return Status of operation
 */
unsigned int mtdLib_str_splitByDelimiter(char *array_in, char *array_out, char delimiter)
{
	if (strlen(array_in) != strlen(array_out))
		return 1; // Error, array is in the different size

	int pos = 0;

}
