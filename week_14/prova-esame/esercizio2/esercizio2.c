#include "esercizio2.h"
#include <stdio.h>
#include "../utils/mat_struct.h"

TipoSCL lowerValues(Mat* m, float value) {
	TipoSCL result=(TipoSCL)malloc(sizeof(NodoSCL));
	TipoSCL aux=result;
	for(int r=0; r<m->rows; r++) {
		for(int c=0; c<m->cols; c++) {
			if(m->row_ptrs[r][c] < value) {
				aux->next = (NodoSCL*) malloc(sizeof(NodoSCL));
				aux = aux->next;
				aux->v = m->row_ptrs[r][c];
				aux->row = r;
				aux->col = c;
			}
		}
	}
	aux->next=NULL;
	return result->next;
}
