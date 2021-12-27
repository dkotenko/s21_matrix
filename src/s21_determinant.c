#include "s21_matrix.h"

double s21_determinant(matrix_t *A)
{
	if (A->rows != A->columns || A->rows < 1 || A->columns < 1) {
		return 0;
	}
	
}