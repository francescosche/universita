#include "set.h"

#include <stdio.h>
#include <stdlib.h>

// Data una rappresentazione degli insiemi mediante SCL
// (vedi definizione nel file set.h), implementare le seguenti funzioni
// con side-effect


// stampa gli elementi dell'insieme set
void set_print(SetElem *set) {
	//while(set->next != NULL)
		printf("%d", set->info);
}


// dato un insieme set, restituisce un valore non nullo (true) se l'insieme e' vuoto, 
// 0 (false) altrimenti
int is_empty(SetElem *set) {
    return 0;
}


// dato un insieme set ed un valore intero info, restituisce un valore non nullo (true)
// se info e' un elemento di set, 0 (false) altrimenti
int is_element(SetElem *set, int info) {
    return 0;
}


// dato un insieme set, restituisce un valore non nullo (true) se set rappresenta un insieme
// (ovvero non contiene elementi duplicati), 0 (false) altrimenti
int is_set(SetElem *set) {
    return 0;
}


// dati gli insiemi sub e set, restituisce un valore non nullo (true) se sub e' un
// sottoinsieme di set, 0 (false) altrimenti
int is_subset(SetElem *sub, SetElem *set) {
    return -1;
}

// dato un insieme set e un valore intero, modifica set aggiungendovi l'elemento info
// se non e' gia' presente 
void set_add(SetElem **set, int info) {

}

// dato un insieme set e un valore intero, rimuove dall'insieme l'elemento info
// (se presente)
void set_del(SetElem **set, int info) {

}

// dato un insieme src e un insieme dest, inserisce nell'insieme dest gli elementi di src 
// che non sono gia' presenti in dest
void set_union(SetElem *src, SetElem **dest) {

}

// dato un insieme src e un insieme dest, elimina dall'insieme dest gli eventuali elementi 
// presenti anche in src
void set_difference(SetElem *src, SetElem **dest) {

}
