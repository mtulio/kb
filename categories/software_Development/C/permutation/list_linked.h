
#ifndef _LIST_LINKED_H_
#define _LIST_LINKED_H_

#define MAX_BUF_SIZE	200

struct list_node {
	int value;
	struct list_node *next;
};

/* inser value on new node */
void list_insert_int(struct list_node *node, int value);

/* Show all nodes from root */
void list_show(struct list_node *root);

/* Delete each node, recursivelly */
void list_delete_all(struct list_node *node);

/* Delete list from root */
void list_delete(struct list_node *root);

#endif /*_LIST_LINKED_H_*/

