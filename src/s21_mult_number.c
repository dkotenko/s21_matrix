#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result)
{
	int result_code = RES_OK;

	if (A->rows < 1 || A->columns < 1) {
		result_code = RES_INCORRECT;
	} else {
		result_code = s21_create_matrix(A->rows, A->columns, result);
	}

	if (result_code == RES_OK) {
		for (int i = 0; i < A->columns; i++) {
			for (int j = 0; j < A->rows; j++) {
				result->matrix[i][j] = A->matrix[i][j] * number;
			}
		}
	}
	return result_code;
}