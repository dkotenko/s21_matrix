#include "s21_matrix.h"

/*
** B[m][n]
*/ 
double s21_determinant_array(double **B, int m, int n) {
    int row_size = m;
    int column_size = n;

    if (row_size != column_size) {
        return NAN;
    }

    else if (row_size == 1)
        return (B[0][0]);

    else if (row_size == 2)
        return (B[0][0]*B[1][1] - B[1][0]*B[0][1]);

    else {
        double **minor; //[row_size-1][column_size-1];
        int malloc_size = row_size - 1;
        minor = (double **)malloc(sizeof(double *) * (row_size - 1));
        if (!minor) {
            exit(1);
        }
        for (int i = 0; i < row_size - 1; i++) {
            minor[i] = (double *)malloc(sizeof(double) * (column_size - 1));
            if (!minor[i]) {
                exit(1);
            }
        }

        int row_minor, column_minor;
        int firstrow_columnindex;
        int sum = 0;

        register int row,column;

        // exclude first row and current column
        for(firstrow_columnindex = 0; firstrow_columnindex < row_size;
                firstrow_columnindex++) {

            row_minor = 0;

            for(row = 1; row < row_size; row++) {

                column_minor = 0;

                for(column = 0; column < column_size; column++) {
                    if (column == firstrow_columnindex)
                        continue;
                    else
                        minor[row_minor][column_minor] = B[row][column];

                    column_minor++;
                }

                row_minor++;
            }

            m = row_minor;
            n = column_minor;

            if (firstrow_columnindex % 2 == 0)
                sum += B[0][firstrow_columnindex] * s21_determinant_array(minor, m, n);
            else
                sum -= B[0][firstrow_columnindex] * s21_determinant_array(minor, m, n);

        }
        for (int i = 0; i < malloc_size; i++) {
            free(minor[i]);
        }
        free(minor);
        return sum;
    }
}

double s21_determinant(matrix_t *A)
{
	if (A->rows != A->columns || A->rows < 1 || A->columns < 1) {
		return NAN;
	}
	return s21_determinant_array(A->matrix, A->rows, A->columns);
}