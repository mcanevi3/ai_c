#ifndef SMATRIX_H
#define SMATRIX_H

// starts from 1,1
#define SMATRIX_AT(m, i, j) ((m).data[((i)-1)*(m).cols + ((j)-1)])

struct _smatrix
{
	float* data;
	int cols;
	int rows;
};
typedef struct _smatrix smatrix;

smatrix smatrix_new(int,int);
void smatrix_delete(smatrix*);

smatrix smatrix_zeros(int,int);
smatrix smatrix_zeros_like(smatrix);
smatrix smatrix_from_vec(int,int,float[]);

smatrix smatrix_add_scalar(smatrix,float);
smatrix smatrix_multiply_scalar(smatrix,float);

smatrix smatrix_add(smatrix,smatrix);
smatrix smatrix_substract(smatrix,smatrix);
smatrix smatrix_multiply(smatrix,smatrix);

smatrix smatrix_transpose(smatrix);

void smatrix_print(smatrix);

smatrix smatrix_inverse(smatrix);

#endif
