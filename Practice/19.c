#include <stdio.h>
#include <stdlib.h>

#define MAX 100
node_t* stack[MAX];
int top = -1;

typedef struct node {
    int data;
    struct node *left, *right;
} node_t;

void preoreder(node_t* t){
    if (t != NULL){
        printf("%d\n",t->data);
        preoreder(t->left);   
        preoreder(t->right);   
    }
}

void inorder(node_t* t){
    if (t != NULL){
        inorder(t->left);
        printf("%d\n",t->data);
        inorder(t->right);
    }
}


void postorder(node_t* t){
    if (t != NULL){
        postorder(t->left);
        postorder(t->right);
        printf("%d\n",t->data);
    }
}

void push(node_t* n) {
    stack[++top] = n;
}

node_t* pop() {
    return stack[top--];
}

int isEmpty() {
    return (top == -1);
}


void inorder_itr(node_t* t){
    node_t* crr = t;
    while (crr != NULL || !isEmpty()){
        while (crr != NULL){
            push(crr);
            crr = crr->left;
        }
        crr = pop();
        printf("%d ", crr->data);
        crr = crr->right;   
    }    
}
