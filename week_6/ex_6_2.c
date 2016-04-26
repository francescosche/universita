#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
	funzione che risolve equazioni del tipo
		ax^2+bx+c=0
	ritorna
		-1 con 0 soluzioni;
		0 con 1 soluzione;
		1 con 2 soluzioni
*/
int risolviEquazione(float *x1, float *x2, float a, float b, float c) {
	float delta = (b*b)-(4*a*c);
	*x1 = ((b*(-1))+sqrt((b*b)-(4*a*c)))/(2*a);
	*x2 = ((b*(-1))-sqrt((b*b)-(4*a*c)))/(2*a);
	return delta;
}

int main() {
	float s1, s2, a, b, c;
	int r;
	char finale = 'i';
	printf("Inserisci a: ");
	scanf("%f", &a);
	printf("Inserisci b: ");
	scanf("%f", &b);
	printf("Inserisci c: ");
	scanf("%f", &c);
	r = risolviEquazione(&s1, &s2, a, b, c);
	
	if(r+1 == 1)
		finale = 'e';
	else
		finale = 'i';
		
	printf("La funzione ha %d soluzion%c", r+1, finale);
	
	if(r+1 > 0)
		printf(", ovvero %f", s1);
	if(r+1 > 1)
		printf(" e %f", s2);
		
	printf("\n");
}
