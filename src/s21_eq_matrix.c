#include "s21_matrix.h"

#define SUCCESS 1
#define FAILURE 0

int s21_eq_matrix(matrix_t *A, matrix_t *B)
{
	int result = SUCCESS;

	if (!A || !B || A->columns != B->columns || A->rows != B->rows) {
		return FAILURE;
	}
	for (int i = 0; i < A->rows && result == SUCCESS; i++) {
		if (memcmp(A->matrix[i], B->matrix[i], A->columns * sizeof(double))) {
			result = FAILURE;
		}
	}
	return result;
}