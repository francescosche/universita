#include<stdio.h>

int main() {
	int n_bit,i,bit,decimale=0;
	printf("Converte un numero binario inserito dall'utente in un numero decimale.\n\n");
	printf("Quanti bit avrà il tuo numero? ");
	scanf("%d", &n_bit);
	i = n_bit;
	printf("\n");
	while(i > 0) {
		int posizione = n_bit-i;
		printf("Inserisci il valore del bit 2^%d: ", posizione);
		scanf("%d", &bit);
		while(posizione > 0) {
			bit = bit*2;
			posizione--;
		}
		decimale += bit;
		i--;
	}
	printf("\nIl tuo numero, in decimale, avrebbe %d\n", decimale);
}
