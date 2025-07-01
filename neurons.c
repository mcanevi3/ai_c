#include <stdio.h>
#include <stdlib.h>

#include "smatrix.h"
#include "neuron.h"

struct _layer{
    neuron* children;
    int count;
    int N;
};
typedef struct _layer layer;

layer layer_new(int,int);
void layer_delete(layer*);
void layer_print(layer);

layer layer_new(int count,int N){
    layer l={.count=count,.N=N};
    l.children=malloc(count*sizeof(neuron));
    for(int i=0;i<count;i++){
        l.children[i]=neuron_new(smatrix_zeros(N,N),smatrix_zeros(N,1));
    }
    return l;
}
void layer_delete(layer* l){
    if(l->children)
    {
        for(int i=0;i<l->count;i++){
            neuron_delete(&l->children[i]);
        }
    }
    free(l->children);
}

void layer_print(layer l){
    if(l.children)
    {
        for(int i=0;i<l.count;i++){
            printf("[%d] ",i);
            neuron_print(l.children[i]);
        }
    }
}

int main(){
    layer layer1=layer_new(2,3);
    layer_print(layer1);
    layer_delete(&layer1);
    return 0;
}