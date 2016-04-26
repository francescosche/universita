#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    float *a = (float*)malloc(11*sizeof(float));
    printf("Inserisci numero: \n");
    scanf("%f", a);
    printf("Valore %f \n", a[0]);
    
    if(a[0] <= 0.0){
        printf("Il numero non può essere negativo! \n");
        return -1;
    }
    
    for(int i = 0; i < 10; i++){
        a[10] =  (a[9-i] + a[0] / a[9-i]) /2.0f;
    }
    
    printf("Radice: %f\n",a[11]);
}
