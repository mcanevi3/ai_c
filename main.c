#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

struct _neuron {
	float weight;
	float bias;
};
typedef struct _neuron neuron;

neuron new_neuron(float weight,float bias){
	neuron n={.weight=weight,.bias=bias};
	return n;
}

void print_neuron(neuron n){
	printf("Neuron weight:%f bias:%f\n",n.weight,n.bias);
}

struct _node{
	void* data;
	struct _node* next;
};
typedef struct _node node;

node* new_node(void* data){
	node* n=(node*)malloc(sizeof(node));
	n->data=data;
	n->next=NULL;
	return n;	
}

void delete_node(node* n){
	if(n)
	{
		free(n->data);
		free(n);
	}
} 

typedef float (*func)(float);

float test_func(float x)
{
	return x*x;
}


int main(){
	matrix* a=matrix_from_vec(2,2,(float[]){1,2,3,4});
	matrix* b=matrix_from_vec(2,2,(float[]){1,2,3,4});
	matrix* c;
		
	matrix_print(a);
	matrix_print(b);
	c=matrix_multiply(a,b);
	matrix_print(c);
	c=matrix_add_scalar(c,2);
	matrix_print(c);
	
	matrix_delete(a);
	matrix_delete(b);
	matrix_delete(c);
	return 0;

}
