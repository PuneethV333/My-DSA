//implementation of stack using a structure
#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
  int *s;
  int top;
  int size;
}stack_t;

int push(stack_t *ptr,int data){
    if(ptr->top == ptr->size - 1){
        printf("stack is full\n");
        return -1;
    }
    (ptr->s)[++(ptr->top)] = data;
    return 1;
}

int pop(stack_t* ptr){
    if(ptr->top == - 1){
        printf("Stack is empty\n");
        return -1;
    }
    return ((ptr->s)[(ptr->top)--]);
}

void display(stack_t* ptr){
    if (ptr->top == - 1){
          printf("Stack is empty\n");
          return;
    }
    for (int i = ptr->top; i >= 0; i++){
        printf("%d\n",ptr->s[i]);
    }
}

void init(stack_t* ptr){
    ptr->top = -1;
}

int main()
{
  int top,size,ch,k,x;
  stack_t stk;
  init(&stk);
  while(1)
  {
    display(&stk);
    printf("\n1..push\n");
    printf("2..pop\n");
    printf("3..display\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("Enter the data\n");
             scanf("%d",&x);
             k=push(&stk,x);
             if(k>0)
               printf("Element pushed successfully\n");
             break;
     case 2:k=pop(&stk);
            if(k>0)
               printf("Element popped=%d",k);
            break;
     case 3:display(&stk);
            break;
     case 4:exit(0);
   }
 }
}
