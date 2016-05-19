#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    
    //Valori di Gradi
	float *valori = (float*)malloc(sizeof(float));
    //Scala usata
	char *scala = (char*)malloc(sizeof(char)); 
    
    printf("C per Celsius, K per Kelvin e F per Fahrenheit \n");
    printf("Inserisci la scala da usare: \n");
    scanf("%c", scala);
    printf("Inserisci la temperatura: \n");
    scanf("%f", valori);
 
	if(*scala == 'c' ){
	    printf("Kelvin: %f, F: %f \n", *valori + 273.15, (*valori *9/5) + 32);
	}

	else if (*scala == 'k'){
        printf("Celsius: %f, F: %f \n", *valori - 273.15, ((*valori - 273.15) *9/5) +32);
	}

    else {
        printf("Celsius: %f, Kelvin: %f \n", (*valori -32)*5/9, (*valori -32)*5/9 + 273.15);
    }
    
    free(valori);
    free(scala);
}
