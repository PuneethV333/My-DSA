//implementation of stack uisng an array
#include<stdio.h>
#include<stdlib.h>
int push(int* arr,int* top,int size,int data){
    if(*top == size-1){
        printf("Stack is full\n");
        return -1;
    }
    arr[++(*top)] = data;
    return 1;
}

int pop(int* arr,int* top){
    if (*top == -1){
        printf("Stack is empty\n");
        return -1;
    }
    int res = arr[(*top)--];
    return res;
}

void display(int* arr,int top){
    if(top == -1){
        printf("stack is empty\n");
        return;
    }
    for (int i = top; i >= 0; i++){
        printf("%d\n",arr[i]);
    } 
}



int main()
{
  int top,size,ch,k,x;
  int *s;
  printf("Enter the size of the stack..\n");
  scanf("%d",&size);
  s=malloc(sizeof(int)*size);
  top=-1;
  while(1)
  {
    display(s,top);
    printf("\n1..push\n");
    printf("2..pop\n");
    printf("3..display\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("Enter the data\n");
             scanf("%d",&x);
             k=push(s,&top,size,x);
             if(k>0)
               printf("Element pushed successfully\n");
             break;
     case 2:k=pop(s,&top);
            if(k>0)
               printf("\nElement popped=%d\n",k);
            break;
     case 3:display(s,top);
            break;
     case 4:exit(0);
   }
 }
}
