#include "tree.h"
#include "visualtree.h"
#include <stdio.h>

int main() {

  // 3, 5, 1, 2,0, 0, 1, 4, 0, 0, 0, 2, 0, 7, 0, 0
  /*node *t = create_node(3, create_node(5, create_node(12, NULL, NULL), create_node(1,  create_node(4, NULL, NULL), NULL)), create_node(2, NULL,  create_node(7, NULL, NULL)));*/
  node *t = scan_tree();

  printf("Prefix : ");
  display_prefix(t);
  printf("\n");

  printf("Infix : ");
  display_infix(t);
  printf("\n");

  printf("Suffix : ");
  display_suffix(t);
  printf("\n");

  printf("Nodes count : %d\n", count_nodes(t));
  printf("Leavers count : %d\n", count_leaves(t));
  printf("Only children count : %d\n", count_only_children(t));
  printf("Tree height : %d\n", height(t));
  write_tree(t);

  free_tree(t);

  return 0;
}
