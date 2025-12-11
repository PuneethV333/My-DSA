#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node_t;

typedef struct{
    node_t* top;
}stack_t;

void push(stack_t* st,int x){
    node_t* temp = malloc(sizeof(node_t));
    if(temp == NULL){
        printf("something went wrong\n");
    }
    temp->data = x;
    temp->next = st->top;
    st->top = temp;
}

int pop(stack_t* st){
    if(st->top == NULL){
        printf("Stack is empty\n");
        return -1;
    }
    node_t* temp = st->top;
    int res = temp->data;
    st->top = temp->next;
    free(temp);
    return res;
}

int peek(stack_t* st){
    if(st->top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return st->top->data;
}


void display(stack_t* st){
    if(st->top == NULL){
        printf("Stack is empty\n");
        return;
    }
    node_t* temp = st->top;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int isEmpty(stack_t* st){
    return (st->top == NULL);
}
