#include<stdio.h>

void stampaAsterischi(int n) {
	while(n != 0) {
		printf("*");
		n--;
	}
	printf("\n");
}

int main() {
	int num;
	printf("Inserisci il numero di asterischi che vuoi stampare: ");
	scanf("%d", &num);
	stampaAsterischi(num);
}
