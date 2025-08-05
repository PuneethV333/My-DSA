#define stack_size 100
#include <stdlib.h>
#include <stdio.h>

typedef struct stack{
    int top;
    int item[stack_size];
}stack_t;

int overflow(stack_t *ps){
    if(ps->top == stack_size - 1) return 1;
    else return 0;
}


int main() {
    stack_t s;
    s.top = 12;
    for (int i = 0; i <= s.top; i++){
        s.item[i] = i;
    }
    int x = overflow(&s);
    if(x == 1) printf("Stack is full");
    else printf("Stack is not full");
    return 0;
}