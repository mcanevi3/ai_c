#include <stdio.h>
#include <stdlib.h>

#include "gradient_descent.h"
#include "smatrix.h"


smatrix func(smatrix x){
    smatrix A=smatrix_from_vec(2,2,(float[]){2,1,1,3});
    smatrix b=smatrix_from_vec(2,1,(float[]){-1,-2});
    
    smatrix xnew=smatrix_multiply(A,x);
    xnew=smatrix_add(xnew,b);
    
    xnew=smatrix_multiply(smatrix_transpose(xnew),xnew);
    xnew=smatrix_multiply_scalar(xnew,0.5f);

    smatrix_delete(&A);
    smatrix_delete(&b);
    return xnew;
}

smatrix grad(smatrix x){
    smatrix A=smatrix_from_vec(2,2,(float[]){2,1,1,3});
    smatrix b=smatrix_from_vec(2,1,(float[]){-1,-2});

    smatrix xnew=smatrix_multiply(A,x);
    xnew=smatrix_add(xnew,b);
    xnew=smatrix_multiply(smatrix_transpose(A),xnew);
    return xnew;
}

int main()
{
    smatrix x;

    smatrix A=smatrix_from_vec(2,2,(float[]){2,1,1,3});
    smatrix b=smatrix_from_vec(2,1,(float[]){-1,-2});
    x=smatrix_inverse(smatrix_multiply(smatrix_transpose(A),A));
    x=smatrix_multiply_scalar(x,-1);
    x=smatrix_multiply(x,smatrix_transpose(A));
    x=smatrix_multiply(x,b);
    smatrix_print(x);

    smatrix_delete(&b);
    smatrix_delete(&A);

    float alpha=0.05;
    int N=100;
    smatrix x0=smatrix_from_vec(2,1,(float[]){0,0});

    x=grad_descent_min_mat(func,grad,x0,alpha,N);
    smatrix_print(x);

    smatrix_delete(&x);
    smatrix_delete(&x0);
    return 0;
}
