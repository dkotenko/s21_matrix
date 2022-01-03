#include "tests.h"


static int test_correct_s21_sub_matrix(matrix_t *A, matrix_t *B)
{
	matrix_t sub = s21_sub_matrix(A, B);
	matrix_t m_result = s21_create_matrix(3,3);
	double result[3][3] = {{0,1,2}, {3,4,5}, {6,7,8}};
	int r = 0;
	
	for (int i = 0; i < m_result.rows; i++) {
        for (int j = 0; j < m_result.columns; j++) {
            m_result.matrix[i][j] = result[i][j];
        }
    }
	r += s21_eq_matrix(&sub, &m_result) == 0;
	s21_free_matrix(&m_result, m_result.rows);
	s21_free_matrix(&sub, sub.rows);
	return print_result("Sub matrix: correct matrix", r);
}

int test_incorrect_s21_sub_matrix(matrix_t *A, matrix_t *B)
{
	int r = 0;
	matrix_t sub;

	A->columns = 4;
	sub = s21_sub_matrix(A, B);
	r += sub.matrix_type != INCORRECT_MATRIX;

	A->rows = 4;
	A->columns = 3;
	sub = s21_sub_matrix(A, B);
	r += sub.matrix_type != INCORRECT_MATRIX;

	A->rows = 0;
	B->rows = 0;
	sub = s21_sub_matrix(A, B);
	r += sub.matrix_type != INCORRECT_MATRIX;

	A->rows = 1;
	B->rows = 1;
	A->columns = 0;
	B->columns = 0;
	sub = s21_sub_matrix(A, B);
	r += sub.matrix_type != INCORRECT_MATRIX;
	
	A->rows = 3;
	B->rows = 3;
	return print_result("Sub matrix: incorrect matrix", r);
}

int test_s21_sub_matrix(void)
{
	int r = 0;
	matrix_t A;
	matrix_t B;
	init_matrixes_3x3(&A, &B);
	r += test_correct_s21_sub_matrix(&A, &B);
	r += test_incorrect_s21_sub_matrix(&A, &B);
	
	s21_free_matrix(&A, A.rows);
	s21_free_matrix(&B, B.rows);
	
	return r;
}