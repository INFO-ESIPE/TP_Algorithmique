#ifndef BST_H
#define BST_H
#include "tree.h"


/*
 * recherche l'élément elt dans l'arbre t. 
 * Elle renvoie l'adresse du noeud contenant l'élément s'il est présent, NULL sinon.
*/
node *find_bst(node *t, char* word);

/*
 * Effectue l'insertion de l'élément elt dans l'arbre binaire de recherche t. 
 * Si l'élément elt est déjà présent, alors la fonction ne modifie rien. 
 * La fonction renvoie un pointeur sur la racine de l'arbre après l'insertion.
*/
node *insert_bst(node *t, char* word);

node *create_random_bst_tree(int n);
node *create_ordered_bst_tree(int n);
node *extract_min_bst(node *t, node **min);
node *remove_bst(node* t, char* word);
#endif