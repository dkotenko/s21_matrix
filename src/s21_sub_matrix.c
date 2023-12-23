#include "s21_matrix.h"
#include <check.h>

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result)
{
	int result_code = RES_OK;

	if (A->columns != B->columns || A->rows != B->rows || A->rows < 1 || A->columns < 1) {
		result_code = RES_INCORRECT;
	} else {
		result_code = s21_create_matrix(A->rows, A->columns, result);
	}

	if (result_code == RES_OK) {
		for (int i = 0; i < A->columns; i++) {
			for (int j = 0; j < A->rows; j++) {
				result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
			}
		}	
	}
	return result_code;
}