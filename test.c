#include <stdio.h>
#include <stdlib.h>

#include "gradient_descent.h"

float func(float x){
    return x*x-4*x+5;
}
float grad(float x){
    return 2*x-4;
}

int main()
{
    float x0=4;
    float alpha=0.2;
    int N=10;
    printf("0: %f\n",x0);   
    printf("result:%f\n",grad_descent_min(func,grad,x0,alpha,N)); 

    return 0;
}