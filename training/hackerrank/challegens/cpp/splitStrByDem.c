/* 
 * String manipulation functions
 * Created by: Marco Túlio
 * */

#include <stdio.h>
#include <stdlib.h>

/* Function to get a delimiter from an string */
int str_get_rowNumber(char *array, char delimiter) 
{
	int pos, count_row;
	pos = count_row = 0;
	for (pos=0; array[pos]!='\0'; pos++)
		if (array[pos] == delimiter)
			count_row++;

	// check line is not finishing with delimiter. Eg. delimiter=',': [A,B,]
	if (array[pos-1]!=delimiter)
		count_row++;	

	return count_row;
}

int main(void)
{
	char array[] = "10,20,30,a";

	printf("%d", str_get_rowNumber(array, ','));


	exit (0);
}
