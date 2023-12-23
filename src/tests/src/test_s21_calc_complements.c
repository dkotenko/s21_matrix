#include "tests.h"
#include <math.h>

START_TEST(test_calc_complements_invalid) {
	matrix_t m = {0};
	matrix_t result = {0};
	int res = s21_create_matrix(2,2, &m);
	PRINT_IF_ERR_CREATE_MATRIX(res);
	
	if (res == RES_OK) {
		m.rows = 0;
		m.columns = 0;
		res = s21_calc_complements(&m, &result);
		ck_assert_int_eq(res, RES_INCORRECT);

		m.rows = 2;
		m.columns = 0;
		res = s21_calc_complements(&m, &result);
		ck_assert_int_eq(res, RES_INCORRECT);

		m.rows = 2;
		m.columns = 3;
		res = s21_calc_complements(&m, &result);
		ck_assert_int_eq(res, RES_INCORRECT);
		s21_free_matrix(&m, m.rows);
	}
} END_TEST

START_TEST(test_calc_complements_correct) {
	matrix_t source = {0};
	matrix_t expected = {0};
	matrix_t actual = {0};
	int res = RES_OK;

	res = s21_create_matrix(3, 3, &source);
	PRINT_IF_ERR_CREATE_MATRIX(res);
	res = s21_create_matrix(3, 3, &expected);
	PRINT_IF_ERR_CREATE_MATRIX(res);

	PRINT_IF_ERR_CREATE_MATRIX(res);
	if (res == RES_OK) {
			/*
		1 2 3
		0 4 2
		5 2 1
		*/
		source.matrix[0][0] = 1;
		source.matrix[0][1] = 2;
		source.matrix[0][2] = 3;
		source.matrix[1][0] = 0;
		source.matrix[1][1] = 4;
		source.matrix[1][2] = 2;
		source.matrix[2][0] = 5;
		source.matrix[2][1] = 2;
		source.matrix[2][2] = 1;

		/*
		0 10 -20
		4 -14 8
		-8 -2 4 
		*/
		expected.matrix[0][0] = 0;
		expected.matrix[0][1] = 10;
		expected.matrix[0][2] = -20;
		expected.matrix[1][0] = 4;
		expected.matrix[1][1] = -14;
		expected.matrix[1][2] = 8;
		expected.matrix[2][0] = -8;
		expected.matrix[2][1] = -2;
		expected.matrix[2][2] = 4;

		res = s21_calc_complements(&source, &actual);
		ck_assert_double_eq_tol(expected.matrix[0][0], actual.matrix[0][0], EPSILON);
		ck_assert_double_eq_tol(expected.matrix[0][1], actual.matrix[0][1], EPSILON);
		ck_assert_double_eq_tol(expected.matrix[0][2], actual.matrix[0][2], EPSILON);
		ck_assert_double_eq_tol(expected.matrix[1][0], actual.matrix[1][0], EPSILON);
		ck_assert_double_eq_tol(expected.matrix[1][1], actual.matrix[1][1], EPSILON);
		ck_assert_double_eq_tol(expected.matrix[1][2], actual.matrix[1][2], EPSILON);
		ck_assert_double_eq_tol(expected.matrix[2][0], actual.matrix[2][0], EPSILON);
		ck_assert_double_eq_tol(expected.matrix[2][1], actual.matrix[2][1], EPSILON);
		ck_assert_double_eq_tol(expected.matrix[2][2], actual.matrix[2][2], EPSILON);
	
	}
	
	s21_free_matrix(&source, source.rows);
	s21_free_matrix(&expected, expected.rows);
	s21_free_matrix(&actual, actual.rows);
} END_TEST


Suite *calc_complements_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("calc_complements matrix");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_calc_complements_correct);
  tcase_add_test(tc_core, test_calc_complements_invalid);
  suite_add_tcase(s, tc_core);

  return s;
}