#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list_linked.h"
#include "permutation.h"

// See Problem: https://www.hackerrank.com/contests/upe-pcs15-hard/challenges/ordered-permutations
// TODO: Input might to has spaces

/* Get permutation divisible by 8 */
int main(void)
{
	struct list_node_str *list_root;
	char str_in[MAX_BUF_SIZE];
	char str_tmp[2];
	int k = 0;

	// init
	list_root = (struct list_node_str *)malloc(sizeof(struct list_node_str) );
	memset(str_in, 0 , strlen(str_in));

	// sstdin - Eg.: DOG
	scanf("%[^\n]", &str_in);

	// sstdin - Eg.: 2
	scanf("%d", &k);

	// set permutation from stdin string
	for (int pos_ctrl=0; pos_ctrl<strlen(str_in); pos_ctrl++)
		setPermutation_insertList_str(str_in, pos_ctrl, list_root);

	// Show list elements
	//list_show_str(list_root);
	list_show_str_k(list_root, k);

	//check_permutation_k (list_root, k);

	if (list_root)
		list_delete_str(list_root);
	//printf("\n\n Done. ;) \n");
	exit (0);
}
