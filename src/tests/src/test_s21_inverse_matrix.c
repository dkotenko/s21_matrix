#include "tests.h"
#include <math.h>

START_TEST(test_inverse_invalid) {
	matrix_t m = {0};
	matrix_t result = {0};
	int result_code = RES_OK;

	result_code = s21_create_matrix(2,2, &m);
	PRINT_IF_ERR_CREATE_MATRIX(result_code);

	m.rows = 0;
	result_code = s21_inverse_matrix(&m, &result);
	ck_assert_int_eq(result_code, RES_INCORRECT);

	m.rows = 2;
	m.columns = 0;
	result_code = s21_inverse_matrix(&m, &result);
	ck_assert_int_eq(result_code, RES_INCORRECT);

	m.columns = 3;
	result_code = s21_inverse_matrix(&m, &result);
	ck_assert_int_eq(result_code, RES_INCORRECT);

	s21_free_matrix(&m, m.rows);
} END_TEST


START_TEST(test_inverse_correct) {
	matrix_t ex1 = {0};
	matrix_t res1 = {0};
	int res = RES_OK;

	res |= s21_create_matrix(3, 3, &ex1);
	PRINT_IF_ERR_CREATE_MATRIX(res);
	res |= s21_create_matrix(3, 3, &res1);
	PRINT_IF_ERR_CREATE_MATRIX(res);

	if (res == RES_OK) {
				/*
		1 1 3
		1 3 -3
		-2 -4 -4
		*/
		ex1.matrix[0][0] = 1;
		ex1.matrix[0][1] = 1;
		ex1.matrix[0][2] = 3;
		ex1.matrix[1][0] = 1;
		ex1.matrix[1][1] = 3;
		ex1.matrix[1][2] = -3;
		ex1.matrix[2][0] = -2;
		ex1.matrix[2][1] = -4;
		ex1.matrix[2][2] = -4;

		/*
		1 4 7
		2 5 8
		3 6 9 
		*/
		res1.matrix[0][0] = 3;
		res1.matrix[0][1] = 1;
		res1.matrix[0][2] = 1.5;
		res1.matrix[1][0] = -1.25;
		res1.matrix[1][1] = -0.25;
		res1.matrix[1][2] = -0.75;
		res1.matrix[2][0] = -0.25;
		res1.matrix[2][1] = -0.25;
		res1.matrix[2][2] = -0.25;

		matrix_t inverse1 = {0};
		res = s21_inverse_matrix(&ex1, &inverse1);
		ck_assert_double_eq_tol(res1.matrix[0][0], inverse1.matrix[0][0], EPSILON);
		ck_assert_double_eq_tol(res1.matrix[0][1], inverse1.matrix[0][1], EPSILON);
		ck_assert_double_eq_tol(res1.matrix[0][2], inverse1.matrix[0][2], EPSILON);
		ck_assert_double_eq_tol(res1.matrix[1][0], inverse1.matrix[1][0], EPSILON);
		ck_assert_double_eq_tol(res1.matrix[1][1], inverse1.matrix[1][1], EPSILON);
		ck_assert_double_eq_tol(res1.matrix[1][2], inverse1.matrix[1][2], EPSILON);
		ck_assert_double_eq_tol(res1.matrix[2][0], inverse1.matrix[2][0], EPSILON);
		ck_assert_double_eq_tol(res1.matrix[2][1], inverse1.matrix[2][1], EPSILON);
		ck_assert_double_eq_tol(res1.matrix[2][2], inverse1.matrix[2][2], EPSILON);
		s21_free_matrix(&inverse1, inverse1.rows);
	}
	
	s21_free_matrix(&ex1, ex1.rows);
	s21_free_matrix(&res1, res1.rows);
} END_TEST


Suite *inverse_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Inverse matrix");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_inverse_correct);
  tcase_add_test(tc_core, test_inverse_invalid);
  suite_add_tcase(s, tc_core);

  return s;
}