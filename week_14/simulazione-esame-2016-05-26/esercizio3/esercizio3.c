#include <stdlib.h>

#include "esercizio3.h"

TipoSCL aux_minElements(TipoSCL l1, TipoSCL l2, TipoSCL l3) {
	if(l1->info < l2->info)
		l3->info = l1->info;
	else
		l3->info = l2->info;
	if(l1->next == NULL)
		l3->next = NULL;
	else{
		l3->next = (TipoSCL)malloc(sizeof(NodoSCL));
		return aux_minElements(l1->next, l2->next, l3->next);
	}
	return l3;
}

TipoSCL minElements(TipoSCL l1, TipoSCL l2) {
	TipoSCL l3 = NULL, first;
	if(l1 == NULL)
		return l3;
	first = (TipoSCL)malloc(sizeof(NodoSCL));
	l3 = first;
	l3 = aux_minElements(l1, l2, l3);
	return first;
}
