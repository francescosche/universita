#include "esercizio1.h"
#include <stdio.h>

int matrix_block_sum(Mat* dest, Mat* src, int start_row, int start_col) {
	if(dest->cols >= src->cols+start_col && dest->rows >= src->rows+start_row) {
		for(int i=0; i<src->rows; i++) {
			for(int j=0; j<src->cols; j++) {
				dest->row_ptrs[i+start_row][j+start_col] += src->row_ptrs[i][j];
			}
		}
		return (src->cols*src->rows);
	}else{
		return 0;
	}
}
