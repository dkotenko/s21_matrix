#include "s21_matrix.h"

/*
static double get_determinant(matrix_t *A)
{
	int side_size = A->rows
	double minor[side_size][side_size];
	int i, j, runloop, row, col;
	int det = 0;
	int sign = 1;
																	//Initialize sign as 1 initially as first i=element needs to be positive while calculating determinant.
	if(order == 1)
   {
   	return(*(matrix));													//return the determinant value for Single Element.
   }
   else
	{
		for(runloop = 0 ; runloop < order ; runloop++)				//need to run the loop order number of times.
   	{
      	row = 0, col = 0;													//Initialize row and column for Minor Matrix as (0,0).
      	for(i = 0 ; i < order ; i++)									//Loop to go through rows.
      	{
   	   	for(j = 0 ; j < order ; j++)								//Loop to go through columns.
         	{
     	   		*((Minor+i*(order-1))+j)=0;							//Initialize corresponding Minor element as Zero.
            	if(i != 0 && j != runloop)								//Consider only the elements which are not in the same row and column of considered minor.
            	{
            		*((Minor+row*(order-1))+col) = *((matrix+i*order)+j);			//Assign value to Minor from Main Matrix.
            		col++;													//Go to next column.
            		if(col > order-2)										//If column exceeds the Minor Matrix size.
               	{
               		row++;												//Go to next row.
               		col=0;												//Go to first column of next row. 
               	}
					}
				}
			}
         det = det + (sign * ((*(matrix+runloop)) * (determinant(Minor,order-1))));	//Recursive function to call the same function again with Minor size.
         sign=-1*sign;
		}
	}
   free(Minor);																//Free the allocated memory.
   return (det);																//Return the value of determinant.
}
}
*/
double s21_determinant(matrix_t *A)
{
	if (A->rows != A->columns || A->rows < 1 || A->columns < 1) {
		return NAN;
	}
	return 0;
}