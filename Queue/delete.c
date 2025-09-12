#include <stdio.h>
#include <stdlib.h>

typedef struct QUEUE{
    int* item;
    int f;
    int r;
    int size;
}queue_t;


int delete(queue_t* q){
    // delete at end
    if(q->f == -1){
        printf("Empty Queue\n");
        return -1;
    }
    int x = q->item[q->f];
    if(q->f == q->r){
        q->f = q->r = -1;
    }else{
        (q->f)++;
    }
    return x;
}



