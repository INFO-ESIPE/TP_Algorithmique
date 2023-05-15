#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define MAX_WORD_LENGTH 80

link *read_text(FILE *infile) {
    link *lst = NULL;
    char *word = (char *)malloc(MAX_WORD_LENGTH*sizeof(char));
    while (fscanf(infile, "%s ", word) != -1) {
        lst = insert_first_list(lst, word);
    }
    free(word);
    return lst;
}

table *read_text_table(FILE *infile, int N) {
    table *tab = create_table(N);
    char *word = (char *)malloc(MAX_WORD_LENGTH*sizeof(char));
    while (fscanf(infile, "%s ", word) != -1) {
        add_occ_table(tab, word, 0);
    }
    free(word);
    return tab;
}

int main(int argc, char **argv) {

    if (argc < 3) {
        fprintf(stderr, "Usage: concordance <in_file> <out_file>\n");
        return 1;
    }

    FILE *fin = fopen(argv[1], "r");
    if (fin == NULL) {
        fprintf(stderr, "Error opening file for reading: %s\n", argv[1]);
        return 1;
    }


    /* LISTE CHAINEE*/
    /*link *lst = read_text(fin);
    fclose(fin);
    display_list(lst);
    printf("Total number of words = %d\n", count_words(lst));
    printf("Total number of distinct words = %d\n", count_distinct_words(lst));
    free_list(lst);
    */


    /* TABLE DE HASHAGE*/
    table* tab = read_text_table(fin, 10);
    print_table(tab);
    char output[1000];
    sprintf(output, "---File %s---\nwords : %d\ndistinct words : %d\n", argv[1], tab->size, size_table(tab));
    fclose(fin);
    free_table(tab);

    FILE *fout = fopen(argv[2], "w");
    if (fout == NULL) {
        fprintf(stderr, "Error opening file for writing: %s\n", argv[2]);
        return 1;
    }
    fprintf(fout, "%s", output);
    fclose(fout);


    return 0;
}

