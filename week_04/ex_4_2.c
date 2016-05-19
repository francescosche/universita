#include<stdio.h>

int main() {
	int i= 10;
	int j= 20;
	
	char *p = (char*) &i;
	char *q = (char*) &j;
	
	
	for(int k=0; k<sizeof(int); k++) {
		*q = *p;
		p++;
		q++;
	}
	
	printf("%d == %d\n", i, j);
}
