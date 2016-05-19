#include<stdio.h>

void scambia(int *a, int *b);

int main() {
	int a, b;
	a = 1;
	b = 2;
	printf("Prima\n\ta = %d\n\tb = %d\n", a, b);
	scambia(&a, &b);
	printf("Dopo\n\ta = %d\n\tb = %d\n", a, b);
}

void scambia(int *a, int *b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}
