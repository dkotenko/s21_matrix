#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result)
{
    int result_code = RES_OK;

    if (A->columns != B->rows || A->rows < 1 || A->columns < 1 || B->rows < 1 || B->columns < 1) {
		result_code = RES_INCORRECT;
	} else {
        result_code = s21_create_matrix(A->rows, A->columns, result);
    }

    if (result_code == RES_OK) {
        for (int i = 0; i < result->rows; i++) {
            for (int j = 0; j < result->columns; j++) {
                int sum = 0;
                for (int k = 0; k < A->columns; k++) {
                    sum += A->matrix[i][k] * B->matrix[k][j];
                }
                result->matrix[i][j] = sum;
            }           
        }
    }
    return result_code;
}