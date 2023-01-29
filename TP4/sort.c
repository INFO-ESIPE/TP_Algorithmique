#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <time.h>  

#include "sort.h"
#include "array.h"



int less(int a, int b) {
	nb_less++;
	return a < b;
}

void swap(int *a, int *b) {
	nb_swap++;
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void selection_sort(int t[], int size) {
	int i, j, min;
	for(i = 0; i < size; i++)
	{
		min = i;
		for(j = i+1; j < size; j++)
			if(less(t[j], t[min]))
				min = j;
		swap(&t[i], &t[min]);
	}
}

void insertion_sort(int t[], int size)
{
int i,j;
	for (i = 0; i < size; i++) 
	{
		j = i;
		while (j > 0 && less(t[j], t[j-1])) 
		{
			swap(&t[j-1], &t[j]);
			j--;
		}
	}
}


void quick_sort(int t[], int size) {
    if (size < 2) return;

    int pivot = t[size / 2];
    int i, j;
    for (i = 0, j = size - 1; ; i++, j--) {
        while (less(t[i], pivot)) i++;
        while (less(pivot, t[j])) j--;
        if (i >= j) break;
        swap(&t[i], &t[j]);
    }
    quick_sort(t, i);
    quick_sort(t + i, size - i);
}

int comparator(const void *a,const void *b)
{
	int aint = *(int*)a;
	int bint = *(int*)b;
	if (aint == bint)
		return 0;
	else
		if (aint < bint)
			return -1;
		else
			return 1;
}

int compare(int *unsorted, int*sorted, int array_size)
{
	int i;
	qsort (unsorted, array_size, sizeof(int), comparator);
	/*printf("expct: ");*/
	print_array(unsorted, array_size);
	for(i = 0; i < array_size; i++)
		if(unsorted[i] != sorted[i])
			return 0;
	return 1;

}


void test_sort(int withDemo, char* sort_function)
{
	/* Création du tableau */
	int count_test = 0;
	int max_test = 5;


	int max_value = 10000;
	int size = 10;
	int i;
	int* tab = NULL;
	int* tab_init = NULL;

	tab = create_array(size);
	tab_init = create_array(size);
	fill_random_array(tab, size, max_value);
	for(i = 0; i < size; i++)
		tab_init[i] = tab[i];

	

	/* TEST 1 */
	count_test++;
	nb_less = 0;
    nb_swap = 0;

	printf("----%s %d/%d----\n", sort_function, count_test, max_test );
	printf("from : ");
	print_array(tab, size);

	if(strcmp(sort_function, "selection_sort") == 0) selection_sort(tab, size);
	else if(strcmp(sort_function, "insertion_sort") == 0) insertion_sort(tab, size);
	else quick_sort(tab, size);
	
	printf("to   : ");
	print_array(tab, size);
	if(!compare(tab_init, tab, size)) printf("Le tri a échoué ! \n");
    else {
        printf("Le tri a réussi avec : \n");
        printf("%d comparaisons\n", nb_less);
        printf("%d échanges\n", nb_swap);
    }
	free(tab_init);
	free(tab);

	/* TEST 2 */
	size = 10000;
	tab = create_array(size);
	tab_init = create_array(size);
	fill_random_array(tab, size, max_value);
	for(i = 0; i < size; i++)
		tab_init[i] = tab[i];
	count_test++;
	nb_less = 0;
    nb_swap = 0;

	printf("----%s %d/%d----\n", sort_function, count_test, max_test );
	printf("from : ");
	print_array(tab, size);

	if(strcmp(sort_function, "selection_sort") == 0) selection_sort(tab, size);
	else if(strcmp(sort_function, "insertion_sort") == 0) insertion_sort(tab, size);
	else quick_sort(tab, size);
	
	printf("to   : ");
	print_array(tab, size);
	if(!compare(tab_init, tab, size)) printf("Le tri a échoué ! \n");
    else {
        printf("Le tri a réussi avec : \n");
        printf("%d comparaisons\n", nb_less);
        printf("%d échanges\n", nb_swap);
    }


	free(tab_init);
	free(tab);


	/* TEST 3 */

	size = 1000;
	tab = create_array(size);
	tab_init = create_array(size);
	for(i = 0; i < size; i++)
		tab[i] = i%3;

	for(i = 0; i < size; i++)
		tab_init[i] = tab[i];
	count_test++;
	nb_less = 0;
    nb_swap = 0;

	printf("----%s %d/%d----\n", sort_function, count_test, max_test );
	printf("from : ");
	print_array(tab, size);

	if(strcmp(sort_function, "selection_sort") == 0) selection_sort(tab, size);
	else if(strcmp(sort_function, "insertion_sort") == 0) insertion_sort(tab, size);
	else quick_sort(tab, size);
	
	printf("to   : ");
	print_array(tab, size);
	if(!compare(tab_init, tab, size)) printf("Le tri a échoué ! \n");
    else {
        printf("Le tri a réussi avec : \n");
        printf("%d comparaisons\n", nb_less);
        printf("%d échanges\n", nb_swap);
    }
	free(tab_init);
	free(tab);



	/* TEST 4 */
	size = 1000;
	tab = create_array(size);
	tab_init = create_array(size);
	for(i = 0; i < size; i++)
		tab[i] = size-i;

	for(i = 0; i < size; i++)
		tab_init[i] = tab[i];
	count_test++;
	nb_less = 0;
    nb_swap = 0;

	printf("----%s %d/%d----\n", sort_function, count_test, max_test );
	printf("from : ");
	print_array(tab, size);

	if(strcmp(sort_function, "selection_sort") == 0) selection_sort(tab, size);
	else if(strcmp(sort_function, "insertion_sort") == 0) insertion_sort(tab, size);
	else quick_sort(tab, size);
	
	printf("to   : ");
	print_array(tab, size);
	if(!compare(tab_init, tab, size)) printf("Le tri a échoué ! \n");
    else {
        printf("Le tri a réussi avec : \n");
        printf("%d comparaisons\n", nb_less);
        printf("%d échanges\n", nb_swap);
    }


	free(tab_init);
	free(tab);

	/* TEST 5 */
	size = 1000;
	tab = create_array(size);
	tab_init = create_array(size);
	for(i = 0; i < size; i++)
		tab[i] = size;

	for(i = 0; i < size; i++)
		tab_init[i] = tab[i];
	count_test++;
	nb_less = 0;
    nb_swap = 0;

	printf("----%s %d/%d----\n", sort_function, count_test, max_test );
	printf("from : ");
	print_array(tab, size);

	if(strcmp(sort_function, "selection_sort") == 0) selection_sort(tab, size);
	else if(strcmp(sort_function, "insertion_sort") == 0) insertion_sort(tab, size);
	else quick_sort(tab, size);
	
	printf("to   : ");
	print_array(tab, size);
	if(!compare(tab_init, tab, size)) printf("Le tri a échoué ! \n");
    else {
        printf("Le tri a réussi avec : \n");
        printf("%d comparaisons\n", nb_less);
        printf("%d échanges\n", nb_swap);
    }



	/* libération du tableau */
	free(tab_init);
	free(tab);

}


void fill_instr()
{

}
