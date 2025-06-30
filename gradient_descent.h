#ifndef GRADIENT_DESCENT_H
#define GRADIENT_DESCENT_H

#define DEBUG 0

typedef float (*func_scalar)(float);
float grad_descent_min(func_scalar fun,func_scalar grad,float x0,float alpha,int N);
float grad_descent_max(func_scalar fun,func_scalar grad,float x0,float alpha,int N);

struct _smatrix;
typedef struct _smatrix (*func_mat)(struct _smatrix);
struct _smatrix grad_descent_min_mat(func_mat fun,func_mat grad,struct _smatrix x0,float alpha,int N);
#endif
