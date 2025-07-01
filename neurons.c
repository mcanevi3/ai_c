#include <stdio.h>
#include <stdlib.h>

#include "smatrix.h"
#include "neuron.h"

int main(){

    neuron n1=neuron_new(smatrix_from_vec(2,1,(float[]){3,4}),smatrix_from_vec(2,1,(float[]){1,2}));
    neuron_print(n1);

    neuron_delete(&n1);
    return 0;
}