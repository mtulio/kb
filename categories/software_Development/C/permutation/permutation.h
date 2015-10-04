#include "config.h"

#ifndef _PERMUTATION_H_
#define _PERMUTATION_H_

/* Globals */
extern unsigned int perm_break_point;	/* EXTERN Permute break point */
extern unsigned int perm_found;     		/* Permute was found */
extern double len_orig;            		/* Original lenght of string/number */
#ifdef _PERM_K
	extern unsigned long long int perm_counter;
	extern unsigned int perm_k;
#endif /* _PERM_K */

/* Change string positions str1 to str2  */
void swap_str ( char *str_1, char *str_2 );

/* Permute  string  recursively */
void permute ( char *str, int start, int end );

#endif /*_PERMUTATION_H_*/
