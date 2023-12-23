#include "s21_matrix.h"
#include <math.h>

/*
** B[m][n]
*/ 
int s21_determinant_array(double **B, int m, int n, double *result) {
    int row_size = m;
    int column_size = n;
    int result_code = RES_OK;

    if (row_size != column_size) {
        result_code = RES_INCORRECT;
    } else if (row_size == 1) {
        *result = B[0][0];
    } else if (row_size == 2) {
        *result = B[0][0]*B[1][1] - B[1][0]*B[0][1];
    } else {
        int malloc_size = row_size - 1;
        double **minor = s21_create_matrix_array(malloc_size, malloc_size); //[row_size-1][column_size-1];
        if (!minor) {
            result_code = RES_INCORRECT;
        }

        int row_minor, column_minor;
        int column_i;
        double sum = 0;

        // exclude first row and current column
        for(column_i = 0; column_i < row_size;
                column_i++) {
            row_minor = 0;
            for(int row = 1; row < row_size; row++) {
                column_minor = 0;
                for(int column = 0; column < column_size; column++) {
                    if (column == column_i)
                        continue;
                    else
                        minor[row_minor][column_minor] = B[row][column];

                    column_minor++;
                }
                row_minor++;
            }
            m = row_minor;
            n = column_minor;
            double determinant;
            result_code = s21_determinant_array(minor, m, n, &determinant);
            if (result_code != RES_OK) {
                break ;
            }
            if (column_i % 2 == 0) {
                sum += B[0][column_i] * determinant;
            } else {
                sum -= B[0][column_i] * determinant;
            }
        }
        s21_free_matrix_array(minor, malloc_size);
        *result = sum;
    }
    return result_code;
}

int s21_determinant(matrix_t *A, double *result)
{
    int result_code = RES_OK;

	if (A->rows != A->columns || A->rows < 1 || A->columns < 1) {
		result_code = RES_INCORRECT;
	}
    result_code |= s21_determinant_array(A->matrix, A->rows, A->columns, result);
	return result_code;
}