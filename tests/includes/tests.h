#ifndef TESTS_H
#define TESTS_H

#define OK 1
#define FAILURE 1

#include "s21_matrix.h"
#include <stdio.h>

int print_result(char *test_name, int result);
int test_s21_sum_matrix(void);
void init_matrixes_3x3(matrix_t *A, matrix_t *B);
void populate_matrix(double **arr, matrix_t *m);
int test_s21_create_matrix(void);
int test_s21_free_matrix(void);
int test_s21_eq_matrix(void);
int test_s21_sub_matrix(void);
int test_s21_transpose(void);


#endif
