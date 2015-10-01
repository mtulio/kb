#include <stdio.h>
#include <stdlib.h>

/* Study case o lists (insert, delete_all, show)
 * */

struct node {
	int value;
	struct node *next;
};

/* inser value on new node */
void list_insert(struct node *node, int value)
{
	struct node *new;

	if (node->next) {
		list_insert(node->next, value);
	}
	else {
		new = (struct node *)malloc(sizeof(struct node));
		node->next = new;
		new->value = value;
		new->next = 0;
	}
}

/* Show all nodes from root */
void list_show(struct node *root)
{
	struct node *list;
	list = root->next;

	for (; list != 0; ) {
		if (list)
			printf("\nshow: %d", list->value);
		list = list->next;
	}
}

/* Delete each node, recursivelly */
void list_delete_all(struct node *node)
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
void list_delete(struct node *root)
{
	struct node *list;
	list = root->next;

//	printf("\n removing node: %d \n", list->value);
	list_delete_all(list);

}

/* Main - insert N nodes to the list */
int main(void)
{
	struct node *root;
	
	root = (struct node *)malloc(sizeof(struct node) );
	root->next = 0;

	int N=200; // insert N nodes on the list
	
	// testing: 
	//root->value = 5;
	//printf("%d \n", root->value);

	// Inserting N nodes in list
	for (int i=10; i<N; i++) {
		list_insert(root, i);
	}

	list_show(root);
	list_delete(root);
//	list_show(root);

	if (root) {
		free (root);
		root = 0;
	}

	printf("\n finish ;) \n");

	exit (0);
}
