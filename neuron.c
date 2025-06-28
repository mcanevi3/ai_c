#include <stdio.h>
#include "neuron.h"

neuron new_neuron(float weight,float bias){
	neuron n={.weight=weight,.bias=bias};
	return n;
}

void print_neuron(neuron n){
	printf("Neuron weight:%f bias:%f\n",n.weight,n.bias);
}

