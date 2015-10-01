#include <stdio.h>
#include <stdlib.h>

#include "list_linked.h"

/* Study case o lists (insert, delete_all, show)
 */

/* inser value [int] on new node */
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

/* inser value[str] on new node */
void list_insert_str(struct list_node_str *node, char *value)
{
	struct list_node_str *new;

	if (node->next) {
		list_insert_str(node->next, value);
	}
	else {
		new = (struct list_node_str *)malloc(sizeof(struct list_node_str));
		node->next = new;

		memset(new->value, 0, strlen(new->value));
		memcpy(new->value, value, strlen(value));

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

/* Show all[str] nodes from root */
void list_show_str(struct list_node_str *root)
{
	struct list_node_str *list;
	list = root->next;

	for (int cnt=1; list != 0; cnt++) {
		if (list)
			printf("[%d] show: %s\n", cnt, list->value);
		else
			printf("[%d] show err\n", cnt);
		list = list->next;
	}
}

/* Show all[str] nodes from root */
void list_show_str_k(struct list_node_str *root, int k)
{
	struct list_node_str *list;
	list = root->next;

	for (int n=0; n<k; n++ ) {
		if (n==k-1)
			printf("show_k[%d]: %s\n", k, list->value);
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

/* Delete list from root */
void list_delete_str(struct list_node_str *root)
{
	struct list_node_str *list;
	list = root->next;

//	printf("\n removing node: %d \n", list->value);
	list_delete_all(list);

}

