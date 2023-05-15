#include "bst.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int equal(char *s1, char *s2) {
    return strcmp(s1, s2) == 0;
}

int less(char *s1, char *s2) {
    return strcmp(s1, s2) < 0;
}

node *find_bst(node *t, char* word) {
    node *ptr = t;
    while (ptr != NULL && !equal(ptr->word, word) ) {
        if (less(word, ptr->word)) ptr = ptr->left;
        else ptr = ptr->right;
    }
    return ptr;
}

node *insert_bst(node *t, char* word) {
    if (t == NULL)
        t = create_node(word, NULL, NULL);
    else if (less(word, t->word))
        t->left = insert_bst(t->left, word);
    else if (less(t->word, word))
        t->right = insert_bst(t->right, word);
    return t;
}

node *create_random_bst_tree_aux(int n, char **tab) {
    if (n == 0) return NULL;
    int m = n / 2;
    node *t = create_node(tab[m], NULL, NULL);
    t->left = create_random_bst_tree_aux(m, tab);
    t->right = create_random_bst_tree_aux(n - m - 1, tab + m + 1);
    return t;
}

node *create_ordered_bst_tree(int n) {
    /* Create random words ordered */
    char **tab = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        tab[i] = (char *)malloc(10 * sizeof(char));
        sprintf(tab[i], "%d", i);
    }
    
    node *t = NULL;
    t = create_random_bst_tree_aux(n, tab);
        
    free(tab);
    return t;
}

node *create_random_bst_tree(int n) {
    /* Create random words ordered */
    char **tab = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        tab[i] = (char *)malloc(10 * sizeof(char));
        sprintf(tab[i], "%d", rand() % n);
    }

    

    node *t = NULL;
    t = create_random_bst_tree_aux(n, tab);
        
    free(tab);
    return t;
}

node *extract_min_bst(node *t, node **min) {
    if(t== NULL) *min = NULL;
    else if(t->left != NULL) {
        t->left = extract_min_bst(t->left, min);
    } else {
        node *to_extract = t;
        t = t->right;
        to_extract->right = NULL;
        *min = to_extract;
    }
    return t;
}

node *remove_bst(node* t, char* word) {
    if(t==NULL) return NULL;
    if(less(word, t->word)) {
        t->left = remove_bst(t->left, word);
    } else if(less(t->word, word)) {
        t->right = remove_bst(t->right, word);
    } else {
        node *left = t->left;
        node *right = t->right;
        free(t);
        if(left == NULL) return right;
        if(right == NULL) return left;
        node *tmp;
        right = extract_min_bst(right, &tmp);
        t = tmp;
        t->left = left;
        t->right = right;
    }
    return t;
}