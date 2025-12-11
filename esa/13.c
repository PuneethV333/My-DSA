#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    int pty;
    struct node* next;
}node_t;

typedef struct{
    node_t* head;
}pqueue_t;

void enqueue(pqueue_t* pq,int x,int pty){
    node_t* temp = malloc(sizeof(node_t));
    temp->data = x;
    temp->next = NULL;
    temp->pty = pty;
    if(pq->head == NULL || temp->pty > pq->head->pty){
        temp->next = pq->head;
        pq->head = temp;
        return;
    }
    node_t* pres = pq->head;
    while(pres->next == NULL && pres->next->pty <= pty){
        pres = pres->next;
    }

    temp->next = pres->next;
    pres->next = temp;
}


void dequeue(pqueue_t* pq){
    if(pq->head == NULL){
        printf("Empty\n");
        return;
    }

    node_t* temp = pq->head;
    pq->head = temp->next;
    free(temp);
}