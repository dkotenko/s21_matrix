#include "tests.h"

START_TEST(test_mult_number_invalid) {
	matrix_t mult = {0};
	matrix_t A = {0};

	A.rows = 0;
	int res = s21_mult_number(&A, 2, &mult);
	ck_assert_int_eq(res, RES_INCORRECT);
	
    A.columns = 0;
	A.rows = 1;
	res = s21_mult_number(&A, 2, &mult);
	ck_assert_int_eq(res, RES_INCORRECT);
} END_TEST

START_TEST(test_mult_number_correct) {
	matrix_t A = {0};
	matrix_t B = {0};
	matrix_t mult = {0};
	init_matrixes_3x3(&A, &B);

	int res = s21_mult_number(&A, 2, &mult);
	matrix_t m_result = {0};
	s21_create_matrix(3,3, &m_result);
	double result[3][3] = {{2,4,6}, {8,10,12}, {14,16,18}};
	
	for (int i = 0; i < m_result.rows; i++) {
        for (int j = 0; j < m_result.columns; j++) {
            m_result.matrix[i][j] = result[i][j];
        }
    }
	ck_assert_int_eq(s21_eq_matrix(&mult, &m_result), SUCCESS);
	ck_assert_int_eq(res, RES_OK);
	
	s21_free_matrix(&m_result, m_result.rows);
	s21_free_matrix(&mult, mult.rows);
	s21_free_matrix(&A, A.rows);
	s21_free_matrix(&B, B.rows);
} END_TEST


Suite *mult_number_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Mult number matrix");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_mult_number_correct);
  tcase_add_test(tc_core, test_mult_number_invalid);
  suite_add_tcase(s, tc_core);

  return s;
}