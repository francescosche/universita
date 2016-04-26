#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    //Definisco A e B
    int a = 3;
    int b = 5;
    int * a_ptr = &a;
    int * b_ptr = &b;
    
    //Distanza tra A e B
    int offset = b_ptr - a_ptr;
    
    printf("Inidirizzo di A: %d, Indirizzo di B: %d, Offset: %d \n", a_ptr, b_ptr, offset);
    
    //B si trova in  a_ptr + offset
    *(a_ptr + offset) = a;
    
}
