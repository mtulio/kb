#include <stdio.h>
#include <stdlib.h>

#include "list_linked.h"

/* Study case o lists (insert, delete_all, show)
 */

/* inser value on new node */
void list_insert_int(struct list_node *node, int value)
{
	struct list_node *new;

	if (node->next) {
		list_insert_int(node->next, value);
	}
	else {
		new = (struct list_node *)malloc(sizeof(struct list_node));
		node->next = new;
		new->value = value;
		new->next = 0;
	}
}

/* Show all nodes from root */
void list_show(struct list_node *root)
{
	struct list_node *list;
	list = root->next;

	for (; list != 0; ) {
		if (list)
			printf("show: %d\n", list->value);
		list = list->next;
	}
}

/* Delete each node, recursivelly */
void list_delete_all(struct list_node *node)
{

	if (node->next) {
		list_delete_all(node->next);
		free(node);
		node=0;
	}
	else {
		free(node);
		node=0;
	}
}

/* Delete list from root */
void list_delete(struct list_node *root)
{
	struct list_node *list;
	list = root->next;

//	printf("\n removing node: %d \n", list->value);
	list_delete_all(list);

}

