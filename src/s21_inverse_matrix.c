#include "s21_matrix.h"
#include <math.h>

double static **inverse(double **num, int size)
{
    double b[25][25], fac[25][25];
    int p, q, m, n, i, j, f;
    f = size;
    for (q = 0;q < f; q++)
    {
        for (p = 0;p < f; p++)
        {
            m = 0;
            n = 0;
            for (i = 0;i < f; i++)
            {
            for (j = 0;j < f; j++)
                {
                    if (i != q && j != p)
                    {
                        b[m][n] = num[i][j];
                        if (n < (f - 2)) {
                            n++;
                        } else {
                            n = 0;
                            m++;
                        }
                    }
                }
            }
            fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
        }
    }
    transpose(num, fac, f);
}

matrix_t s21_inverse_matrix(matrix_t *A)
{
    matrix_t inverse_matrix = s21_create_matrix(A->rows, A->columns);
}