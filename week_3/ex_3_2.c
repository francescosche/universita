#include<stdio.h>

void printCoolCheckerboard(int num_tiles, int tile_size) {
	
	for(int row=num_tiles; row>0; row--) {
		for(int row_in=tile_size; row_in>0; row_in--) {
			for(int col=num_tiles; col>0; col--) {
				for(int col_in=tile_size; col_in>0; col_in--) {
					if((row+col)%2==0) {
						printf("*");
					}else{
						printf("-");
					}
				}
			}
			printf("\n");
		}
	}
	
	printf("\n");

}

int main() {
	int num_tiles, tile_size;
	printf("Implementazione della funzione printCoolCheckerboard() che stampa una scacchiera prendendo in input il numero di righe/colonne e la grandezza delle piastrelle da stampare.\n\n");
	printf("Inserisci il numero di righe/colonne che vuoi visualizzare: ");
	scanf("%d", &num_tiles);
	printf("Inserisci la grandezza delle piastrelle da stampare: ");
	scanf("%d", &tile_size);
	printCoolCheckerboard(num_tiles, tile_size);
	return 0;
}
