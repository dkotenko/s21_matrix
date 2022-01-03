#include "s21_matrix.h"

int test_s21_free_matrix(void)
{
	int r = 0;
	matrix_t m = s21_create_matrix(2,2);
	s21_free_matrix(&m, m.rows);
	r += m.matrix != NULL;
	return r;
}