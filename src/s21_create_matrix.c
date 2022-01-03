#include "s21_matrix.h"

matrix_t s21_create_matrix(int rows, int columns)
{
	matrix_t matrix;

	if (rows < 1 || columns < 1) {
		matrix.matrix_type = INCORRECT_MATRIX;
		return matrix;
	}

	matrix.matrix = malloc(sizeof(double *) * rows);
	if (!matrix.matrix) {
		return get_incorrect_matrix();
	}
	for (int i = 0; i < columns; i++) {
		matrix.matrix[i] = calloc(columns, sizeof(double));
		if (!matrix.matrix[i]) {
			s21_free_matrix(&matrix, i);
			return get_incorrect_matrix();
		}
	}
	matrix.matrix_type = ZERO_MATRIX;
	matrix.rows = rows;
	matrix.columns = columns;
	return matrix;
}