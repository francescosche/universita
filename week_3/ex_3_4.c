#include<stdio.h>

int main() {
	int min, num;
	printf("Inserisci un numero: ");
	scanf("%d", &num);
	min = num;
	while(num!=0) {
		printf("Inserisci un altro numero (0 per uscire): ");
		scanf("%d", &num);
		if(num!=0 && num < min) {
			min = num;
		}
	}
	printf("Il numero più basso fra quelli inseriti è %d \n", min);
}
