#include <stdio.h>
#include <stdlib.h>


typedef struct tree{
    int* arr;
}tree_t;


void init(tree_t* t){
    t->arr = malloc(sizeof(int)*100);
    for (int i = 0; i < 100; i++){
        t->arr[i] = -1;
    }
}

void insert(tree_t* t,int x){
    int i = 0;
    for (i = 0; t->arr[i] != -1;){
        if(x < t->arr[i]){
            i = i*2 + 1;
        }else{
            i = i*2 + 2;
        }
    }
    t->arr[i] = x;
}

void postoreder(int* root,int i){
    if(root[i] != 0){
        postoreder(root,(2*i + 1));
        postoreder(root,(2*i + 2));
        printf("%d\n",root[i]);
    }
}

void preorder(int* root,int i){
    if(root[i] != -1){
        printf("%d\n",root[i]);
        preorder(root,2*i + 1);
        preorder(root,2*i + 2);
    }
}

void inorder(int* root,int i){
    if(root[i] != -1){
        inorder(root,2*i + 1);
        printf("%d\n",root[i]);
        inorder(root,2*i+2);
    }
}

int max(int* root){
    int i = 0;
    if(root[i] == -1){
        return -1;
    }
    while(root[2*i + 2] != -1){
        i = 2*i +2;
    }
    return root[i];
}

int min(int* root){
    int i = 0;
    if(root[i] == -1){
        return -1;
    }
    while (root[2*i + 1] != -1){
        i = 2*i + 1;
    }
    return root[i];
}

int height(int* root,int i){
    int r,l;
    if(root[i] == -1){
        return 0;
    }
    if((root[2*i+1] == -1) && (root[2*i+2] == -1)){
        return 1;
    }
    r = height(root,2*i+2);
    l = height(root,2*i+1);
    if(r>l)
        return r+1;
    return l+1;
}

int leafNode(int* root,int i){
    int r,l;
    if(root[i] == -1){
        return 0;
    }
    if((root[2*i+1] == -1) && (root[2*i+2] == -1)){
        return 1;
    }
    r = leafNode(root,2*i+2);
    l = leafNode(root,2*i+1);
    return r+l;
}