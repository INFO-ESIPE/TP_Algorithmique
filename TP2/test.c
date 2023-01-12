/*
	Algorithmique - Permet de tester les fonctions (TP2)
	Max Ducoudré - INFO1
*/

#include <stdio.h>
#include <stdlib.h>

#include "exo.h"


int func_count = 0;
int func_max = 8;


void print_total_function_result()
{
	if(func_max == func_count) printf("\033[1;32m");
	else if(func_count == 0) printf("\033[1;31m");
	else printf("\033[1;33m");

	printf("\nTOTAL OF WORKING FUNCTIONS : %d/%d\n\n", func_count, func_max);
	printf("\033[0m");

}

void print_array(int t[], int size)
{
	int i;
	printf("[");
	for(i = 0; i <= size; i++) {
		if(i != 0) printf(" ");
		printf("%d", t[i]);
		if(i != size) printf(","); 

	}
		printf("]");
}



void print_test_result(int test_max, int test_sucess)
{

	if(test_max == test_sucess) printf("\033[1;32m");
	else if(test_sucess == 0) printf("\033[1;31m");
	else printf("\033[1;33m");
	printf("TOTAL OF SUCESS : %d/%d\n", test_sucess, test_max);
	printf("\033[0m");

}


/* TEST PALINDROME */
int print_test_palindrome(int test_max, int test_count, char* test, int lo, int hi, int expected) 
{
	printf("TEST %d/%d :\n", test_count, test_max);
	int result = palindrome_rec(test, lo, hi);

	printf("  palindrome_rec(\"%s\", %d, %d);\n", test, lo, hi);
	printf("  palindrome(\"%s\"); (wrapped)\n", test);
	printf("  result   = %d\n  expected = %d\n", result, expected);
	if(result == expected) {
		printf("  -> TEST SUCESS\n");
		return 1;
	} else {
		printf("  -> TEST FAILED\n");
		return 0;
	}

}
void test_palindrome()
{
	int test_max = 5;
	int test_count = 0;
	int sucessCount = 0;

	printf("\n----TEST PALINDROME----\n");
	test_count++;
	sucessCount += print_test_palindrome(test_max, test_count, "radar", 0, 4, 1);

	test_count++;
	sucessCount += print_test_palindrome(test_max, test_count, "radar", 0, 3, 0);

	test_count++;
	sucessCount += print_test_palindrome(test_max, test_count, "", 0, 0, 1);
		
	test_count++;
	sucessCount += print_test_palindrome(test_max, test_count, "hello", 0, 4, 0);
		
	test_count++;
	sucessCount += print_test_palindrome(test_max, test_count, "aba", 0, 2, 1);

	print_test_result(test_max, sucessCount);

	if(sucessCount == test_max) func_count++;

}

/* TEST INCREASE_SEQ & DECREASE_SEQ*/
void print_test_increase_seq(int test_count, int test_max, int n)
{
	printf("TEST %d/%d :\n", test_count, test_max);
	printf("  increasing_sequence_rec(%d);\n", n);

	printf("  ");
	increasing_sequence_rec(n);
	printf("\n");
}


void print_test_decrease_seq(int test_count, int test_max, int n)
{
	printf("TEST %d/%d :\n", test_count, test_max);
	printf("  decreasing_sequence_rec(%d);\n", n);

	printf("  ");
	decreasing_sequence_rec(n);
	printf("\n");
}


void test_increase_seq() {
	int test_max = 3;
	int test_count = 0;

	printf("\n----TEST INCREASE SEQ----\n");
	test_count++;
	print_test_increase_seq(test_count, test_max, 10);

	test_count++;
	print_test_increase_seq(test_count, test_max, 0);

	test_count++;
	print_test_increase_seq(test_count, test_max, 7);

	printf("END OF TEST\n");
}

void test_decrease_seq() {
	int test_max = 3;
	int test_count = 0;

	printf("\n----TEST DECREASE SEQ----\n");
	test_count++;
	print_test_decrease_seq(test_count, test_max, 10);

	test_count++;
	print_test_decrease_seq(test_count, test_max, 0);

	test_count++;
	print_test_decrease_seq(test_count, test_max, 7);


	printf("END OF TEST\n");

}

/* TEST COUNT */
int print_test_count(int t[], int lo, int hi, int elt, int expected)
{
	int result = count(t, lo, hi, elt);

	printf("  count(");
	print_array(t, hi);
	printf(", %d, %d, %d);\n",lo,hi,elt);

	printf("  result   = %d\n  expected = %d\n", result, expected);
	if(result == expected) {
		printf("  -> TEST SUCESS\n");
		return 1;
	} else {
		printf("  -> TEST FAILED\n");
		return 0;
	}
}

void test_count()
{
	int sucessCount = 0;
	int test_max = 3;
	int test_count = 0;

	printf("\n----TEST COUNT----\n");

	int array_test_1[] = {1, 4, 3, 3, 2, 3, 3, 4};

	test_count++;
	printf("TEST %d/%d :\n", test_count, test_max);
	sucessCount+=(print_test_count(array_test_1, 0, 7, 3, 4));

	test_count++;
	printf("TEST %d/%d :\n", test_count, test_max);
	sucessCount+=(print_test_count(array_test_1, 0, 7, 4, 2));

	test_count++;
	printf("TEST %d/%d :\n", test_count, test_max);
	sucessCount+=(print_test_count(array_test_1, 0, 7, 10, 0));


	print_test_result(test_max, sucessCount);
	if(sucessCount == test_max) func_count++;
}



/* TEST MAX_COUNT */
int print_test_max_count(int t[], int lo, int hi, int expected)
{
	int result = max_count(t, lo, hi);


	printf("  max_count(");
	print_array(t, hi);
	
	printf(", %d, %d);\n",lo,hi);

	printf("  result   = %d\n  expected = %d\n", result, expected);
		
	if(result == expected) {
		printf("  -> TEST SUCESS\n");
		return 1;
	} else {
		printf("  -> TEST FAILED\n");
		return 0;
	}
	
}

void test_max_count()
{
	int sucessCount = 0;
	int test_max = 4;
	int test_count = 0;

	printf("\n----TEST MAX COUNT----\n");

	test_count++;
	int array_test_1[] = {1, 4, 3, 3, 2, 3, 3, 4};
	printf("TEST %d/%d :\n", test_count, test_max);
	sucessCount+=(print_test_max_count(array_test_1, 0, 7, 4));

	test_count++;
	int array_test_2[] = {1, 4, 5, 4, 2, 5, 3, 3, 4};
	printf("TEST %d/%d :\n", test_count, test_max);
	sucessCount+=(print_test_max_count(array_test_2, 0, 8, 3));


	test_count++;
	int array_test_3[] = {2, 2, 2, 2, 2, 2, 3, 3, 4};
	printf("TEST %d/%d :\n", test_count, test_max);
	sucessCount+=(print_test_max_count(array_test_3, 0, 8, 6));

	test_count++;
	int array_test_4[] = {10};
	printf("TEST %d/%d :\n", test_count, test_max);
	sucessCount+=(print_test_max_count(array_test_4, 0, 1, 1));

	print_test_result(test_max, sucessCount);
	if(sucessCount == test_max) func_count++;
}


/*TEST SUM DIGITS ITER*/
int print_test_sum_digits_iter(int n, int expected)
{
	int result = sum_digits_iter(n);

	printf("  test_sum_digits_iter(%d)\n", n);
	printf("  result   = %d\n  expected = %d\n", result, expected);
		
	if(result == expected) {
		printf("  -> TEST SUCESS\n");
		return 1;
	} else {
		printf("  -> TEST FAILED\n");
		return 0;
	}
	
}
void test_sum_digits_iter()
{
	int sucessCount = 0;
	int test_max = 4;
	int test_count = 0;

	printf("\n----TEST SUM DIGITS (iterartive)----\n");
	test_count++;
	printf("TEST %d/%d :\n", test_count, test_max);
	sucessCount+=print_test_sum_digits_iter(912942,27);

	test_count++;
	printf("TEST %d/%d :\n", test_count, test_max);
	sucessCount+=print_test_sum_digits_iter(123451,16);

	test_count++;
	printf("TEST %d/%d :\n", test_count, test_max);
	sucessCount+=print_test_sum_digits_iter(55,10);

	test_count++;
	printf("TEST %d/%d :\n", test_count, test_max);
	sucessCount+=print_test_sum_digits_iter(0,0);


	print_test_result(test_max, sucessCount);
	if(sucessCount == test_max) func_count++;
}

/*TEST SUM DIGITS REC*/
int print_test_sum_digits_rec(int n, int expected)
{
	int result = sum_digits_rec(n);

	printf("  test_sum_digits_rec(%d)\n", n);
	printf("  result   = %d\n  expected = %d\n", result, expected);
		
	if(result == expected) {
		printf("  -> TEST SUCESS\n");
		return 1;
	} else {
		printf("  -> TEST FAILED\n");
		return 0;
	}
}

void test_sum_digits_rec() 
{
	int sucessCount = 0;
	int test_max = 4;
	int test_count = 0;

	printf("\n----TEST SUM DIGIT (recursive)----\n");
	test_count++;
	printf("TEST %d/%d :\n", test_count, test_max);
	sucessCount+=print_test_sum_digits_rec(912942,27);

	test_count++;
	printf("TEST %d/%d :\n", test_count, test_max);
	sucessCount+=print_test_sum_digits_rec(123451,16);

	test_count++;
	printf("TEST %d/%d :\n", test_count, test_max);
	sucessCount+=print_test_sum_digits_rec(55,10);

	test_count++;
	printf("TEST %d/%d :\n", test_count, test_max);
	sucessCount+=print_test_sum_digits_rec(0,0);

	print_test_result(test_max, sucessCount);
	if(sucessCount == test_max) func_count++;
}


/* TEST longest_incr_iter */
int print_longest_incr_iter(int t[], int lo, int hi, int expected)
{
	int result = longest_incr_iter(t, lo, hi);

	printf("  longest_incr_iter(");
	print_array(t, hi);
	
	printf(", %d, %d);\n",lo,hi);

	printf("  result   = %d\n  expected = %d\n", result, expected);
		
	if(result == expected) {
		printf("  -> TEST SUCESS\n");
		return 1;
	} else {
		printf("  -> TEST FAILED\n");
		return 0;
	}
	return 1;
}

void test_longest_incr_iter() 
{
	int sucessCount = 0;
	int test_max = 4;
	int test_count = 0;

	printf("\n----TEST LONGEST INCREASE (iterartive)----\n");
	test_count++;
	printf("TEST %d/%d :\n", test_count, test_max);
	int array_test_1[] = {1, 2, 3, 2, 4, 6, 8, 3};
	sucessCount+=print_longest_incr_iter(array_test_1, 0, 7, 4);

	test_count++;
	printf("TEST %d/%d :\n", test_count, test_max);
	int array_test_2[] = {1, 2, 3, 1, 2, 3, 4, 5};
	sucessCount+=print_longest_incr_iter(array_test_2, 0, 7, 5);

	test_count++;
	printf("TEST %d/%d :\n", test_count, test_max);
	int array_test_4[] = {1, 2, 3, 1, 2, 3, 4, 5};
	sucessCount+=print_longest_incr_iter(array_test_4, 4, 7, 4);


	test_count++;
	printf("TEST %d/%d :\n", test_count, test_max);
	int array_test_3[] = {0, 0, 1};
	sucessCount+=print_longest_incr_iter(array_test_3, 0, 2, 3);

	print_test_result(test_max, sucessCount);
	if(sucessCount == test_max) func_count++;}




/* TEST longest_incr_iter */
int print_first_incr(int t[], int lo, int hi, int expected)
{
	int result = first_incr(t, lo, hi);

	printf("  print_first_incr(");
	print_array(t, hi);
	
	printf(", %d, %d);\n",lo,hi);

	printf("  result   = %d\n  expected = %d\n", result, expected);
		
	if(result == expected) {
		printf("  -> TEST SUCESS\n");
		return 1;
	} else {
		printf("  -> TEST FAILED\n");
		return 0;
	}
	return 1;
}

void test_first_incr() 
{
	int sucessCount = 0;
	int test_max = 4;
	int test_count = 0;

	printf("\n----TEST SUM DIGIT (recursive)----\n");
	test_count++;
	printf("TEST %d/%d :\n", test_count, test_max);
	int array_test_1[] = {1, 2, 3, 4, 4, 6, 8, 3};
	sucessCount+=print_first_incr(array_test_1, 0, 7, 7);

	test_count++;
	printf("TEST %d/%d :\n", test_count, test_max);
	int array_test_2[] = {1, 3, 5, 2, 3, 4, 5, 3};
	sucessCount+=print_first_incr(array_test_2, 0, 7, 3);

	test_count++;
	printf("TEST %d/%d :\n", test_count, test_max);
	int array_test_4[] = {1, 2, 3, 1, 2, 3, 4, 5};
	sucessCount+=print_first_incr(array_test_4, 4, 7, 4);


	test_count++;
	printf("TEST %d/%d :\n", test_count, test_max);
	int array_test_3[] = {0, 0, 1};
	sucessCount+=print_first_incr(array_test_3, 0, 2, 3);

	print_test_result(test_max, sucessCount);
	if(sucessCount == test_max) func_count++;
}


/* TEST longest_incr_iter */
int print_longest_incr_rec(int t[], int lo, int hi, int expected)
{
	struct SubArray subArray;
	subArray.index = 0;
	subArray.size = 0;

	int result = longest_incr_rec(t, lo, hi, subArray);

	printf("  longest_incr_rec(");
	print_array(t, hi);
	
	printf(", %d, %d);\n",lo,hi);

	printf("  result   = %d\n  expected = %d\n", result, expected);
	printf("SubArray->index = %d | SubArray->size = %d\n", subArray.index, subArray.size);

	if(result == expected) {
		printf("  -> TEST SUCESS\n");
		return 1;
	} else {
		printf("  -> TEST FAILED\n");
		return 0;
	}
	return 1;
}

void test_longest_incr_rec() 
{
	int sucessCount = 0;
	int test_max = 4;
	int test_count = 0;

	printf("\n----TEST LONGEST INCREASE (recursive)----\n");
	test_count++;

	printf("TEST %d/%d :\n", test_count, test_max);
	int array_test_1[] = {1, 2, 3, 2, 4, 6, 8, 3};
	sucessCount+=print_longest_incr_rec(array_test_1, 0, 7, 4);

	test_count++;
	printf("TEST %d/%d :\n", test_count, test_max);
	int array_test_2[] = {1, 2, 3, 1, 2, 3, 4, 5};
	sucessCount+=print_longest_incr_rec(array_test_2, 0, 7, 5);

	test_count++;
	printf("TEST %d/%d :\n", test_count, test_max);
	int array_test_4[] = {1, 2, 3, 1, 2, 3, 4, 5};
	sucessCount+=print_longest_incr_rec(array_test_4, 4, 7, 4);

	test_count++;
	printf("TEST %d/%d :\n", test_count, test_max);
	int array_test_3[] = {0, 0, 1};
	sucessCount+=print_longest_incr_rec(array_test_3, 0, 2, 3);

	print_test_result(test_max, sucessCount);
	if(sucessCount == test_max) func_count++;
}
