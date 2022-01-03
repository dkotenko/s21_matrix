#include "s21_matrix.h"

void s21_free_matrix(matrix_t *matrix, int i)
{
	while (--i > -1) {
		free(matrix->matrix[i]);
        matrix->matrix[i] = NULL;
	}
	free(matrix->matrix);
    matrix->matrix = NULL;
}