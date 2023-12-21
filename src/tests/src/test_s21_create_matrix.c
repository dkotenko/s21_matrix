#include "tests.h"

START_TEST(test_create_invalid) {
  matrix_t sum = {0};
  int res = 0;

	res = s21_create_matrix(0, 1, &sum);
	ck_assert_int_eq(res, RES_INCORRECT);

  res = s21_create_matrix(1, 0, &sum);
	ck_assert_int_eq(res, RES_INCORRECT);
	
} END_TEST

START_TEST(test_create_matrix) {
  matrix_t m = {0};
  int res = 0;
	res = s21_create_matrix(3,3, &m);
	
  ck_assert_int_eq(res, RES_OK);
	ck_assert_int_eq(m.rows, 3);
	ck_assert_int_eq(m.columns, 3);
  ck_assert_int_eq((int)m.matrix[0][0], 0);
	s21_free_matrix(&m, m.rows);
} END_TEST


Suite *create_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Create matrix");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_create_matrix);
  tcase_add_test(tc_core, test_create_invalid);
  suite_add_tcase(s, tc_core);
  return s;
}