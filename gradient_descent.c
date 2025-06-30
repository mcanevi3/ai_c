#include <stdio.h>
#include <stdlib.h>

#include "gradient_descent.h"

float grad_descent_min(func_scalar fun,func_scalar grad,float x0,float alpha,int N){
    float x=x0;
    for(int i=1;i<=N;i++)
    {
        x=x-alpha*grad(x);
        if(DEBUG)printf("%d: %f\n",i,x);
    }
    return x;
}

float grad_descent_max(func_scalar fun,func_scalar grad,float x0,float alpha,int N){
    return grad_descent_min(fun,grad,x0,-alpha,N);
}