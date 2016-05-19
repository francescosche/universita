#include<stdio.h>

// includo la libreria "stdlib.h" perchè devo usare la funzione
// sizeof() che si trova all'interno di questa libreria

#include<stdlib.h>

int main() {
	char c;
	short s;
	int i;
	long l;
	float f;
	double d;
	
	// dichiaro la variabile dimensione di tipo intero
	// in cui, ad ogni operazione, assegno un valore diverso
	
	int dimensione;
	
	// all'interno della printf il "\t" lascia una tabulazione (4 spazi)
	// all'interno della printf il "%p" stampa la variabile puntatore presa come argomento
	
	// ad ogni operazione, creo un puntatore dello stesso
	// tipo della variabile per ricavarne l'indirizzo
	
	char* add_c = &c;
	dimensione = sizeof(c);
	printf("char\n\tindirizzo: \t%p\n\tdimensione: \t%d byte\n", add_c, dimensione);
	short* add_s = &s;
	dimensione = sizeof(s);
	printf("short\n\tindirizzo: \t%p\n\tdimensione: \t%d byte\n", add_s, dimensione);
	int* add_i = &i;
	dimensione = sizeof(i);
	printf("int\n\tindirizzo: \t%p\n\tdimensione: \t%d byte\n", add_i, dimensione);
	long* add_l = &l;
	dimensione = sizeof(l);
	printf("long\n\tindirizzo: \t%p\n\tdimensione: \t%d byte\n", add_l, dimensione);
	float* add_f = &f;
	dimensione = sizeof(f);
	printf("float\n\tindirizzo: \t%p\n\tdimensione: \t%d byte\n", add_f, dimensione);
	double* add_d = &d;
	dimensione = sizeof(d);
	printf("double\n\tindirizzo: \t%p\n\tdimensione: \t%d byte\n", add_d, dimensione);
}
