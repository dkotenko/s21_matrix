#include "s21_matrix.h"
#include <check.h>

static void init_matrixes_3x3(matrix_t *A, matrix_t *B)
{   
	double m1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7,8,9}};
	double m2[3][3] = {{1,1,1},{1,1,1},{1,1,1}};
    
	*A = s21_create_matrix(3, 3);
	*B = s21_create_matrix(3, 3);
    
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			A->matrix[i][j] = m1[i][j];
			B->matrix[i][j] = m2[i][j];
		}
	}
}

START_TEST(test_sub_invalid) {
	matrix_t sub;
	matrix_t A;
	matrix_t B;
	init_matrixes_3x3(&A, &B);

	A.columns = 4;
	sub = s21_sub_matrix(&A, &B);
	ck_assert_int_eq(sub.matrix_type, INCORRECT_MATRIX);
	
	A.rows = 4;
	A.columns = 3;
	sub = s21_sub_matrix(&A, &B);
	ck_assert_int_eq(sub.matrix_type, INCORRECT_MATRIX);

	A.rows = 0;
	B.rows = 0;
	sub = s21_sub_matrix(&A, &B);
	ck_assert_int_eq(sub.matrix_type, INCORRECT_MATRIX);

	A.rows = 1;
	B.rows = 1;
	A.columns = 0;
	B.columns = 0;
	sub = s21_sub_matrix(&A, &B);
	ck_assert_int_eq(sub.matrix_type, INCORRECT_MATRIX);
	
	s21_free_matrix(&A, A.rows);
	s21_free_matrix(&B, B.rows);
} END_TEST

START_TEST(test_sub_correct) {
	matrix_t A;
	matrix_t B;
	init_matrixes_3x3(&A, &B);

	matrix_t sub = s21_sub_matrix(&A, &B);
	matrix_t m_result = s21_create_matrix(3,3);
	double result[3][3] = {{0,1,2}, {3,4,5}, {6,7,8}};
	
	for (int i = 0; i < m_result.rows; i++) {
        for (int j = 0; j < m_result.columns; j++) {
            m_result.matrix[i][j] = result[i][j];
        }
    }
	ck_assert_int_eq(s21_eq_matrix(&sub, &m_result), SUCCESS);
	
	s21_free_matrix(&m_result, m_result.rows);
	s21_free_matrix(&sub, sub.rows);
	s21_free_matrix(&A, A.rows);
	s21_free_matrix(&B, B.rows);
} END_TEST


Suite *sub_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Sub matrix");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_sub_correct);
  tcase_add_test(tc_core, test_sub_invalid);
  suite_add_tcase(s, tc_core);

  return s;
}

matrix_t s21_sub_matrix(matrix_t *A, matrix_t *B)
{
	if (A->columns != B->columns || A->rows != B->rows || A->rows < 1 || A->columns < 1) {
		return get_incorrect_matrix();
	}
	matrix_t matrix = s21_create_matrix(A->rows, A->columns);
	for (int i = 0; i < A->columns; i++) {
		for (int j = 0; j < A->rows; j++) {
			matrix.matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
		}
	}
	matrix.matrix_type = CORRECT_MATRIX;
	return matrix;
}