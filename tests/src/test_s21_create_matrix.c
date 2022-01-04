#include "tests.h"

START_TEST(test_create_matrix) {
	matrix_t m = s21_create_matrix(3,3);
	
	ck_assert_int_eq(m.rows, 3);
	ck_assert_int_eq(m.columns, 3);
	ck_assert_int_eq(m.matrix_type, ZERO_MATRIX);
	s21_free_matrix(&m, m.rows);
} END_TEST


Suite *create_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Create matrix");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_create_matrix);
  suite_add_tcase(s, tc_core);
  return s;
}