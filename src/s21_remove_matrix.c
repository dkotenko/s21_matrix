#include "s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
	s21_free_matrix(A, A->rows);
}