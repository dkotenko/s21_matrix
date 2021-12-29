#ifndef TESTS_H
#define TESTS_H

#define OK 1
#define FAILURE 1

#include "s21_matrix.h"

void print_result(char *test_name, int result);
int test_s21_sum_matrix(void);
void init_matrixes_3x3(matrix_t *A, matrix_t *B);
void populate_matrix(double **arr, matrix_t *m);

#endif
