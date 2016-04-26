#include<stdio.h>

int main() {
	int num;
	printf("Inserisci una serie di numeri (separati da spazi):\n");
	scanf("%d", &num);
	while(num != 0) {
		for(int i=0; i<num; i++) {
			printf("*");
		}
		printf("\n");
		num++;
		scanf("%d", &num);
	}
}
