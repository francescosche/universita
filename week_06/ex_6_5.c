#include<stdio.h>
#include<stdlib.h>

int* allocaEdInizializza(int n, int valore) {
	int* ptr = (int*)malloc(sizeof(int)*n);
	for(int i=0; i<n; i++) {
		int* ptr2 = ptr+i;
		*ptr2 = valore;
	}
	return ptr;
}

int main() {
	int n, valore, * ptr;
	printf("Quanti spazi di memoria vuoi riempire?\n\t");
	scanf("%d", &n);
	printf("Con quale valore vuoi riempire questi spazi?\n\t");
	scanf("%d", &valore);
	
	ptr = allocaEdInizializza(n, valore);
	
	for(int i=0; i<n; i++) {
		int* ptr2 = ptr+i;
		printf("%p\t=>\t%d\n", ptr2, *ptr2);
	}
}
