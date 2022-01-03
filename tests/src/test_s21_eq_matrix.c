#include "s21_matrix.h"
#define SUCCESS 1
#define FAILURE 0

static int test_equal()
{
	int r = 0;

	matrix_t A = s21_create_matrix(2,2);
	matrix_t B = s21_create_matrix(2,2);

	r += s21_eq_matrix(&A, &B) == FAILURE;
	s21_free_matrix(&A, A.rows);
	s21_free_matrix(&B, B.rows);
	return r;
}

static int test_non_equal()
{
	matrix_t A = s21_create_matrix(2,2);
	matrix_t B = s21_create_matrix(3,3);
	matrix_t C = s21_create_matrix(2,2);
	int r = 0;

	C.matrix[1][1] = 2;

	r += s21_eq_matrix(&A, &B) == SUCCESS;
	r += s21_eq_matrix(&A, &C) == SUCCESS;

	s21_free_matrix(&A, A.rows);
	s21_free_matrix(&B, B.rows);
	s21_free_matrix(&C, C.rows);
	return r;
}

int test_s21_eq_matrix()
{	
	int r = 0;

	r += test_equal();
	r += test_non_equal();
	return r;
}
