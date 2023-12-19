#pragma once

#include <stdlib.h>
#include <string.h>
#include <check.h>

typedef enum {
    CORRECT_MATRIX = 0,
    INCORRECT_MATRIX = 1,
    IDENTITY_MATRIX = 2,
    ZERO_MATRIX = 3
} matrix_type_t;

typedef enum {
    FAILURE = 0,
    SUCCESS = 1
} result_t;


typedef struct matrix_struct {
	double **matrix;
	int rows;
	int columns;
    matrix_type_t matrix_type;
} matrix_t;

matrix_t s21_create_matrix(int rows, int columns);
double **s21_create_matrix_array(int rows, int columns);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
matrix_t s21_sum_matrix(matrix_t *A, matrix_t *B);
matrix_t s21_sub_matrix(matrix_t *A, matrix_t *B);
matrix_t s21_mult_number(matrix_t *A, double number);
matrix_t s21_mult_matrix(matrix_t *A, matrix_t *B);
matrix_t s21_transpose(matrix_t *A);
matrix_t s21_calc_complements(matrix_t *A);
matrix_t s21_inverse_matrix(matrix_t *A);
matrix_t s21_get_incorrect_matrix(void);
void s21_free_matrix(matrix_t *matrix, int i);
void s21_free_matrix_array(double **matrix, int i);
double s21_determinant(matrix_t *A);
double s21_determinant_array(double **B, int m, int n);
void s21_print_matrix(matrix_t *m, char *name);