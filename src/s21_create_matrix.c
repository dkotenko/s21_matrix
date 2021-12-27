#include "s21_matrix.h"

static void free_matrix(matrix_t *matrix, int i)
{
	while (--i > -1) {
		free(matrix->matrix[i]);
	}
	free(matrix->matrix);
}

matrix_t s21_create_matrix(int rows, int columns)
{
	matrix_t matrix;

	if (rows < 1 || columns < 1) {
		matrix.matrix_type = INCORRECT_MATRIX;
		return matrix;
	}

	matrix.matrix = calloc(rows	, sizeof(double *));
	if (!matrix.matrix) {
		return get_incorrect_matrix();
	}
	for (int i = 0; i < columns; i++) {
		matrix.matrix = calloc(columns, sizeof(double));
		if (!matrix.matrix) {
			free_matrix(&matrix, i);
			return get_incorrect_matrix();
		}
	}
	matrix.matrix_type = ZERO_MATRIX;
	matrix.rows = rows;
	matrix.columns = columns;
	return matrix;
}