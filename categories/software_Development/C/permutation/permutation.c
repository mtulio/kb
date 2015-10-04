#include <string.h>

#include "permutation.h"

/* Change string positions str1 to str2  */
void swap_str ( char *str_1, char *str_2 ) {
	char str_tmp;
	str_tmp = *str_1;
	*str_1 = *str_2;
	*str_2 = str_tmp;
}

/* Permute  string  recursively */
void permute ( char *str, int start, int end ) {


	/* break point (recursivity) */
#ifdef _PERM_EN_BREAK
    if (perm_break_point == 1)
        return;
#endif /* _PERM_EN_BREAK */

    if (start == end) {
#ifdef _PERM_K		/* PERM_K */
    	perm_counter++;
		if (perm_counter == perm_k) {
			printf("%s\n", str);
    		perm_found = 1; 				/* break point */
            perm_break_point = perm_found;
		}

#else /* PERM_DIV8 */
    	if (strlen(str) == len_orig) {
        	if ( (atoi(str)%8 )== 0) { 			/* check divisible by 8*/
        		perm_found = 1; 				/* break point */
                perm_break_point = perm_found;
        	}
    	}
#endif /* _PERM_DIV8 */
    }
    else {
		for (int i = start; i <= end; i++) {

			/* break point */
#ifdef _PERM_EN_BREAK
			if (perm_break_point == 1)
				break;
#endif /* _PERM_EN_BREAK */

			swap_str ( (str+start), (str+i) );
			permute (str, start+1, end );
			swap_str ( (str+start), (str+i) );
        }
    }
}
