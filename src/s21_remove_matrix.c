#include "s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
	memset(A->matrix, 0, A->rows * A->columns * sizeof(double));
	A->matrix_type = ZERO_MATRIX;
}