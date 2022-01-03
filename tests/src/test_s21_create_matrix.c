#include "tests.h"

int test_s21_create_matrix(void)
{
	int r = 0;
	matrix_t m = s21_create_matrix(3,3);
	m.matrix[0][0] = 1.;
	r += m.rows != 3;
	r += m.columns != 3;
	r += m.matrix_type != ZERO_MATRIX;
	s21_free_matrix(&m, m.rows);
	return r;
}