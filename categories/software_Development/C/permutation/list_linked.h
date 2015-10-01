
#ifndef _LIST_LINKED_H_
#define _LIST_LINKED_H_

#define MAX_BUF_SIZE	200

struct list_node {
	int value;
	struct list_node *next;
};

struct list_node_str {
	char value[MAX_BUF_SIZE];
	struct list_node_str *next;
};

/* inser value [int] on new node */
void list_insert_int(struct list_node *node, int value);

/* inser value[str] on new node */
void list_insert_str(struct list_node_str *node, char *str);

/* Show all nodes from root */
void list_show(struct list_node *root);

/* Show all[str] nodes from root */
void list_show_str(struct list_node_str *root);

/* Show all[str] nodes from root */
void list_show_str_k(struct list_node_str *root, int k);

/* Delete each node, recursivelly */
void list_delete_all(struct list_node *node);

/* Delete list from root */
void list_delete(struct list_node *root);

#endif /*_LIST_LINKED_H_*/

