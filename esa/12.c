#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int data;
    int pty;
}elem_t;

typedef struct{
    elem_t item[MAX];
    int size;
}pqueue_t;


void enqueue(pqueue_t* pq,int x,int pty){
    if(pq->size == MAX){
        printf("OverFlow\n");
        return;
    }
    int i = pq->size -1;
    elem_t temp;
    temp.data = x;
    temp.pty = pty;

    for(i;i>=0 && (pq->item)[i].pty > temp.pty;i--){
        (pq->item)[i+1] = (pq->item)[i];
    }
    pq->item[i+1] = temp;
    pq->size++;
}


void dqueue(pqueue_t* pq){
    if(pq->size == 0){
        printf("Empty\n");
        return;
    }
    for(int i = 0;i <pq->size;i++){
        pq->item[i] = pq->item[i+1];
    }
    pq->size--;
}
