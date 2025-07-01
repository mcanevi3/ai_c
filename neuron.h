#ifndef NEURON_H
#define NEURON_H

struct _smatrix;

struct _neuron {
	struct _smatrix weight;
	struct _smatrix bias;
};
typedef struct _neuron neuron;

neuron neuron_new(struct _smatrix,struct _smatrix);
void neuron_print(neuron);
void neuron_delete(neuron*);

#endif