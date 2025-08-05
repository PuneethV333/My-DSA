#define stack_size 100
#include <stdlib.h>
#include <stdio.h>

typedef struct stack{
    int top;
    int item[stack_size];
}stack_t;

void push(stack_t *ps,int x){
    if(ps->top == stack_size-1){
        printf("Stack is full");
    }else{
        ++(ps->top);
        ps->item[ps->top] = x;
    }
}


int main() {
    stack_t s;
    s.top = 12;
    for (int i = 0; i <= s.top; i++){
        s.item[i] = i;
    }
    int x;
    printf("Enter the value : ");
    scanf("%d",&x);
    push(&s,x);
    printf("%d\t%d",s.top,s.item[s.top]);
    return 0;
}