#ifndef __LIST_H__
#define __LIST_H__

typedef struct _olink {
    int pos;
    struct _olink *next;
} olink;

typedef struct _link {
    char *word;
    struct _olink *occurrences;
    struct _link *next;
} link;

typedef struct _table {
link **buckets;
int M; /* nombre de seaux */
int size; /* nombre de mots dans la table */
} table;

void free_list(link *lst);

link *find_list(link *lst, char word[]);
link *insert_first_list(link *lst, char word[]);

void display_list(link *lst);

int count_words(link *lst);
int count_distinct_words(link *lst);

void add_occurrence(link *lnk , int pos);
int count_occurences(link *lnk);

table *create_table(int M);
void add_occ_table(table *tab, char word[], int pos);
int hash(char *word, int M);
void print_table(table *tab);
int size_table(table *tab);
void free_table(table *tab);
#endif
