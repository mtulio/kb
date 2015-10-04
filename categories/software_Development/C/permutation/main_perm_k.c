#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "permutation.h"
#include "config.h"

unsigned int perm_break_point = 0;			/* EXTERN Permute break point */
unsigned int perm_found = 0;     			/* EXTERN Permute was found */
#ifdef _PERM_K
	unsigned long long int perm_counter = 0;	/**/
	unsigned int perm_k = 0;					/**/
#endif /*_PERM_K*/

///* Swap a value from string  */
//void swap (char *str_1, char *str_2)
//{
//	char str_tmp;
//	str_tmp = *str_1;
//	*str_1 = *str_2;
//	*str_2 = str_tmp;
//}
//
///* permute a string */
//void permute (/*struct list_str *list*/long long int k, char *str, int start, int end)			// rec1st: str = ABC, start=1, end=3
//{
//	int i = 0;
//	//int cond = 0;
//
//	/* Recursivity stop condition */
//	if (perm_break == 1)
//		return;
//
//	if (start == end) {
//		counter++;
//		if (counter == k) {
////			printf("[%d][%s]\n", counter, str);
//			printf("%s\n", str);
//			perm_break=1;	/* Recursivity stop condition */
//		}
//
//	}
//	else {
//		for (i = start; i <= end; i++) {
//
//			/* Recursivity stop condition */
//			if (perm_break==1)
//				break;
//
//			swap ((str+start), (str+i));		// rec1st : str+1 = B , str+i = A; str = BAC
//			permute (/*list*/k, str, start+1, end);		// rec1st : str=BAC, start+1 = 2, end = 3
//			swap ( (str+start), (str+i) );		// re1st :
//		}
//	}
//}

/* Main program Permutation */
int main (void) 
{
	int len;

	len = 0;

	char *buffer = NULL;
	unsigned int nlen;

	// stdin
	/* [long] INPUT examples:
	 * 1: supercalifragilisticexpialidocious
	 * 1: 235098745835437453987272234987574748
	 * 2: DOG
	 * 2: 4
	 * 3: UGEUIP
	 * 3: 500
	 * 4: Lorem Ipsum (916800) = LeIsmrup mo
	 * */

	//scanf("%[^\n]", &str_in);
	getline(&buffer, &nlen, stdin);
	scanf("%d", &perm_k);

	// Removing '\n' from line read by getline
	nlen = strlen(buffer);
	if (buffer[nlen - 1] == '\n')
	    buffer[nlen - 1] = '\0';

	// Calc len of string
	len = strlen(buffer);

	// check permutation
	//printf("str_in=[%s] len=[%d]\n", buffer, len);
	permute ( buffer, 0, len-1 );

	// Free pointers
	if (buffer)
		free(buffer);

	return (0);
}
