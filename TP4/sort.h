#ifndef SORT_H
#define SORT_H
int nb_less;
int nb_swap;
int nb_seconds;

int less(int a, int b);

void swap(int *a, int *b);

/* 
    Function to compare if a sort function worked
    const void *a : sorted array
    const void *b : unsorted array
    */
int comparator(const void *a,const void *b);
int compare(int *unsorted, int*sorted, int array_size);
void test_sort(int withDemo, char* sort_function);



void selection_sort(int t[], int size);
void insertion_sort(int t[], int size);

void quick_sort(int t[], int size);

#endif /* SORT_H */