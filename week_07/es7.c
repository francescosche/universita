#include <stdio.h>
#include <stdlib.h>

double* vec_read(int *dim, char *filename);
void    vec_print(double *v, int dim);
void    vec_write(char *filename, double *v, int dim);
void    vec_scale(double *v, int dim, double d);
double  vec_dot(double *src1, double *src2, int dim);
double* vec_clone(double *v, int dim);

int main(int argc, char **argv) {
  int dim1 = 0, dim2 = 0, dim3 = 0;
  
  /********************************************************
   *                    TEST vec_read                     *
   ********************************************************/
  printf("Leggo v1 dal file vec_1.txt...");
  double *v1 = vec_read(&dim1, "vec_1.txt");
  printf(" done.\n\n");

  /********************************************************
   *                    TEST vec_print                    *
   ********************************************************/
  printf("v1: ");
  vec_print(v1, dim1);
  printf("\n\n");

  /********************************************************
   *                    TEST vec_write                    *
   ********************************************************/
  printf("Scrivo una copia di v1 in copia_vec_1.txt...");
  vec_write("copia_vec_1.txt", v1, dim1);
  printf(" done.\n\n");

  /********************************************************
   *                    TEST vec_scale                    *
   ********************************************************/
  printf("Leggo v2 dal file vec_2.txt...");
  double *v2 = vec_read(&dim2, "vec_2.txt");
  printf(" done.\n");
  printf("v2: ");
  vec_print(v2, dim2);
  printf("\n");
  printf("Leggo v3 dal file vec_3.txt...");
  double *v3 = vec_read(&dim3, "vec_3.txt");
  printf(" done.\n");
  printf("v3: ");
  vec_print(v3, dim3);
  printf("\n");
  printf("Scalo v3 di un fattore di 0.5...");
  vec_scale(v3, dim3, 0.5);
  printf(" done.\n");
  printf("v3: ");
  vec_print(v3, dim3);  
  printf("\n\n");

  /********************************************************
   *                    TEST vec_dot                      *
   ********************************************************/
  printf("Calcolo il prodotto scalare tra v2 e v3...");
  double dot = vec_dot(v2, v3, dim2);
  printf(" done.\n");
  printf("Il profotto scalare tra v2 e v3 e': %lf\n\n", dot);

  /********************************************************
   *                    TEST vec_clone                    *
   ********************************************************/
  printf("Clono v2...");
  double *copy_v2 = vec_clone(v2, dim2);
  printf(" done.\n");
  printf("Copia v2: ");
  vec_print(copy_v2, dim3);  

  free(copy_v2);
  free(v3);
  free(v2);
  free(v1);
  printf("\n");

  return 0;
}





/*
	Questa funzione prende in input un puntatore ad un intero (dim) ed il nome di un file (filename).
	La funzione deve restituire un array contenente gli elementi della seconda riga del file.
	La dimensione dell'array è scritta nella prima riga del file, e dovrà essere inserita nella variabile "dim" così da poter essere letta all'esterno della funzione
*/
double* vec_read(int *dim, char *filename) {
	//	aprire il file
	FILE* f = fopen(filename, "r");
	
	//	leggere il primo dato
	//	inserire il dato nel puntatore dim
	fscanf(f, "%d", dim);
	
	//	creo il vettore di grandezza "dim"
	double * vettore = (double *)malloc(*dim * sizeof(double));
	
	//	per ogni elemento da 0 a dim
	for(int i=0; i<*dim; i++) {
	
		//	inserisco nel vettore il valore corrispondente, preso dalla seconda riga, in posizione n
		fscanf(f, "%lf", vettore+i);
	
	}
	
	// ritornare il vettore contenente i nuovi elementi
	return vettore;
	
}





/*
	Questa funzione prende in input un puntatore ad un array (v) e la dimensione dell'array (dim)
	Deve inoltre stampare in formato [x_1 x_2 ... x_dim] tutto il contenuto dell'array
*/

void vec_print(double *v, int dim) {

	//	stampo il primo carattere della printf
	printf("[");
	
	//	per ogni elemento dell'array (da 0 a dim-1)
	for(int i=0; i<dim; i++) {
		
		//	stampo il contenuto della cella di memoria attuale (i)
		printf("%lf", *(v+i));
		
		//	se non mi trovo nell'ultima cella di memoria
		if(i != dim-1)
		
			//	stampo uno spazio per dividere i valori delle varie celle
			printf(" ");
			
	}
	
	//	stampo il carattere finale della printf
	printf("]");
}





/*
	Dato in ingresso il nome di un file (filename), il puntatore ad un vettore (v) e la dimensione del vettore stesso (dim)
	La funzione stampa all'interno del file, il contenuto del vettore, con la seguente formattazione [x_1 x_2 x_3 ... x_dim]
*/

void vec_write(char *filename, double *v, int dim) {

	//	apro il file
	FILE * f = fopen(filename, "w");
	
	//	stampo, all'interno del file, la parentesi quadra di apertura
	fprintf(f, "[");
	
	//	per ogni elemento all'interno del vettore
	for(int i=0; i<dim; i++) {
		
		//	stampo, all'interno del file, il contenuto "i" del vettore
		fprintf(f, "%lf", v[i]);
		
		//	se non ci troviamo nell'ultima cella di memoria del vettore
		if(i != dim-1)
		
			//	stampo, nel file, uno spazio
			fprintf(f, " ");
			
	}
	
	//	stampo, nel file, la parentesi quadra di chiusura
	fprintf(f, "]");
}





/*
	Questa funzione prende in input un vettore (v) di (dim) componenti e moltiplica tutti i valori al suo interno per d, parametro della funzione
*/


void vec_scale(double *v, int dim, double d) {
	
	// per ogni elemento del vettore
	for(int i=0; i<dim; i++) {
	
		// accedo al valore attuale
		double * numero = v+i;
		
		// moltiplico il valore per d
		*numero = *numero*d;
		
	}

}





/*
	Questa funzione, riceve in input due vettori (src1, src2) della stessa dimensione (dim) e restituisce il loro prodotto scalare
	Il prodotto scalare è la somma di tutti i prodotti fra valori con lo stesso indice.
*/

double vec_dot(double *src1, double *src2, int dim) {

	double somma;

	// per ogni elemento da 0 a dim
	for(int i=0; i<dim; i++) {
	
		// sommo il risultato del prodotto fra x_i e y_i con il totale attuale
		somma += (*(src1+i))*(*(src2+i));
	
	}	
	
	// ritorno il valore finale della somma
	return somma;
	
}





/*
	Questa funzione prende in ingresso un vettore (v) di dimensione "dim".
	Restituisce poi una copia del vettore in un'altro spazio di memoria.
*/

double* vec_clone(double *v, int dim) {
	// allochiamo uno spazio di memoria di dimensione dim e tipo double
	double * v1 = (double *)malloc(dim*sizeof(double));
	
	// inseriamo il valore del primo vettore nell'indice i all'interno dell'indice i del vettore appena creato
	v1 = v;
		
	// restituisco il vettore appena popolato
	return v1;
}
