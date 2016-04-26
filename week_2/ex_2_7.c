#include<stdio.h>

int main() {
	int righe, cont=1, cont2, num=1;
	printf("Rappresenta il triangolo di Floyd.\n\n");
	printf("Inserisci il numero di righe del triangolo che vuoi visualizzare: ");
	scanf("%d", &righe);
	while(cont < righe+1) {
		cont2 = cont;
		while(cont2 > 0) {
			printf("%d ", num);
			num++;
			cont2--;
		}
		printf("\n");
		cont++;
	}
}
