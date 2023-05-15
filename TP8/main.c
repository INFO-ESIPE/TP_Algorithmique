#include "tree.h"
#include "visualtree.h"
#include "bst.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>  // <cstdlib> en C++

void update_tree_display(node* t) {
    printf("Tree height : %d\n", height(t));
    write_tree(t);
}

int main() {
    srand(time(NULL));
    unsigned long int time_start; 
    node *t;
    char selected_word[255];
    node* find_node;

    printf("=== ARBRE BINAIRE ===\n");
    printf("== Construire un arbre ==\n");

    printf("'s X1 X2 X3 X4 [...]' : à partir d'une suite d'entiers (X)\n");
    /* ex : "s 20 13 8 7 0 0 11 0 0 16 0 0 23 21 0 0 27 0 0"*/

    printf("'a X'                 : aléatoirement à partir d'un nombre de noeuds X\n");
    /* ex : "a 100"*/

    char choice;
    scanf(" %c", &choice);
    if(choice == 's') { 
        t = scan_tree();
    } else if(choice == 'a') {
        int n;
        scanf(" %d", &n);
        time_start = time(NULL);
        t = create_random_bst_tree(n);
        printf("Temps de construction : %ld secondes\n", time(NULL) - time_start);
    } else {
        printf("Erreur : réponse non reconnue\n");
        return 1;
    }

    update_tree_display(t);

    while(1) {
        printf("\n");
        printf("== Manipuler un arbre ==\n");
        printf("'i X'  : insérer X dans l'arbre\n");
        printf("'f X'  : chercher X dans l'arbre\n");
        printf("'r X'  : supprime l'élément X de l'arbre\n");
        printf("'q' : quitter\n");
        scanf(" %c", &choice);

        if(choice == 'i') {
            scanf(" %s", selected_word);
            insert_bst(t, selected_word);
            update_tree_display(t);
            continue;

        } else if (choice == 'f') {
            scanf(" %s", selected_word);
            find_node = find_bst(t, selected_word);
            if(find_node == NULL) printf("Element non trouvé !\n");
            else printf("Element %s trouvé !\n", find_node->word);

        } else if (choice == 'r') {
            scanf(" %s", selected_word);
            remove_bst(t, selected_word);
            update_tree_display(t);
            continue;
        } else if (choice == 'q') {
            break;
        } else {
            printf("Erreur : réponse non reconnue\n");
            continue;
        }
    }

    printf("Final tree : ");
    display_infix(t);
    printf("\n");
    update_tree_display(t);
    free_tree(t);
    
  
  return 0;
}
