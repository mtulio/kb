#include <stdio.h>
#include <stdlib.h>

/* Main - Test functions */
int main(void)
{
	char array[] = "10,20,30,a";
	char delimiter = ',';
	int resp = 0;

	// testing str_get_rowNumber
	printf("# Number of colluns: %d\n", mtdLib_str_getColNumbers(array, delimiter));

	// testing str_get_rowNumber
	mtdLib_str_getColByDelPos_int(array, delimiter, 1, &resp);
	printf("# Resp: %d\n", resp);

	exit (0);
}
