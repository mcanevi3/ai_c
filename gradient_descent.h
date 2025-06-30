#ifndef GRADIENT_DESCENT_H
#define GRADIENT_DESCENT_H

#define DEBUG 0

typedef float (*func_scalar)(float);
float grad_descent_min(func_scalar fun,func_scalar grad,float x0,float alpha,int N);
float grad_descent_max(func_scalar fun,func_scalar grad,float x0,float alpha,int N);

#endif