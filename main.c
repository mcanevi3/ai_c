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
		
	matrix_print(a);
	matrix_print(b);
	c=matrix_multiply(a,b);
	matrix_print(c);
	c=matrix_add_scalar(c,2);
	matrix_print(c);
	
	matrix_delete(a);
	matrix_delete(b);
	matrix_delete(c);
	return 0;

}
