#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    //Minimo
	int *min = (int*)malloc(sizeof(int));
    //Valori
	int *a = (int*)malloc(sizeof(int));
    
	printf("Inserisci il valore: \n");
	scanf("%d", a);
    *min = *a;
	while(*a != 0){
		printf("Inserisci il valore: \n");
		scanf("%d",a);
		if(*a<*min && *a != 0){
			*min= *a;
		}
	} //Chiudo While
	printf("Hai scelto 0, chiudo\n");
	printf("Il minimo e' %d \n", *min);
    free(min);
    free(a);
}
