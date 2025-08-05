#define stack_size 100
#include <stdlib.h>
#include <stdio.h>

typedef struct stack{
    int top;
    int item[stack_size];
}stack_t;

int empty(stack_t *ps){
    if(ps->top == -1){
        return 1;
    }else{
        return 0;
    }
}


int main() {
    stack_t s;
    s.top = 12;
    for (int i = 0; i <= s.top; i++){
        s.item[i] = i;
    }
    int x = empty(&s);
    if(x == 1){
        printf("stack is empty");
    }else{
        printf("stack is not empty");
    }
    return 0;
}