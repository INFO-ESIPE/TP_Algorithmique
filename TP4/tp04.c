#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"

#define MAX_VALUE 10000
#define MAX_SIZE 10

int main(int argc, char *argv[]) {

	srand(time(NULL));

    printf("\n-----SELECTION SORT-----\n");
    test_sort(0, "selection_sort");
    printf("\n");

    printf("\n-----INSERTION SORT-----\n");
    test_sort(0, "insertion_sort");
    printf("\n");

    printf("\n-----QUICK SORT-----\n");
    test_sort(0, "quick_sort");
    printf("\n");


	/*test_sort(0, MAX_VALUE, MAX_SIZE);*/

	return EXIT_SUCCESS;
}
