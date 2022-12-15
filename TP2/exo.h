/*
	Algorithmique - Les fonctions récursives (TP2)
	Max Ducoudré - INFO1
*/
#ifndef EX1_H
#define EX1_H
	int palindrome_rec(char str[], int lo, int hi);
	int palindrome(char str[]);

	void increasing_sequence_rec(int n);
	void decreasing_sequence_rec(int n);

	int count(int t[], int lo, int hi, int elt);
	int max_count(int t[], int lo, int hi);

	int sum_digits_iter(int n); 
	int sum_digits_rec(int n);

	int longest_incr_iter(int t[], int lo, int hi);
	int first_incr(int t[], int lo, int hi);
	int longest_incr_rec(int t[], int lo, int hi);

#endif 