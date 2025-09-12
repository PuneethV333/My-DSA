#include <stdio.h>
#include <stdlib.h>

typedef struct QUEUE{
    int* item;
    int f;
    int r;
    int size;
}queue_t;


void display(queue_t* q){
    if(q->f == -1){
        printf("Empty\n");
        return;
    }
    for (int i = q->f; i <= q->r; i++){
        printf("%d\n",q->item[i]);
    }   
}



