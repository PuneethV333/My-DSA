#include <stdlib.h>
#include <stdio.h>


typedef struct node{
    int data;
    struct node* left; 
    struct node* right; 
}node_t;


typedef struct {
    node_t* root;
}tree_t;


void init(tree_t *t){
    t->root = NULL;
}

void insert(tree_t* t,int key){
    node_t *temp = malloc(sizeof(node_t));
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    
    if(t->root == NULL){
        t->root = temp;
    }else{
        node_t *crr = t->root;
        node_t* prev = NULL;
        while (crr != NULL){
            prev = crr;
            if(key > crr->data){
                crr = crr->right;
            }else{
                crr = crr->left;
            }
        }
        if(key > prev->data){
            prev->right = temp;
        }else{
            prev->left = temp;
        }
    }

}



void preorder(node_t* root){
    if(root != NULL){
        printf("%d\n",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(node_t* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\n",root->data);
    }
}

void inorder(node_t* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d\n",root->data);
        inorder(root->right);
    }
}

int min(node_t* root){
    if(root == NULL){
        printf("Tree is empty\n");
        return -1;
    }
    node_t* temp = root;
    while (temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;    
}

int max(node_t* root){
    if(root == NULL){
        printf("Tree is empty\n");
        return -1;
    }   
    node_t* temp = root;
    while (temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;    
}


node_t* rinsert(node_t* root,int key){
    if(root == NULL){
        node_t* temp = malloc(sizeof(node_t));
        temp->data = key;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    if(key> root->data){
        root->right = rinsert(root->right,key);
    }else{
        root->left = rinsert(root->left,key);
    }
    return root;
}

void delete(tree_t* t,int key){
    node_t* crr = t->root;
    node_t* prev = NULL;
    node_t* q = NULL;

    
    while (crr != NULL && crr->data != key){
        prev = crr;   

        if(key > crr->data)
            crr = crr->right;
        else
            crr = crr->left;
    }

    
    if(crr == NULL){
        printf("Key not found\n");
        return;
    }

    
    
    
    if(crr->left == NULL || crr->right == NULL){
        if(crr->left == NULL)
            q = crr->right;
        else
            q = crr->left;

        
        if(prev == NULL){
            t->root = q;
        }
        else if(crr == prev->left){
            prev->left = q;
        }else{
            prev->right = q;
        }

        free(crr);
        return;
    }

    
    
    
    else{
        node_t* temp = crr->right;
        node_t* p = NULL;

        
        while(temp->left != NULL){
            p = temp;
            temp = temp->left;
        }

        
        crr->data = temp->data;

        
        if(p != NULL)
            p->left = temp->right;
        else
            crr->right = temp->right;

        free(temp);
    }
}


void iteravtiveInorder(node_t* root){ 
    node_t* stack[100];
    int top = -1;
    node_t* crr = root;

    while (crr != NULL && top != -1){
        while (crr != NULL){
            stack[++top] = crr;
            crr = crr->left;
        }
        crr = stack[top--];
        printf("%d\n",crr->data);
        crr = crr->right;
    }
}

void iterativePreorder(node_t* root){
    if(root == NULL){
        return;
    }

    node_t *stack[100];
    int top = -1;
    stack[++top] = root;

    while (top != -1){
        node_t* crr  = stack[top--];
        printf("%d\n",crr->data);
        if(crr->right){
            stack[++top] = crr->right;
        } 
        if(crr->left){
            stack[++top] = crr->left;
        }
    }
    
}



void iterativePostOrder(node_t* root){
    if(root == NULL) return;

    node_t *stack1[100];
    node_t *stack2[100];
    int top1 = -1;
    int top2 = -1;

    stack1[++top1] = root;

    while (top1!= -1){
        node_t * crr  = root;
        stack2[++top2] = crr;
        if(crr->left){
            stack1[++top1] = crr->left;
        }    
        if(crr->right){
            stack1[++top1] = crr->right;
        }
    }

    while (top2 != -1){
        printf("%d\n",stack2[--top2]->data);
    }
}

