#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "smatrix.h"

smatrix smatrix_new(int rows,int cols){
	smatrix m;
	m.data=malloc(rows*cols*sizeof(float));
	m.rows=rows;
	m.cols=cols;
	return m;
}

void smatrix_delete(smatrix* m){
	if(m->data)
		free(m->data);
}

smatrix smatrix_zeros(int rows,int cols){
	smatrix m=smatrix_new(rows,cols);
	for(int i=0;i<rows*cols;i++){
		m.data[i]=0;
	}
	return m;
}

smatrix smatrix_zeros_like(smatrix m){
	return smatrix_zeros(m.rows,m.cols);
}

smatrix smatrix_from_vec(int rows,int cols,float vec[])
{
	smatrix m=smatrix_zeros(rows,cols);
	for(int i=0;i<rows*cols;i++){
		m.data[i]=vec[i];
	}
	return m;
}

smatrix smatrix_add_scalar(smatrix a,float b){
	smatrix res=smatrix_zeros_like(a);
	for(int i=0;i<a.rows*a.cols;i++){
		res.data[i]=a.data[i]+b ;	
	}
	return res;
}

smatrix smatrix_multiply_scalar(smatrix a,float b)
{
	smatrix res=smatrix_zeros_like(a);
	for(int i=0;i<a.rows*a.cols;i++){
		res.data[i]=a.data[i]*b ;	
	}
	return res;
}

smatrix smatrix_add(smatrix a,smatrix b){
	smatrix res;
	if(a.rows!=b.rows || a.cols!=b.cols)
	{
		printf("Sizes need to match\n");
		return res;
	}
	res=smatrix_zeros_like(a);
	for(int i=0;i<a.rows*a.cols;i++){
		res.data[i]=a.data[i]+b.data[i];	
	}
	return res;
}

smatrix smatrix_substract(smatrix a,smatrix b){
	smatrix res;
	if(a.rows!=b.rows || a.cols!=b.cols)
	{
		printf("Sizes need to match\n");
		return res;
	}
	res=smatrix_zeros_like(a);
	for(int i=0;i<a.rows*a.cols;i++){
		res.data[i]=a.data[i]-b.data[i];	
	}
	return res;
}

smatrix smatrix_multiply(smatrix a,smatrix b){
	smatrix res;

	if(a.cols!=b.rows){
		printf("Not multiplicable!\n");
		return res;
	}
	res=smatrix_zeros(a.rows,b.cols);

	for (int i = 0; i < a.rows; ++i) {
   		for (int j = 0; j < b.cols; ++j) {
      		float sum = 0.0f;
         		for (int k = 0; k < a.cols; ++k) {
                sum += a.data[i * a.cols + k] * b.data[k * b.cols + j];
            }
            res.data[i * res.cols + j] = sum;
        }
    }
		
	return res;
}

smatrix smatrix_transpose(smatrix m) {
    smatrix result = smatrix_zeros(m.cols, m.rows);  // transpose shape

    for (int r = 0; r < m.rows; ++r) {
        for (int c = 0; c < m.cols; ++c) {
            result.data[c * result.cols + r] = m.data[r * m.cols + c];
        }
    }

    return result;
}

void smatrix_print(smatrix m){
	for(int r=0;r<m.rows;r++){	
		for(int c=0;c<m.cols;c++){
			printf("%f ",m.data[r*m.cols+c]);
		}
		printf("\n");
   }
}

smatrix smatrix_inverse(smatrix m) {
    smatrix inv;
    int n = m.rows;

    // Check square matrix
    if (m.rows != m.cols) {
        printf("Matrix must be square to invert!\n");
        return inv;
    }

    // Create augmented matrix: n x 2n
    float* aug = malloc(n * 2 * n * sizeof(float));
    if (!aug) {
        printf("Memory allocation failed.\n");
        return inv;
    }

    // Initialize augmented matrix [A | I]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            aug[i * 2 * n + j] = m.data[i * n + j];       // Left: A
            aug[i * 2 * n + j + n] = (i == j) ? 1.0f : 0.0f; // Right: I
        }
    }

    // Gaussian elimination with partial pivoting
    for (int i = 0; i < n; i++) {
        // Find pivot row
        float maxEl = fabsf(aug[i * 2 * n + i]);
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            float val = fabsf(aug[k * 2 * n + i]);
            if (val > maxEl) {
                maxEl = val;
                maxRow = k;
            }
        }

        if (maxEl < 1e-12) {
            printf("Matrix is singular or nearly singular!\n");
            free(aug);
            return inv;
        }

        // Swap maximum row with current row (pivot)
        if (maxRow != i) {
            for (int j = 0; j < 2 * n; j++) {
                float tmp = aug[i * 2 * n + j];
                aug[i * 2 * n + j] = aug[maxRow * 2 * n + j];
                aug[maxRow * 2 * n + j] = tmp;
            }
        }

        // Make pivot = 1
        float pivot = aug[i * 2 * n + i];
        for (int j = 0; j < 2 * n; j++) {
            aug[i * 2 * n + j] /= pivot;
        }

        // Eliminate column i from other rows
        for (int r = 0; r < n; r++) {
            if (r != i) {
                float factor = aug[r * 2 * n + i];
                for (int c = 0; c < 2 * n; c++) {
                    aug[r * 2 * n + c] -= factor * aug[i * 2 * n + c];
                }
            }
        }
    }

    // Extract inverse matrix from augmented matrix
    inv = smatrix_new(n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inv.data[i * n + j] = aug[i * 2 * n + j + n];
        }
    }

    free(aug);
    return inv;
}