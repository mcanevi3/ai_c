#ifndef NEURON_H
#define NEURON_H

struct _neuron {
	float weight;
	float bias;
};
typedef struct _neuron neuron;

neuron new_neuron(float,float);
void print_neuron(neuron);

#endif
