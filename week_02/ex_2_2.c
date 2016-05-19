#include<stdio.h>

int main() {
	printf("Calcola la media di una serie di numeri.\n\n");
	float num, tot, media;
	int count=0;
	while(num != 0) {
		printf("Inserisci un numero (0 per uscire): ");
		scanf("%f", &num);
		tot += num;
		count++;
	}
	media = tot/(count-1);
	printf("\nLa media aritmetica dei numeri inseriti è %f\n", media);
}
