#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

matrix* matrix_new(int rows,int cols){
	matrix* m=malloc(sizeof(matrix));
	m->data=malloc(rows*cols*sizeof(float));
	m->rows=rows;
	m->cols=cols;
	return m;

}

void matrix_delete(matrix* m){
	if(m)
	{
		if(m->data)
			free(m->data);
		free(m);
	}
}

matrix* matrix_zeros(int rows,int cols){
	matrix* m=matrix_new(rows,cols);
	for(int i=0;i<rows*cols;i++){
		m->data[i]=0;
	}
	return m;
}
matrix* matrix_zeros_like(matrix* m){
	return matrix_zeros(m->rows,m->cols);
}
matrix* matrix_from_vec(int rows,int cols,float vec[])
{
	matrix* m=matrix_zeros(rows,cols);
	for(int i=0;i<rows*cols;i++){
		m->data[i]=vec[i];
	}
	return m;
}

matrix* matrix_add(matrix* a,matrix* b){
	matrix* res;
	if(a->rows!=b->rows || a->cols!=b->cols)
	{
		printf("Sizes need to match\n");
		return res;
	}
	res=matrix_zeros_like(a);
	for(int i=0;i<a->rows*a->cols;i++){
		res->data[i]=a->data[i]+b->data[i];	
	}
	return res;
}

matrix* matrix_add_scalar(matrix* a,float b){
	matrix* res=matrix_zeros_like(a);
	for(int i=0;i<a->rows*a->cols;i++){
		res->data[i]=a->data[i]+b ;	
	}
	return res;
}

matrix* matrix_substract(matrix* a,matrix* b){
	matrix* res;
	if(a->rows!=b->rows || a->cols!=b->cols)
	{
		printf("Sizes need to match\n");
		return res;
	}
	res=matrix_zeros_like(a);
	for(int i=0;i<a->rows*a->cols;i++){
		res->data[i]=a->data[i]-b->data[i];	
	}
	return res;
}

matrix* matrix_multiply(matrix* a,matrix* b){
	matrix* res;

	if(a->cols!=b->rows){
		printf("Not multiplicable!\n");
		return res;
	}
	res=matrix_zeros(a->rows,b->cols);

	for (int i = 0; i < a->rows; ++i) {
   		for (int j = 0; j < b->cols; ++j) {
      		float sum = 0.0f;
         		for (int k = 0; k < a->cols; ++k) {
                sum += a->data[i * a->cols + k] * b->data[k * b->cols + j];
            }
            res->data[i * res->cols + j] = sum;
        }
    }
		
	return res;
}

void matrix_print(matrix* m){
	for(int r=0;r<m->rows;r++){	
		for(int c=0;c<m->cols;c++){
			printf("%f ",m->data[r*m->cols+c]);
		}
		printf("\n");
   }

}
