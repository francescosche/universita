#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  int rows; 
  int cols;
  float **row_ptrs;
} Mat;

Mat* Mat_alloc(int rows, int cols) {
	Mat * matrice = (Mat*)malloc(sizeof(Mat));
	matrice->rows = rows;
	matrice->cols = cols;
	matrice->row_ptrs = (float**)malloc(sizeof(float*)*rows);
	for(int i=0; i<rows; i++) {
		matrice->row_ptrs[i]=(float*)malloc(sizeof(float)*cols);
	}
	return matrice;
}

Mat* Mat_read(char *filename) {
	int righe, colonne;
	FILE * file = fopen(filename, "r");
	fscanf(file, "%d", &righe);
	fscanf(file, "%d", &colonne);
	Mat * matrice = Mat_alloc(righe, colonne);
	for(int i=0; i<righe; i++) {
		for(int j=0; j<colonne; j++) {
			fscanf(file, "%f", &matrice->row_ptrs[i][j]);
		}
	}
	return matrice;
}

void Mat_print(Mat *m) {
	int righe = m->rows;
	int colonne = m->cols;
	for(int i=0; i<righe; i++) {
		for(int j=0; j<colonne; j++) {
			printf("%f ", m->row_ptrs[i][j]);
		}
		printf("\n");
	}
}

void Mat_write(char *filename, Mat *m) {
	FILE * f = fopen(filename, "w");
	int righe = m->rows;
	int colonne = m->cols;
	fprintf(f, "%d ", righe);
	fprintf(f, "%d\n", colonne);
	for(int i=0; i<righe; i++) {
		for(int j=0; j<colonne; j++) {
			fprintf(f, "%f ", m->row_ptrs[i][j]);
		}
		fprintf(f, "\n");
	}
}

int  Mat_is_symmetric(Mat *m) {
	int righe = m->rows;
	int colonne = m->cols;
	for(int i=0; i<righe; i++) {
		for(int j=0; j<colonne; j++) {
			if(m->row_ptrs[i][j] != m->row_ptrs[j][i])
				return 0;
		}
	}
	return 1;
}

void Mat_normalize_rows(Mat *m) {
	float somma, risultato;
	int righe = m->rows;
	int colonne = m->cols;
	for(int i=0; i<righe; i++) {
		somma = 0;
		for(int j=0; j<colonne; j++) {
			somma += ((m->row_ptrs[i][j])*(m->row_ptrs[i][j]));
		}
		risultato = sqrt(somma);
		for(int j=0; j<colonne; j++) {
			m->row_ptrs[i][j] = m->row_ptrs[i][j]/risultato;
		}
	}
}

Mat* Mat_clone(Mat *m) {
	int righe = m->rows;
	int colonne = m->cols;
	Mat * matrice = Mat_alloc(righe, colonne);
	for(int i=0; i<righe; i++) {
		for(int j=0; j<colonne; j++) {
			matrice->row_ptrs[i][j] = m->row_ptrs[i][j];
		}
	}
	return matrice;
}

void Mat_free(Mat *m) {
	int righe = m->rows;
	for(int i=0; i<righe; i++) {
		free(m->row_ptrs[i]);
	}
	free(m->row_ptrs);
	free(m);
}

int main(int argc, char **argv) {
  /********************************************************
   *             TEST Mat_alloc/Mat_read                  *
   ********************************************************/
  printf("Leggo m1 dal file mat_1.txt...");
  Mat *m1 = Mat_read("mat_1.txt");
  printf(" fatto.\n\n");

  /********************************************************
   *                    TEST Mat_print                    *
   ********************************************************/
  printf("m1:\n");
  Mat_print(m1);
  printf("\n");

  /********************************************************
   *                    TEST Mat_write                    *
   ********************************************************/
  printf("Scrivo una copia di m1 in copia_mat_1.txt...");
  Mat_write("copia_mat_1.txt", m1);
  printf(" fatto.\n\n");

  /********************************************************
   *                TEST Mat_is_symmetric                 *
   ********************************************************/
  printf("Leggo m2 dal file mat_2.txt...");
  Mat *m2 = Mat_read("mat_2.txt");
  printf(" fatto.\n");
  printf("m2:\n");
  Mat_print(m2);  
  printf("La matrice m2 e' simmetrica?\n");
  int is_symmmetric = Mat_is_symmetric(m2);
  if(is_symmmetric) {
  	printf("Si e' simmetrica.\n");
  }else{
  	printf("No non e' simmetrica.\n");
  }
  printf("\n");

  /********************************************************
   *               TEST Mat_normalize_rows                *
   ********************************************************/
  printf("Leggo m3 dal file mat_3.txt...");
  Mat *m3 = Mat_read("mat_3.txt");
  printf(" fatto.\n");
  printf("m3:\n");
  Mat_print(m3);  
  printf("Normalizzo le righe della matrice m3...");
  Mat_normalize_rows(m3);
  printf(" fatto.\n");
  printf("La matrice m3 con righe normalizzate e':\n");
  Mat_print(m3);
  printf("\n");

  /********************************************************
   *                    TEST Mat_clone                    *
   ********************************************************/
  printf("Clono m2...");
  Mat *copy_m2 = Mat_clone(m2);
  printf(" fatto.\n");
  printf("Copia m2:\n");
  Mat_print(copy_m2);  

  /********************************************************
   *                    TEST Mat_free                     *
   ********************************************************
   *					NON SICURO						  *
   ********************************************************/
  Mat_free(copy_m2);
  Mat_free(m3);
  Mat_free(m2);
  Mat_free(m1);

  return 0;
}
