#ifndef MATRIX_H
#define MATRIX_H

struct _matrix
{
	float* data;
	int cols;
	int rows;
};
typedef struct _matrix matrix;

matrix* matrix_new(int,int);
void matrix_delete(matrix* );

matrix* matrix_zeros(int,int);
matrix* matrix_zeros_like(matrix*);
matrix* matrix_from_vec(int,int,float[]);

matrix* matrix_add_scalar(matrix*,float);
matrix* matrix_multiply_scalar(matrix*,float);

matrix* matrix_add(matrix*,matrix*);
matrix* matrix_substract(matrix*,matrix*);
matrix* matrix_multiply(matrix*,matrix*);

void matrix_print(matrix*);

#endif
