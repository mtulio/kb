#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list_linked.h"
#include "permutation.h"

#define MAX_BUF_SIZE	200

///* Check each element of list is divisible by 8*/
void check_divisible_by8 (struct list_node *list_root)
{
	int k = 0;
	struct list_node *l_tmp;
	l_tmp = list_root->next;

	for (; l_tmp != 0; ++k)
	{
		if (l_tmp){

			// YES if value is divisible by 8
			//printf(" check [%d]: %s \n", l_tmp->value, ((l_tmp->value %8 == 0) ? "true":"false"));
			printf(" k=[%d] N[%d]/8 \t? %s \n", k, l_tmp->value, ((l_tmp->value %8 == 0) ? "YES":"NO"));

		}
		l_tmp = l_tmp->next;
	}
}

/* Get permutation divisible by 8 */
int main(void)
{
	struct list_node *list_root;
	char str_in[MAX_BUF_SIZE];
	char str_tmp[2];

	// init
	list_root = (struct list_node *)malloc(sizeof(struct list_node) );
	memset(str_in, 0 , strlen(str_in));

	// sstdin - Eg.: 12893
	scanf("%[^\n]", &str_in);

	// set permutation from stdin string
	for (int pos_ctrl=0; pos_ctrl<strlen(str_in); pos_ctrl++)
		setPermutation_insertList_int(str_in, pos_ctrl, list_root);

	// Show list elements
	//list_show(list_root);

	check_divisible_by8 (list_root);

	//printf("\n\n Done. ;) \n");
	exit (0);
}
