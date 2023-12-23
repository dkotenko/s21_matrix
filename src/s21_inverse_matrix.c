#include "s21_matrix.h"
#include <math.h>
#include <stdio.h>

static int inverse(double **src, int size, double **result)
{
	
	int i,j,k,n;
    int result_code = RES_OK;
	n = size;

    double a[(n * 2) + 1][(n * 2) + 1];
    double ratio;
    
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            a[i][j] = src[i - 1][j - 1];
        }
    }
    
    /* Augmenting Identity Matrix of Order n */
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==j)
            {
                a[i][j+n] = 1;
            }
            else
            {
                a[i][j+n] = 0;
            }
        }
    }
    
    /* Applying Gauss Jordan Elimination */
    for(i=1;i<=n;i++)
    {
        if(a[i][i] == 0.0)
        {
            result_code = RES_CALC_ERROR;
            break;
        }
        for(j=1;j<=n;j++)
        {
            if(i!=j)
            {
                ratio = a[j][i]/a[i][i];
                for(k=1;k<=2*n;k++)
                {
                    a[j][k] = a[j][k] - ratio*a[i][k];
                }
            }
        }
    }
    
    if (result_code == RES_OK) {
        /* Row Operation to Make Principal Diagonal to 1 */
        for(i=1;i<=n;i++)
        {
            for(j=n+1;j<=2*n;j++)
            {
                a[i][j] = a[i][j]/a[i][i];
            }
        }

        if (result) {
            int m = 0;
            int p;
            
            for(i=1;i<=n;i++)
            {
                p = 0;
                for(j=n+1;j<=2*n;j++)
                {
                    result[m][p] = a[i][j];
                    p++;
                }
                m++;
            }
        } else {
            result_code = RES_INCORRECT;
        }
    }
    return result_code;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result)
{
    int result_code = RES_OK;

    if (A->rows != A->columns || A->rows < 1 || A->columns < 1) {
		result_code |= RES_INCORRECT;
	} else {
        result_code |= s21_create_matrix(A->rows, A->columns, result);
    }
    
    if (result_code == RES_OK) {
        double **inverse_array = NULL;
        result_code = inverse(A->matrix, A->rows, result->matrix);
        if (!inverse_array) {
            result_code = RES_INCORRECT;
        }
    }
    return result_code;
}