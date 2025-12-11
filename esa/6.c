#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int *arr;
    int top;
    int size;
}stack_t;


void init(stack_t* st){
    printf("Enter the number of elem.. : ");
    scanf("%d",&(st->size));
    st->arr =  malloc(sizeof(int)*(st->size));
    st->top = -1;
}

void push(stack_t* st,int x){
    if(st->top == st->size - 1){
        printf("Stack is full\n");
        return;
    }
    st->arr[++(st->top)] = x;
}


int pop(stack_t* st){
    if(st->top == -1){
        printf("Stack is empty\n");
        return -1;
    }
    return (st->arr[(st->top)--]);
}


int peek(stack_t* st){
    if(st->top == -1){
        printf("Stack is empty\n");
        return;
    }
    return (st->arr[st->top]);
}

void display(stack_t* st){
    if(st->top == -1){
        printf("Stack is empty\n");
        return;
    }
    for(int i = st->top;i >= 0; i--){
        printf("%d\n",(st->arr)[i]);
    }
}


int isEmpty(stack_t* st){
    return (st->top == -1);
}

int isFull(stack_t* st){
    return (st->top == st->size -1);
}

void sort(stack_t* st){
    stack_t temp;
    init(&temp);
    while(!isEmpty(st)){
        int  x = pop(st);
        while(!isEmpty(&temp) && temp.arr[temp.top] > x)
        {
            push(st,pop(&temp));
        }
        push(&temp,x);
    }    

    while(!isEmpty(&temp)){
        push(st,pop(&temp));
    }

}

void insertSort(stack_t* st,int x){
    if(!isEmpty(st) || st->arr[st->top] <= x){
        push(st,x);
        return;
    }

    int temp = pop(st);
    insertSort(st,x);
    push(st,temp);
}

void sortRes(stack_t* st){
    if(!isEmpty(st)){
        int x = pop(st);
        sortRes(st);
        insertSort(st,x);
    }
}
