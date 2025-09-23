#include<stdlib.h>
#include<stdio.h>
struct queue
{
	int *cq;
	int f,r,size;
};

typedef struct queue queue_t;

void init(queue_t* q){
    printf("Enter the size of queue : ");
    scanf("%d",&(q->size));
    q->f = q->r = -1;
    q->cq = malloc(sizeof(int)*(q->size));
}

int qinsert(queue_t* q,int data){
    if((q->r+1)%q->size == q->f){
        printf("Queue is full\n");
        return -1;
    }
    q->r = (q->r + 1)%q->size;
    q->cq[q->r] = data;
    if (q->f == -1){
        q->f = 0;
    }
    return 1;    
}

int qdelete(queue_t* q){
    if (q->f == -1){
        printf("Empty queue\n");
        return -1;
    }
    int res = q->cq[q->f];
    if(q->f == q->r){
        q->f = q->r = -1;
    }else{
        q->f = (q->f+1)%q->size;
    }
    return res;   
}

void display(queue_t* q){
    if(q->f == -1){
        printf("Queue is empty\n");
        return;
    }
    int f = q->f;
    int r = q->r;
    int size = q->size;
    while (f != r){
        printf("%d\n",q->cq[f]);
        f = (f+1)%size;
    }
    printf("%d\n",q->cq[f]);   
}

int qisempty(queue_t* q){
    return (q->f == -1);
}

int josephus(int p,int n){
    int i,k = 0;
    queue_t q;
    init(&q);
    for (i = 1; i <= p; i++){
        qinsert(&q,i);
    }

    while (!qisempty(&q)){
        for ( i = 1; i < n; i++){
            k = qdelete(&q);
            qinsert(&q,k);
        }
        k = qdelete(&q);
        
    }
    
    return k;
    
}

int main(){
   int ch,k,x;
   queue_t q;
   init(&q);
  while(1)
  {
    display(&q);
    printf("\n1..Insert");
    printf("\n2..Delete");
    printf("\n3..Display");
    printf("\n4..EXIT");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:printf("Enter the value..");
              scanf("%d",&x);
              k=qinsert(&q,x);
              if(k>=0)
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
