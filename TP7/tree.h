#ifndef TREE_H
#define TREE_H

typedef struct _node {
    int data;                /* data stored : an integer    */
    struct _node *left;      /* pointer to the left child   */
    struct _node *right;     /* pointer to the right child  */
} node;

/*
 * Allocate memory for a new node.
 */
node *create_node(int data, node *left, node *right);

node *create_tree(int suite[], int size);

void display_prefix(node *t);
void display_suffix(node *t);
void display_infix(node *t);

node *scan_tree();

int count_nodes(node *t);
int count_leaves(node *t);
int count_only_children(node *t);
int height(node *t);
void free_tree(node *t);
#endif /* TREE_H */
