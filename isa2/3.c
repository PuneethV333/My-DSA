#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node{
    char data;
    struct node* left;
    struct node* right;
}node_t;


typedef struct{
    node_t* root;
}tree_t;



int isOper(char ch){
    switch(ch){
        case '+' :
        case '-' :
        case '/' :
        case '*' :
            return 1;
        default:
            return 0;
    }
}


void push(node_t** stack,int *top,node_t* temp){
    stack[++(*top)] = temp;
}

node_t* pop(node_t** stack,int * top){
    return stack[(*top)--];
}

void createExpTree(tree_t *t,char *exp){
    node_t* stack[100];
    int top = -1;
    char ch;
    int i = 0;
    while (exp[i] != '\0'){
        ch = exp[i];

        if(ch == ' ' || ch == '\n'){
            i++;
            continue;
        }
        node_t * temp = malloc(sizeof(node_t));
        temp->data = ch;
        temp->left = temp->right = NULL;
        if(isOper(ch)){
            temp->right = pop(stack,&top);
            temp->left = pop(stack,&top);
        }
            push(stack,&top,temp);
        i++;
    }
    t->root = pop(stack,&top); 
}

int eval(node_t* root){
    if(root == NULL) return 0;
    if(isdigit(root->data)){
        return root->data - '0';
    }

    int left = eval(root->left);
    int right = eval(root->right);

    switch(root->data){
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left*right;
        case '/':
            return left/right;
            
    }
    return 0;
}