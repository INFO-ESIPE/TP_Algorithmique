/*
	Algorithmique - Les fonctions récursives (TP2)
	Max Ducoudré - INFO1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*Renvoi 1 si la chaîne de caractère str entre l'indice lo et li est un palindrome, sinon 0*/
int palindrome_rec(char str[], int lo, int hi) 
{
	if(lo < hi) {
		if(str[lo] == str[hi]) return palindrome_rec(str, lo+1, hi-1);
		else return 0;
	}
	return 1;
}

/*Renvoi 1 si str est un palindrome, sinon 0*/
int palindrome(char str[]) 
{
	int hi = 0;
	while(str[hi] != '\0') hi++;
	if(str[0] != '\0') hi--;

	return palindrome_rec(str, 0, hi);
}

/*Affiche les entiers naturels allant de n à 1 récursivement*/
void increasing_sequence_rec(int n)
{
	if(n <= 0) return;
	else {
		increasing_sequence_rec(n-1);
		printf("%d ", n);

	}
}

/*Affiche les entiers naturel allant de 1 à n récursivement*/
void decreasing_sequence_rec(int n)
{
	if(n <= 0) return;
	else {
		printf("%d ", n);
		decreasing_sequence_rec(n-1);
	}
}

/*Compte le nombre de fois que elt apparaît dans le tableau t dans l'interval lo/hi*/
int count(int t[], int lo, int hi, int elt)
{
	if(lo > hi) return 0;
	if(t[lo] == elt) {
		return count(t, lo+1, hi, elt)+1;
	} else {
		return count(t, lo+1, hi, elt);
	}

}

/*Renvoie le nombre d'occurence de l'élément le plus présent dans le tableau t entre l'indice lo et hi*/
int max_count(int t[], int lo, int hi)
{
	if (lo >= hi) return 0;

	if(count(t, lo, hi, t[lo]) < count(t, lo, hi, t[lo+1]))
		return max_count(t, lo+1, hi);
	else
		return count(t, lo, hi, t[lo]);
		
	return 0;
}


int getDigitFromNumber(int n, int offset)
{
	int result = 0;
	int i;
	for(i = 0; i < offset && n != 0; i++) {
		result += n%10;
		n = n/10;
	}
	return result;
}


/*Fonction qui prend en argument un entier positif n et qui renvoie la somme des chiffres qui le forment (version itérative).*/
int sum_digits_iter(int n) 
{
	int result = 0;
	int i;
	for(i = 0; n != 0; i++) {
		result += n%10;
		n = n/10;
	}
	return result;
}

/*Fonction qui prend en argument un entier positif n et qui renvoie la somme des chiffres qui le forment (version révursive).*/
int sum_digits_rec(int n) 
{
	if(n == 0) return 0;
    return (n % 10 + sum_digits_rec(n / 10));
}


/* Fonction qui  renvoie la longueur de la plus longue suite croissante dans un tableau t (linéaire) */
int longest_incr_iter(int t[], int lo, int hi)
{
	int result = 1;
	int lenght = 1;
	int i;

	for(i = lo+1; i <= hi; i++) {
		if(t[i] >= t[i-1]) lenght++;
		else  {
			if(result < lenght) result = lenght;
			lenght = 1;
		}
	}
	if (result < lenght) result = lenght;

	return result;
}

/* Fonction qui renvoie la longueur de la première suite croissante dans un tableau t */
int first_incr(int t[], int lo, int hi)
{
	int lenght = 1;
	int i;

	for(i = lo+1; i <= hi; i++) {
		if(t[i] >= t[i-1]) lenght++;
		else return lenght;		
	}
	return lenght;
}

/* Fonction qui renvoie la longueur de la plus longue suite croissante dans un tableau t (récursive) */
int longest_incr_rec(int t[], int lo, int hi)
{
	int taille = first_incr(t, lo, hi);
	if(taille > first_incr(t, lo+taille, hi))
		return taille;
	else
		return longest_incr_rec(t, lo+taille, hi);
}