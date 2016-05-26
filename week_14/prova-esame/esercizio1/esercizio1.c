#include "esercizio1.h"
#include "../utils/mat_struct.h"

float mat_avg(Mat* m, int rs, int cs, int bs) {
	float totale = 0;
	for(int r=rs; r<rs+bs; r++) {
		for(int c=cs; c<cs+bs; c++) {
			totale += m->row_ptrs[r][c];
		}
	}
	return totale/(bs*bs);
}

Mat* matrixScale(Mat* m, int block_size) {
	int new_rows = (m->rows)/block_size;
	int new_cols = (m->cols)/block_size;
	Mat* new_m = (Mat*)Mat_alloc(new_rows, new_cols);
	for(int r=0; r<new_m->rows; r++) {
		for(int c=0; c<new_m->cols; c++) {
			new_m->row_ptrs[r][c] = mat_avg(m, r*block_size, c*block_size, block_size);
		}
	}
	return new_m;
}
