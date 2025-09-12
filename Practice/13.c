#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int *item;
	int f,r,size;
};

typedef struct queue  queue_t;


void init(queue_t* ptr){
    printf("Entre the size of queue : ");
    scanf("%d",&(ptr->size));
    ptr->item = malloc(sizeof(int)*(ptr->size));
    ptr->f = ptr->r = -1;
}

int qinsert(queue_t *ptr,int data){
    if (ptr->r = ptr->size -1 ){
        printf("Queue is full\n");
        return 0;
    }
    ptr->item[++(ptr->r)] = data;
    if (ptr->r == -1){
        ptr->r = 0;
    }
    return 1;
}

int qdelete(queue_t* ptr){
    if (ptr->f == -1){
        printf("Queue is empty");
        return 0;
    }
    int x = ptr->item[ptr->f];
    if(x == ptr->item[ptr->r]){
        ptr->f = ptr->r = -1;
    }else{
        ptr->f++;
    }
    return x;
}

void display(queue_t* ptr){
    if (ptr->f == -1){
        printf("Queue is empty\n");
        return;
    }
    
    for (int i = ptr->f; i < ptr->r ; i++)
    {
        printf("%d\n",ptr->item[i]);
    }
    
}

int main()
{
  queue_t q;
  int ch,k,x;
  init(&q);
  while(1)
  {
    display(&q);
    printf("\n1..Insert");
    printf("\n2..Delete");
    printf("\n3..display");
    printf("\n4..EXIT");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:printf("Enter the value..");
              scanf("%d",&x);
              k=qinsert(&q,x);
              if(k>0)
                 printf("Element inserted successfully\n");
               break;
       case 2:k=qdelete(&q);
              if(k>=0)
                printf("element deleted=%d\n",k);
                break;
		case 3:display(&q);
		              break;
        case 4:exit(0); 
   }
  }
 }