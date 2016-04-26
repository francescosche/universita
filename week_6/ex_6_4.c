#include<stdio.h>

void stampaAsterischi(int n, int fill) {
	if(fill > 0) {
		for(int i=0; i<n; i++) {
			printf("*");
		}
	}else{
/*
		printf("*");
		for(int i=0; i<n-2; i++) {
			printf(" ");
		}
		printf("*");
*/
		for(int i=0; i<n; i++) {
			if(i==0 || i==n-1)
				printf("*");
			else
				printf(" ");
		}
	}
	printf("\n");
}

int main() {
	int n, fill;
	printf("Quanto deve essere lunga la riga?\n\t");
	scanf("%d", &n);
	printf("Devono esserci gli asterischi? (no <= 0, si > 0)\n\t");
	scanf("%d", &fill);
	printf("\n");
	stampaAsterischi(n, fill);
}
