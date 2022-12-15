/*
	Algorithmique (fonction main pour lancer les tests) (TP2)
	Max Ducoudré - INFO1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test.h"


void usage() {
	printf("Usage: bench [options]\n");
	printf("  -a                   Run all tests.\n");
	printf("\n");
	printf("  --exo1               Run tests for exo1 functions.\n");
	printf("  --palindrome         Run tests for palindrome functions.\n");
	printf("\n");
	printf("  --exo2               Run tests for exo2 functions.\n");
	printf("  --increase_seq       Run tests for increasing_sequence function.\n");
	printf("  --decrease_seq       Run tests for decreasing_sequence function.\n");
	printf("\n");
	printf("  --exo3               Run tests for exo3 functions.\n");
	printf("  --count              Run tests for count function.\n");
	printf("  --max_count          Run tests for max_count function.\n");
	printf("\n");
	printf("  --exo4               Run tests for exo4 functions.\n");
	printf("  --sum_digits_iter    Run tests for sum_digits_iter function.\n");
	printf("  --sum_digits_rec     Run tests for sum_digits_rec function.\n");
	printf("\n");
	printf("  --exo5               Run tests for exo5 functions.\n");
	printf("  --longest_incr_iter  Run tests for longest_incr_iter function.\n");
	printf("  --first_incr         Run tests for first_incr function.\n");
	printf("\n");




}


int main(int argc, char* argv[])
{
	if(argc == 2 && argv[1][0] == '-') 
	{
		if(strcmp(argv[1], "--palindrome") == 0|| strcmp(argv[1], "--exo1") == 0){
			test_palindrome();
			return EXIT_SUCCESS;
		} else if (strcmp(argv[1], "--increase_seq") == 0) {
			test_increase_seq();
			return EXIT_SUCCESS;
		} else if (strcmp(argv[1], "--decrease_seq") == 0) {
			test_decrease_seq();
			return EXIT_SUCCESS;
		} else if (strcmp(argv[1], "--exo2") == 0) {
			test_increase_seq();
			test_decrease_seq();
			return EXIT_SUCCESS;
		} else if (strcmp(argv[1], "--exo3") == 0) {
			test_count();
			test_max_count();
			return EXIT_SUCCESS;
		} else if (strcmp(argv[1], "--count") == 0) {
			test_count();
			return EXIT_SUCCESS;
		} else if (strcmp(argv[1], "--max_count") == 0) {
			test_max_count();
			return EXIT_SUCCESS;
		} else if (strcmp(argv[1], "--exo4") == 0) {
			test_sum_digits_iter();
			test_sum_digits_rec();
			return EXIT_SUCCESS;
		} else if (strcmp(argv[1], "--sum_digits_iter") == 0) {
			test_sum_digits_iter();
			return EXIT_SUCCESS;
		} else if (strcmp(argv[1], "--sum_digits_rec") == 0) {
			test_sum_digits_rec();
			return EXIT_SUCCESS;
		} else if (strcmp(argv[1], "--exo4") == 0) {
			test_longest_incr_iter();
			test_first_incr();
			test_longest_incr_rec();
			return EXIT_SUCCESS;
		} else if (strcmp(argv[1], "--longest_incr_iter") == 0) {
			test_longest_incr_iter();
			return EXIT_SUCCESS;
		} else if (strcmp(argv[1], "--first_incr") == 0) {
			test_first_incr();
			return EXIT_SUCCESS;
		} else if (strcmp(argv[1], "--longest_incr_rec") == 0) {
			test_longest_incr_rec();
			return EXIT_SUCCESS;
		} else
		{
			switch (argv[1][1]) 
			{
				case 'a':
					test_palindrome();
					test_increase_seq();
					test_decrease_seq();
					test_count();
					test_max_count();
					test_sum_digits_iter();
					test_sum_digits_rec();
					test_longest_incr_iter();
					test_first_incr();
					test_longest_incr_rec();
					print_total_function_result();
					break;
				default:
					usage();
					return EXIT_FAILURE;
			}
		}
	} else 
	{
		usage();
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;

}