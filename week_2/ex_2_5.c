#include<stdio.h>

int main() {
	int n1, n2, cont=1;
	printf("Trova il minimo comune multiplo fra due numeri.\n\n");
	printf("Inserisci il primo numero: ");
	scanf("%d", &n1);
	printf("Inserisci il secondo numero: ");
	scanf("%d", &n2);
	while((cont%n1)!=0 || (cont%n2)!=0) {
		cont++;
	}
	printf("\nIl minimo comune multiplo fra %d e %d è %d\n", n1, n2, cont);
}
