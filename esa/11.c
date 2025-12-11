#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node_t;

typedef struct{
    node_t* front;
    node_t* rare;
}queue_t;


void init(queue_t* q){
    q->rare = q->front = NULL;
}

void enqueue(queue_t* q,int x){
    node_t* temp = malloc(sizeof(node_t));
    if(temp == NULL){
        printf("Something went wrong\n");
        return;
    }

    temp->data = x;
    temp->next = NULL;
    if(q->rare == NULL){
        q->front = q->rare = temp;
        return;
    }
    q->rare->next = temp;
    q->rare = temp;
}

void dequeue(queue_t* q){
    if(q->front == NULL){
        printf("Queue is empty\n");
        return;
    }

    node_t* temp = q->front;
    q->front = q->front->next;
    if(q->front == NULL){
        q->rare = NULL;
    }
    free(temp);
}

