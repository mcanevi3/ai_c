#include <stdio.h>
#include <stdlib.h>

struct _node{
    void* data;
    struct _node* next;
};
typedef struct _node node;

node node_new(void* data);
void node_delete(node*);

node node_new(void* data){
    node n={.data=NULL,.next=NULL};
    n.data=data;
    n.next=NULL;
    return n;
}
void node_delete(node* n){
    if(n)
    {
        
    }
}

int main(){

    return 0;
}