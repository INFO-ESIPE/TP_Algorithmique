#include "arrays.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int *create_array(int max_size) {
    int *ptr = (int*)malloc(max_size*sizeof(int));
    return ptr;
}

void free_array(int t[]) {
    free(t);
}

/*
 * Write this function!
 */
void insert_unsorted(int t[], int *size, int elt) {
	t[*size] = elt;
	(*size)++;
}

/*
 * Write this function!
 */
int find_unsorted(int t[], int size, int elt) {
	int i;
	for(i = 0; i < size; i++) 
		if(t[i] == elt) return 1;

    return 0;
}

/*
 * Write this function!
 */
void insert_sorted(int t[], int *size, int elt) {
	
	int i;
	for(i = (*size); i >= 0 && t[i-1] > elt; i--)
		t[i] = t[i-1];

	t[i] = elt;
	(*size)++;
}

/*
 * Write this function!
 */
int find_sorted(int t[], int size, int elt) {
	
	int lo = 0;
	int hi = size-1;
	int mid;
	while(lo <= hi)
	{
		mid = (lo + hi)/2;
		if(t[mid] == elt) return 1;

		if(t[mid] > elt) hi = mid-1;
		else lo = mid+1;
	}
    return 0;
}

