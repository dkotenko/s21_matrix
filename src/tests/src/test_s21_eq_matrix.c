#include "tests.h"

START_TEST(test_equal_matrix) {
	int res = RES_OK;
	matrix_t A = {0};
	matrix_t B = {0};

	res |= s21_create_matrix(2,2, &A);
	PRINT_IF_ERR_CREATE_MATRIX(res);
	
	res |= s21_create_matrix(2,2, &B);
	PRINT_IF_ERR_CREATE_MATRIX(res);

	ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
	s21_free_matrix(&A, A.rows);
	s21_free_matrix(&B, B.rows);
} END_TEST

START_TEST(test_non_equal_matrix) {
	matrix_t A = {0};
	matrix_t B = {0};
	matrix_t C = {0};
	int res = RES_OK;

	res = s21_create_matrix(2,2, &A);
	PRINT_IF_ERR_CREATE_MATRIX(res);
	res |= s21_create_matrix(3,3, &B);
	PRINT_IF_ERR_CREATE_MATRIX(res);
	res |= s21_create_matrix(2,2, &C);
	PRINT_IF_ERR_CREATE_MATRIX(res);

	if (res == RES_OK) {
		C.matrix[1][1] = 2;
		ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
		ck_assert_int_eq(s21_eq_matrix(&A, &C), FAILURE);
	}

	s21_free_matrix(&A, A.rows);
	s21_free_matrix(&B, B.rows);
	s21_free_matrix(&C, C.rows);
} END_TEST


Suite *equal_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Eq matrix");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_equal_matrix);
  tcase_add_test(tc_core, test_non_equal_matrix);
  suite_add_tcase(s, tc_core);

  return s;
}