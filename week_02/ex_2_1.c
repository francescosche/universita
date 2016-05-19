#include<stdio.h>

int main() {
	float a, b, x;
	printf("Inserisci il valore della variabile 'a': ");
	scanf("%f", &a);
	printf("Inserisci il valore della variabile 'b': ");
	scanf("%f", &b);
	x = (b*(-1))/(a);
	printf("\nCon i valori %f e %f,\nil risultato che risolve l'equazione è %f\n", a, b, x);
}
