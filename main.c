#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

typedef float (*func)(float);

float test_func(float x)
{
	return x*x;
}


int main(){
	matrix* a=matrix_from_vec(2,2,(float[]){1,2,3,4});
	matrix* b=matrix_from_vec(2,2,(float[]){1,2,3,4});
	matrix* c;
		
	matrix_print(a);printf("\n");
	matrix_print(b);printf("\n");
	c=matrix_multiply(a,b);
	matrix_print(c);printf("\n");
	c=matrix_add_scalar(c,2);
	matrix_print(c);printf("\n");
	matrix_print(matrix_multiply_scalar(c,3));printf("\n");
	
	matrix_delete(a);
	matrix_delete(b);
	matrix_delete(c);
	return 0;

}
