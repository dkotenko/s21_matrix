#include "color.h"
#include "tests.h"

void populate_matrix(double **arr, matrix_t *m)
{
    for (int i; i < m->rows; i++) {
        for (int j; j < m->columns; j++) {
            m->matrix[i][j] = arr[i][j];
        }
    }
}

void init_matrixes_3x3(matrix_t *A, matrix_t *B)
{   
	double m1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7,8,9}};
	double m2[3][3] = {{1,1,1},{1,1,1},{1,1,1}};
    
	*A = s21_create_matrix(3, 3);
	*B = s21_create_matrix(3, 3);
    
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			A->matrix[i][j] = m1[i][j];
			B->matrix[i][j] = m2[i][j];
		}
	}
}

int print_result(char *test_name, int r)
{
    int result = r == 0 ? 1 : 0;
    printf("%s%s - %s%s\n",
        result ? ANSI_COLOR_GREEN : ANSI_COLOR_RED,
        test_name,
        result ? "OK" : "FAILURE",
        ANSI_COLOR_RESET);
    return r;
}


int main()
{
    int r = 0;
    
    
    r += print_result("Free ", test_s21_free_matrix());
    r += print_result("Create ", test_s21_create_matrix());
    r += print_result("Equal ", test_s21_eq_matrix());
    r += print_result("Sum ", test_s21_sum_matrix());
    r += print_result("Sub ", test_s21_sub_matrix());
    r += print_result("Transpose ", test_s21_sub_matrix());
    print_result("TOTAL", r);
    return 0;
}