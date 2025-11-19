#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *data;
    int size;
}tree_t;


// todo: traversal

void preorder(int *data,int i){
    if(data[i] != -1){
        printf("%d\n",data[i]);
        preorder(data,2*i+1);
        preorder(data,2*i+2);
    }
}


void postorder(int *data,int i){
    if(data[i] != -1){
        postorder(data,2*i+1);
        postorder(data,2*i+2);
        printf("%d\n",data[i]);
}}



void inorder(int *data,int i){
    if(data[i] != -1){
        inorder(data,2*i+1);
        printf("%d\n",data[i]);
        inorder(data,2*i+2);
}}


void insert(tree_t* data,int key){
    int i = 0;
    while (data->data[i] != -1)
    {
        if(key > data->data[i]){
            i = 2*i + 2;
        }else{
            i = 2*i + 1;
        }
    }
    data->data[i] = key;
}

int max(int *root){
    int i = 0;
    if(root[i] == -1){
        printf("Tree is empty\n");
        return -1;
    }
    while (root[2*i+2] != -1){
        i = 2*i + 2;
    }
    return root[i];    
}



int min(int *root){
    int i = 0;
    if(root[i] == -1){
        printf("Tree is empty\n");
        return -1;
    }
    while (root[2*i + 1] != -1){
        i = 2*i+1;
    }
    return root[i];
}

void delete(tree_t *t,int key){

    int i = 0;
    int *root = t->data;
    int size = t->size;
    if(root[i] == -1){
        printf("tree is empty\n");
        return;
    }

    //search for key
    while (i <  size && root[i] != key && root[i] != -1){
        if(key > root[i]){
            i = 2*i + 2;
        }else{
            i= 2*i+1;
        }
    }
    // key not found
    if(i >= size || root[i] == -1){
        printf("Data is not in tree");
        return;
    }

    int left = 2*i+1;
    int right = 2*i+2;
    if((root[left] == -1 || left >= size) && (root[right] == -1 || right >= size)){
        root[i] = -1;
    }
    else if ((left >= size || (root[left] == -1))){
        root[i] = root[right];
        delete(t,root[right]);
    }
    else if (right >= size || root[right] == -1){
        root[i] = root[left];
        delete(t,root[left]);
    }else{
        int succ = right;
        while (2*succ + 1 < size && root[2*succ + 1] != -1){
            succ = 2*succ + 1;
        }
        root[i] = root[succ];
        delete(t,root[succ]);
        
    }
        
}


int hight(int* root,int i){
    int l,r;
    if(root[i]==-1){
        return -1;
    }if((root[2*i+1] == -1) && (root[2*i +2] == -1)){
        return 0;
    }
    l = hight(root,2*i+1);
    r = hight(root,2*i+2);
    if(l>r){
        return l+1;
    }return r+1;    
}

int leafNode(int* root,int i){
    int l,r;
    if(root[i] == -1){
        return 0;
    }
    if(root[2*i+1] == -1 && root[2*i + 2] == -1){
        return  1;
    }
    l = leafNode(root,2*i+1);
    r = leafNode(root,2*i+2);
    return l+r;
}