#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "array.h"




int calcul_time_for_sort(int search_time, char sort_function);
void fill_instr_data_time(int sec, FILE *fptr)
{
    int size;

    printf("Calcul for %d seconds...\n", sec);
    fprintf(fptr, "%d ", sec);

    size = calcul_time_for_sort(sec, 's');
    fprintf(fptr, "%d ", size);
    printf("Select sort : %d\n", size);

    size = calcul_time_for_sort(sec, 'i');
    fprintf(fptr, "%d ", size);
    printf("Insert sort : %d\n", size);

    size = calcul_time_for_sort(sec, 'q');
    fprintf(fptr, "%d ", size);
    printf("Quick sort : %d\n", size);


    fprintf(fptr, "\n");
    

}

void fill_instr_data(int size, char line_flag, int with_quicksort, FILE *fptr)
{
    int max_value;
    int* tab;
    
    max_value = 100000;
	
    fprintf(fptr, "%d ", size);
	tab = create_array(size);
	fill_random_array(tab, size, max_value);


    nb_less = 0;
    nb_swap = 0;
    selection_sort(tab, size);

    if(line_flag == 'c') fprintf(fptr, "%d ", nb_less);
    if(line_flag == 's') fprintf(fptr, "%d ", nb_swap);


    nb_less = 0;
    nb_swap = 0;
	insertion_sort(tab, size);

    if(line_flag == 'c') fprintf(fptr, "%d ", nb_less);
    if(line_flag == 's') fprintf(fptr, "%d ", nb_swap);

    if(with_quicksort)
    {
        nb_less = 0;
        nb_swap = 0;
        quick_sort(tab, size);
        if(line_flag == 'c') fprintf(fptr, "%d", nb_less);
        if(line_flag == 's') fprintf(fptr, "%d", nb_swap);
    }

    fprintf(fptr,"\n");

    free(tab);
}


int calcul_time_for_sort(int search_time, char sort_function)
{  
    int* tab = NULL;
    int nb_seconds = 0;
    int size = 0;
    
    /*int start_try = 10000000;*/
    int arrondi = 10000;

    while(nb_seconds < search_time)
    {
        size += arrondi;
    
        tab = create_array(size);        
	    fill_random_array(tab, size, 10000);

        if(sort_function == 'i')
        {
            nb_seconds =  time(NULL);
            insertion_sort(tab, size);
            nb_seconds = time(NULL) - nb_seconds;
        }
        else if(sort_function == 's')
        {
            nb_seconds =  time(NULL);
            selection_sort(tab, size);
            nb_seconds = time(NULL) - nb_seconds;
        }
        else if(sort_function == 'q')
        {
            nb_seconds =  time(NULL);
            quick_sort(tab, size);
            nb_seconds = time(NULL) - nb_seconds;
        }

        
        free(tab);
        tab = NULL;
    }
    if(size != 0) size -= arrondi;

    return size;
}

int main(int argc, char** argv)
{
    srand(time(NULL));
    
    int nb_seconds = 0;
    int size = atoi(argv[1]);

    int* tab = create_array(size);        
    fill_random_array(tab, size, 10000);
    printf("For %d elements\n", size);

    /*
    nb_seconds =  time(NULL);
    insertion_sort(tab, size);
    nb_seconds = time(NULL) - nb_seconds;
    printf("Insertion sort : %d\n", nb_seconds);
    

    nb_seconds =  time(NULL);
    selection_sort(tab, size);
    nb_seconds = time(NULL) - nb_seconds;
    printf("Selection sort : %d\n", nb_seconds);
    */
    

    
    nb_seconds =  time(NULL);
    quick_sort(tab, size);
    nb_seconds = time(NULL) - nb_seconds;
    printf("Quick sort : %d\n", nb_seconds);
    


    free(tab);


    /*int i;


    FILE *fptr;
    */

    /*
    fptr = fopen("data/sort1.dat","w");
    printf("Writing data...\n");
    for(i = 0; i <= 100; i++)
        fill_instr_data(i*100, 'c', 1, fptr);

    printf("Data written in sort1.dat !\n");
    fclose(fptr);



    fptr = fopen("data/sort2.dat","w");
    printf("Writing data...\n");
    for(i = 0; i <= 100; i++)
        fill_instr_data(i*10, 'c', 1, fptr);

    printf("Data written in sort2.dat !\n");
    fclose(fptr);


    fptr = fopen("data/sort3.dat","w");
    printf("Writing data...\n");
    for(i = 0; i <= 100; i++)
        fill_instr_data(i*100, 's', 0, fptr);

    printf("Data written in sort3.dat !\n");
    fclose(fptr);

    */
    /*
    fptr = fopen("data/sort4.dat","w");
    printf("Writing data...\n");
    for(i = 0; i <= 2; i++)
        fill_instr_data_time(i, fptr);

    printf("Data written in sort4.dat !\n");
    fclose(fptr);

    */


    return 0;
}



