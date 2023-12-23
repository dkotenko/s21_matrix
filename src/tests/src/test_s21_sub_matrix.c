#include "tests.h"

START_TEST(test_sub_invalid) {
	matrix_t sub = {0};
	matrix_t A = {0};
	matrix_t B = {0};
	int res = 0;
	init_matrixes_3x3(&A, &B);

	A.columns = 4;
	res = s21_sub_matrix(&A, &B, &sub);
	ck_assert_int_eq(res, RES_INCORRECT);
	
	A.rows = 4;
	A.columns = 3;
	res = s21_sub_matrix(&A, &B, &sub);
	ck_assert_int_eq(res, RES_INCORRECT);

	A.rows = 0;
	B.rows = 0;
	res = s21_sub_matrix(&A, &B, &sub);
	ck_assert_int_eq(res, RES_INCORRECT);

	A.rows = 1;
	B.rows = 1;
	A.columns = 0;
	B.columns = 0;
	res = s21_sub_matrix(&A, &B, &sub);
	ck_assert_int_eq(res, RES_INCORRECT);
	
	A.rows = 3;
	B.rows = 3;
	s21_free_matrix(&A, A.rows);
	s21_free_matrix(&B, B.rows);
} END_TEST

START_TEST(test_sub_correct) {
	matrix_t A = {0};
	matrix_t B = {0};
	matrix_t sub = {0};
	init_matrixes_3x3(&A, &B);

	s21_sub_matrix(&A, &B, &sub);
	matrix_t m_result = {0};
	s21_create_matrix(3,3, &m_result);
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