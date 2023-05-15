#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * Create a link representing 1 occurence of the string 'word'.
 * The string is copied and must be freed when the link is freed.
 */
link *create_link(char word[], link *next) {
    if(find_list(next, word) != NULL) {
        link *ptr = find_list(next, word);
        add_occurrence(ptr, count_occurences(ptr));
        return next;
    }

    link *new = malloc(sizeof(link));
    new->word = malloc(strlen(word)+1);
    strcpy(new->word, word);
    new->occurrences = NULL;
    add_occurrence(new, 0);
    new->next = next;
    return new;
}

void free_link(link *lnk) {
    free(lnk->word);
    olink *ptr = lnk->occurrences;
    while(ptr != NULL) {
        olink *tmp = ptr;
        ptr = ptr->next;
        free(tmp);
    }
    free(lnk);
}

void display_list(link *lst) {
    int i = 0;
    while (lst) {
        if(i == 5) {
            printf("[...]");
            break;
        }
        printf("%s (x%d) | ", lst->word, count_occurences(lst));
        lst = lst->next;
        i++;
    }
    printf("\n");
}

void free_list(link *lst) {
    if(lst == NULL) return;
    free_list(lst->next);
    free_link(lst);
}

int equal(char* w1, char* w2) {
    return strcmp(w1, w2) == 0;
}

link *find_list(link* lst, char word[]) {
    if(lst == NULL) return NULL;
    link *ptr = lst;
    while (ptr != NULL && !equal(ptr->word, word))
        ptr = ptr->next;
    return ptr;
}

link *insert_first_list(link *lst, char word[]) {
    return create_link(word, lst);
}

int count_words(link *lst) {
    int count = 0;
    for(link *ptr = lst; ptr != NULL; ptr = ptr->next) {
        count += count_occurences(ptr);
    }
    
    return count;
}
int count_distinct_words(link *lst) {
    int count = 0;
    for(link *ptr = lst; ptr != NULL; ptr = ptr->next) count++;
    return count;
}

int count_occurences(link *lnk) {
    int count = 0;
    for(olink *ptr = lnk->occurrences; ptr != NULL; ptr = ptr->next) count++;
    return count;
}

void add_occurrence(link *lnk , int pos) {
    olink *new = malloc(sizeof(olink));
    new->pos = pos;
    if(lnk->occurrences == NULL) {
        lnk->occurrences = new;
        new->next = NULL;
    } else {
        olink *ptr = lnk->occurrences;
        while(ptr->next != NULL) ptr = ptr->next;
        ptr->next = new;
        new->next = NULL;
    }
}


table *create_table(int M) {
    table *new_table = malloc(sizeof(table));
    new_table->buckets = malloc(M*sizeof(link*));
    for(int i = 0; i < M; i++) new_table->buckets[i] = NULL;
    new_table->M = M;
    new_table->size = 0;
    return new_table;
}

void add_occ_table(table *tab, char word[], int pos) {
    int hash_value = hash(word, tab->M);
    tab->buckets[hash_value] = insert_first_list(tab->buckets[hash_value], word);
    tab->size++;
}

void print_table(table *tab) {
    for(int i = 0; i < tab->M; i++) {
        printf("(%d) %0d elements --> | ", i, count_distinct_words(tab->buckets[i]));
        display_list(tab->buckets[i]);
    }
}

int hash(char *word, int M) {
    int hash = 0;
    int i;
    for(i = 0; i < strlen(word); i++) {
        hash += (i + 1) * word[i]; 
    }
    hash = hash % M;
    if(hash < 0) hash = -hash;

    return hash;
}

int size_table(table *tab) {
    int count = 0;
    for(int i = 0; i < tab->M; i++) {
        count += count_distinct_words(tab->buckets[i]);
    }
    return count;
}

void free_table(table *tab) {
    for(int i = 0; i < tab->M; i++) {
        free_list(tab->buckets[i]);
    }
    free(tab->buckets);
    free(tab);
}