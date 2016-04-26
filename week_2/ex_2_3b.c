#include<stdio.h>

int main() {
	printf("Disegna un quadrato con lunghezza del lato scelta dall'utente.\n\n");
	int num, num_r, num_c;
	printf("Inserisci la lunghezza del lato: ");
	scanf("%d", &num);
	num_r = num;
	num_c = num;
	printf("\n");
	while(num_r>0) {
		while(num_c>0) {
			if(num_c == num || num_c == 1 || num_r == 1 || num_r == num)
				printf("*");
			else
				printf(" ");
			num_c--;
		}
		printf("\n");
		num_c = num;
		num_r--;
	}
}
