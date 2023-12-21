#include "s21_matrix.h"

matrix_t s21_transpose(matrix_t *A)
{
	if (A->rows < 1 || A->columns < 1) {
		return s21_get_incorrect_matrix();
	}
	matrix_t matrix = {0};
	int res = s21_create_matrix(A->rows, A->columns, &matrix);
	(void) res;
	for (int i = 0; i < A->rows; i++) {
		for (int j = 0; j < A->columns; j++) {
			matrix.matrix[j][i] = A->matrix[i][j];
		}
	}
	return matrix;
}