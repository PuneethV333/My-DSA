#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int size;
}tree_t;

void postorder(tree_t* t,int i){
    if((t->data)[i] != -1){
        postorder(t,2*i+1);
        postorder(t,2*i+2);
        printf("%d ",(t->data)[i]);
    }
}


void preorder(tree_t* t,int i){
    if((t->data)[i] != -1){
        printf("%d ",(t->data)[i]);
        preorder(t,2*i+1);
        preorder(t,2*i+2);
    }
}


void inorder(tree_t* t,int i){
    if((t->data)[i] != -1){
        inorder(t,2*i+1);
        printf("%d ",(t->data)[i]);
        inorder(t,2*i+2);
    }
}

