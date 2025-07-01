#include <stdio.h>
#include <stdlib.h>

#include "smatrix.h"

int main(){
	smatrix a=smatrix_from_vec(2,2,(float[]){1,2,3,4});
	smatrix b=smatrix_from_vec(2,2,(float[]){1,2,3,4});
	smatrix c;
		
	smatrix_print(a);printf("\n");
	smatrix_print(b);printf("\n");
	c=smatrix_multiply(a,b);
	smatrix_print(c);printf("\n");
	c=smatrix_add_scalar(c,2);
	smatrix_print(c);printf("\n");
	smatrix_print(smatrix_multiply_scalar(c,3));printf("\n");
	
	smatrix_delete(&a);
	smatrix_delete(&b);
	smatrix_delete(&c);
	return 0;

}
