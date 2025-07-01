#include <stdio.h>
#include "smatrix.h"
#include "neuron.h"

neuron neuron_new(smatrix weight,smatrix bias){
	neuron n;
	n.weight=weight;
	n.bias=bias;
	return n;
}

void neuron_print(neuron n){
	printf("Neuron weight:\n");
	smatrix_print(n.weight);
	printf("bias:\n");
	smatrix_print(n.bias);
}

void neuron_delete(neuron* n){
	smatrix_delete(&n->weight);
	smatrix_delete(&n->bias);
}