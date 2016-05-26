#include <stdlib.h>
#include <stdio.h>
#include "esercizio2.h"

int rotateList(int** v, TipoSCL src, int num) {
	if(src == NULL) {
		(*v) = NULL;
		return 0;
	}
	
	int l=0;
	TipoSCL aux = src;
	while(aux != NULL) {
		l++;
		aux = aux->next;
	}
	*v = (int*)malloc(sizeof(int)*l);
	
	int i=0;
	while(i<l-num) {
		(*v)[i+num] = src->info;
		src = src->next;
		i++;
	}
	i=0;
	while(i<num) {
		(*v)[i] = src->info;
		src = src->next;
		i++;
	}
	return l;
}
