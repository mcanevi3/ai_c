#include <stdio.h>
#include <stdlib.h>

#include "gradient_descent.h"
#include "matrix.h"

matrix* func(matrix* x){
    matrix* xnew=matrix_zeros_like(x);
    return x*x-4*x+5;
}

int main()
{
    float alpha=0.2;
    int N=10;
    matrix* x0=matrix_from_vec(2,1,(float[]){2,3});
    matrix* x=NULL;
    x=grad_descent_min_mat(func,func,x0,alpha,N);
    matrix_delete(x0);
    return 0;
}
