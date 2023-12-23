#include "s21_matrix.h"
#include <math.h>

static void s21_populate_minor_row(double *src_row, double *dest_row, int column, int a_size) {
    int m = 0;

    for (int j = 0; j < a_size; j++) {
        if (j != column) {
            dest_row[m] = src_row[j];
            m++;
        }
    }
}

static void s21_populate_minor(double **src, double **dest,  int row, int column, int a_size)
{
    int k = 0;

    for (int i = 0; i < a_size; i++) {
        if (i != row) {
            s21_populate_minor_row(src[i], dest[k], column, a_size);
            k++;
        }
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
        int result_code = s21_create_matrix(n, n, result);
        for (int i = 0; i < n && result_code == RES_OK; i++) {
            for (int j = 0; j < n; j++) {
                s21_populate_minor(A->matrix, temp_minor, i, j, n);
                double determinant = 0;
                result_code = s21_determinant_array(temp_minor, n - 1, n - 1, &determinant);
                if (result_code != RES_OK) {
                    break ;
                }
                result->matrix[i][j] = determinant * pow(-1, i + j);
            }
        }
        s21_free_matrix_array(temp_minor, n - 1);
    }
    return result_code;
}