#define stack_size 100
#include <stdlib.h>
#include <stdio.h>

typedef struct stack{
    int top;
    int item[stack_size];
}stack_t;

void display(stack_t *s){
    if(s->top == -1){
        printf("Stack is empty\n");
    }else{
        printf("Elements in stacks are : \n");
        for (int i = 0; i <= s->top; i++){
            printf("%d. %d\n",i+1,s->item[i]);
        }        
    }
}


int main() {
    stack_t s;
    s.top = 12;
    for (int i = 0; i <= s.top; i++){
        s.item[i] = i;
    }
    display(&s);
    
    return 0;
}