
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *item;
    int size,f,r;
}queue_t;


void init(queue_t* q){
    printf("Entre the size :");
    scanf("%d",&(q->size));
    q->item  = malloc(sizeof(int)*q->size);
    q->f = q->r = -1;
}

void enqueue(queue_t* q,int x){
    if(q->r == q->size-1){
        printf("Overflow\n");
        return;
    }
    if(q->f == -1){
        q->f = 0;
    }
    q->item[++(q->r)] = x;
}

void dequeue(queue_t* q){
    if(q->f == -1 || q->f>q->r){
        printf("No elem...");
        return;
    }
    if(q->f == q->r){
        q->f = q->r = -1;
    }else{
        (q->f)++;
    }
}


void display(queue_t* q){
    if(q->f == -1 || q->f > q->r){
        printf("Queue is empty\n");
        return;
    }
    for(int i = q->f;i <= q->r;i++){
        printf("%d ",(q->item)[i]);
    }
    printf("\n");
}