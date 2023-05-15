#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

node *create_node(char *word, node *left, node *right) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->left = left;
    new_node->right = right;
    new_node->word = (char *)malloc((strlen(word)+1)*sizeof(char));
    strcpy(new_node->word, word);
    return new_node;
}

void display_prefix(node *t) {
  if (t == NULL) return;
  printf("%s ", t->word);
  display_prefix(t->left);
  display_prefix(t->right);
}

void display_infix(node *t) {
  if (t == NULL) return;
  display_infix(t->left);
  printf("%s ", t->word);
  display_infix(t->right);
}

void display_suffix(node *t) {
  if (t == NULL) return;
  display_suffix(t->left);
  display_suffix(t->right);
  printf("%s ", t->word);
}

node *scan_tree() {
  char word[255];
  scanf("%s", word);
  if (word[0] == '\0') return NULL;
  
  node *left =  scan_tree();
  node *right =  scan_tree();
  return create_node(word, left, right);
}


int count_nodes(node *t) {
  if (t == NULL) return 0;
  return 1 + count_nodes(t->left) + count_nodes(t->right);
}

int count_leaves(node *t) {
  if (t == NULL) return 0;
  if (t->left == NULL && t->right == NULL) return 1;
  return count_leaves(t->left) + count_leaves(t->right);
}

int count_only_children(node *t) {
  if(t == NULL) return 0;
  if(t->left == NULL && t->right != NULL) return 1 + count_only_children(t->right);
  if(t->left != NULL && t->right == NULL) return 1 + count_only_children(t->left);
  return count_only_children(t->left) + count_only_children(t->right);
}

int height(node *t) {
  if(t == NULL) return 0;

  int left_h = height(t->left);
  int right_h = height(t->right);

  if(left_h > right_h) return 1 + left_h;
  else                 return 1 + right_h;
}

void free_tree(node *t) {
  if(t == NULL) return;
  free_tree(t->left);
  free_tree(t->right);
  free(t);
}