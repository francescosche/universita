#include<stdio.h>

int main() {
	float numero, radice;
	printf("Inserisci il numero del quale calcolare la radice quadrata: ");
	scanf("%f", &numero);
	
	
	// calcoliamo la radice
	
	radice = numero;
	float radice_vecchia = radice-1;
	
	for(int i=0; i<10; i++) {
		radice = (radice_vecchia+numero/radice_vecchia)/2;
	}
	
	
	printf("La radice quadrata del numero %f è %f\n", numero, radice);
}
