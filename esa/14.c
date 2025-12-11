#include <stdio.h>
#include <stdlib.h>

//(r+1)%size == front ->full
// front == -1 -> empty

typedef struct {
    int* item;
    int size,r,f;
}cqueue_t;

void init(cqueue_t* q){
    printf("Enter the size : ");
    scanf("%d",&(q->size));
    q->item = malloc(sizeof(int)*(q->size));
    q->f = q->r = -1;
}


void enqueue(cqueue_t* q,int x){
    if((q->r + 1)%q->size == q->f){
        printf("Queue is full\n");
        return;
    }

    if(q->f == -1){
        q->f = q->r = 0;
    }else{
        q->r = (q->r + 1)%q->size;
    }

    q->item[q->r] = x;
}


void dequeue(cqueue_t* q){
    if(q->f == -1){
        printf("Empty\n");
        return;
    }

    if(q->f == q->r){
        q->f = q->r = -1;
    }else{
        q->f = (q->f + 1)%q->size;
    }
}

void display(cqueue_t* q){
    if((q->r + 1)%q->size == q->f){
        printf("Emty\n");
        return;
    }

    int i = q->f;
    while(1){
        printf("%d ",q->item[i]);
        if(i == q->r){
            break;
        }
        i = (i+1)%q->size;
    }
    printf("\n");
}


int josephus(cqueue_t* q,int k){
    int arr[q->size];
    for(int i = 0;i < q->size;i++){
        arr[i] = 1;
    }
    int alive = q->size;
    int count = 0;
    int i = 0;
    while(alive > 1){
        if(arr[i] == 1){
            count++;
            if(count == k){
                arr[i] = 0;
                alive--;
                count = 0;
            }
        }
        i = (i+1)%(q->size);
    }
    for(i = 0; i<q->size;i++){
        if(arr[i] == 1){
            return i+1;
        }
    }
    return -1;
    
}