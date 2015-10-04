#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/* PERMUTATION DIVISIBLE BY 8
 *
 * INSTRUCTIONS:
 * 	Calculate if integer N has any number permutable that is divisible by 8. The
 * 	test will print "YES" if the integer N has an permutable divisible by 8, and
 * 	its hasn't: "NO".
 *
 * INPUT 1: first line with T tests to do.
 * INPUT 2th> : next line have T lines, each one with N integer to
 * 				test permutation and divisibility by 8
 *
 * INPUT #1:
 * 2
 * 16
 * 7
 * OUPUT #1:
 * YES
 * NO
 *
 */

/*************/
/* Start here*/

#include "permutation.h"
#include "config.h"

/* Globals */
unsigned int perm_break_point = 0;	/* EXTERN Permute break point */
unsigned int perm_found = 0;     	/* EXTERN Permute was found */
double len_orig = 0;            	/* EXTERN Original lenght of string/number */
#ifdef _PERM_K
	unsigned int perm_counter = 0;	/**/
	unsigned int perm_k = 0;		/**/
#endif /*_PERM_K*/

/*
 * check permutation of array - code here:
 */
void ispermuation_divisibleby8 ( int arr_size, char** arr ) {

	/* Constraint: (arr_size 1 <= arr_size <= 45)*/
	if ((arr_size < 1) || (arr_size > 45))
		return;

    for ( int pos=0; pos<arr_size; pos++ ) {
    	perm_found = 0;
        len_orig = strlen(arr[pos]);

        /* Constraint: 0 <= N <= 110 */
        if ( len_orig > pow(10,100) ) {
        	printf("NO\n");
            continue;
        }

        /* check permutation and div8*/
        permute (arr[pos], 0, len_orig);

        if (perm_found == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
}


/* Ends here */
/*************/

/* locked to edit */
int main() {

    int _arr_size = 0;
    int _arr_i;
    scanf("%d\n", &_arr_size);
    char* _arr[_arr_size];
    for(_arr_i = 0; _arr_i < _arr_size; _arr_i++) {
        char* _arr_item;
        _arr_item = (char *)malloc(10240 * sizeof(char));
        scanf("\n%[^\n]",_arr_item);
        _arr[_arr_i] = _arr_item;
    }

    ispermuation_divisibleby8(_arr_size, _arr);

    return 0;
}

