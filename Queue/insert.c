#include <stdio.h>
#include <stdlib.h>

typedef struct QUEUE{
    int* item;
    int f;
    int r;
    int size;
}queue_t;


int insert(queue_t* ptr,int data){
    if(ptr->r == ptr->size - 1){
        printf("Queue is full\n");
        return -1;
    }
    ptr->item[(ptr->r)++] = data;
    if(ptr->f == -1){
        (ptr->f) = 0;
    }
    return 1;
}



