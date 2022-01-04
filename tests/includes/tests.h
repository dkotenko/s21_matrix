#ifndef TESTS_H
#define TESTS_H

#include "s21_matrix.h"
#include <stdio.h>
#include <check.h>

int print_result(char *test_name, int result);
int test_s21_sum_matrix(void);
void init_matrixes_3x3(matrix_t *A, matrix_t *B);
void populate_matrix(double **arr, matrix_t *m);
int test_s21_create_matrix(void);
int test_s21_free_matrix(void);
int test_s21_eq_matrix(void);
int test_s21_sub_matrix(void);
int test_s21_transpose(void);
void print_matrix(matrix_t m);
Suite *free_suite(void);
Suite *create_suite(void);
Suite *equal_suite(void);
Suite *sum_suite(void);
Suite *sub_suite(void);
Suite *trans_suite(void);



#endif
