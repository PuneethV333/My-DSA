#include <stdio.h>
#include <stdlib.h>
typedef struct NODE{
    int data;
    struct NODE* left; 
    struct NODE* right; 
}tnode_t;

typedef struct Tree{
    tnode_t* root;
}tree_t ;



void insert(tree_t* t,int data){
    tnode_t* temp = malloc(sizeof(tnode_t));
    temp->data = data;
    temp->left = temp->right = NULL;
    if(t->root == NULL){
        t->root = temp;
        return;
    }
    tnode_t *prev = NULL;
    tnode_t *crr = t->root;
    while (crr != NULL){
        prev = crr;
        if (crr->data > data){
            crr = crr->left;
        }else{
            crr = crr->right;
        }
    }

    if(data > prev->data){
        prev->right = temp;
    }else{
        prev->left = temp;
    }
}

void preorder(tnode_t* t){
    if (t != NULL){
        printf("%d\n",t->data);
        preorder(t->left);
        preorder(t->right);
    }
}
void inorder(tnode_t* t){
    if (t != NULL){
        inorder(t->left);
        printf("%d\n",t->data);
        inorder(t->right);
    }
}
void postorder(tnode_t* t){
    if (t != NULL){
        postorder(t->left);
        postorder(t->right);
        printf("%d\n",t->data);
    }
}

