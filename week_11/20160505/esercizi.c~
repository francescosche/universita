#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "mat.h"

// Data in input una lista di caratteri list , e due caratteri new e old, aggiornare tutti gli
// elementi di list contenenti il carattere old con il carattere new.
void str_update(TipoSCL list, char new, char old) {
	while(list != NULL) {
		if(list->c == old)
			list->c = new;
		list = list->next;
	}
}

// Data in input una matrice di interi rappresentata nella struttura Mat e un valore intero value, 
// creare e restituire un vettore contenente gli indici lineari
// di tutti gli elementi di mat che sono maggiori di value. Si ricorda che
// l'indice lineare di un elemento (r, c) di una matrice di dimensione
// rows x cols e' uguale a r * cols + c. La funzione deve scrivere la 
// dimensione del vettore di output nel parametro n.
int* mat_find(Mat *mat, int value, int *n)
{
	int dim = 0;
	for(int i=0; i<mat->rows; i++) {
		for(int j=0; j<mat->cols; j++) {
			if(mat->row_ptrs[i][j] > value)
				dim++;
		}
	}
	*n = dim;
	int * v = (int*)malloc(sizeof(int)*dim);
	dim = 0;
	for(int i=0; i<mat->rows; i++) {
		for(int j=0; j<mat->cols; j++) {
			if(mat->row_ptrs[i][j] > value) {
				v[dim] = i*(mat->cols)+j;
				dim++;
			}
		}
	}
	return v;
}

// Dato in input un vettore v di dimensione n e un intero value, scrivere
// ricorsivamente zero in tutti gli elementi di v che sono minori di value. 
void vec_wipe(int *v, int n, int value) 
{
    if(n >= 0) {
        if(v[0] < value)
            v[0] = 0;
        vec_wipe(v+1, n-1, value);
    }
}
