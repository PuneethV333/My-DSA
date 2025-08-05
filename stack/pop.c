#define stack_size 100
#include <stdlib.h>
#include <stdio.h>

typedef struct stack{
    int top;
    int item[stack_size];
}stack_t;

int pop(stack_t *ps){
    if(ps->top == -1){
        printf("Stack is empty\n");
        return -1;
    }else{
        int x = ps->item[ps->top];
        --(ps->top);
        return x;
    }
}


int main() {
    stack_t s;
    s.top = 12;
    for (int i = 0; i <= s.top; i++){
        s.item[i] = i;
    }
    int x = pop(&s);
    printf("%d",x);
    return 0;
}