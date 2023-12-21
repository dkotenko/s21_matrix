#include "s21_matrix.h"
#include <math.h>

static void s21_populate_minor(double **src, double **dest,  int row, int column, int a_size)
{
    int k = 0;
    int m;

    for (int i = 0; i < a_size; i++) {
        if (i == row) {
            continue;
        }
        m = 0;
        for (int j = 0; j < a_size; j++) {
            if (j != column) {
                dest[k][m] = src[i][j];
                m++;
            }
        }
        k++;
    }
}

int s21_calc_complements(matrix_t *A, matrix_t *result)
{
    int result_code = RES_OK;
    int n = A->rows;
    (void)result;
    
    if (A->rows != A->columns || A->rows < 1 || A->columns < 1 || !result) {
        result_code = RES_INCORRECT;
	}

    if (result_code == RES_OK) {
        double **temp_minor = s21_create_matrix_array(n - 1, n - 1);
        int resulst_code = s21_create_matrix(n, n, result);
        (void)resulst_code;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                s21_populate_minor(A->matrix, temp_minor, i, j, n);
                result->matrix[i][j] = s21_determinant_array(temp_minor, n - 1, n - 1) * pow(-1, i + j);
            }
        }
        s21_free_matrix_array(temp_minor, n - 1);
    }
    return result_code;
}