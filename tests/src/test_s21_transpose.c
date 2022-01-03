#include "tests.h"

int test_s21_transpose(void)
{
	int r = 0;
	matrix_t src;
	matrix_t dest;

	src = s21_create_matrix(2, 2);
	dest = s21_create_matrix(2, 2);

	/*
	1 2
	3 4
	*/
	src.matrix[0][0] = 1;
	src.matrix[0][1] = 2;
	src.matrix[1][0] = 3;
	src.matrix[1][1] = 4;

	/*
	1 2
	3 4
	*/
	src.matrix[0][0] = 1;
	src.matrix[0][1] = 3;
	src.matrix[1][0] = 2;
	src.matrix[1][1] = 4;

	matrix_t trans = s21_transpose(&src);
	r = s21_eq_matrix(&dest, &trans) == 0;
	return r;
}