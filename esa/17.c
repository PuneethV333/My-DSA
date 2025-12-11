#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node* next;
}node_t;


typedef struct{
    node_t* f;
    node_t* r;
}dqueue_t;


void init(dqueue_t* q){
    q->f = q->r = NULL;
}


void insertFront(dqueue_t* q,int x){
    node_t* temp = malloc(sizeof(node_t));
    temp->data = x;
    temp->next = NULL;


    if(q->f == NULL){
        q->f = q->r = temp;
    }else{
        temp->next = q->f;
        q->f = temp;
    }
}


void insertRare(dqueue_t* q,int x){
    node_t* temp = malloc(sizeof(node_t));
    temp->data = x;
    temp->next = NULL;
    if(q->r == NULL){
        q->r = q->f = temp;
    }else{
        q->r->next = temp;
        q->r = temp;
    }
}


void deleteFront(dqueue_t* q){
    if(q->f == NULL){
        printf("Empy\n");
        return;
    }
    node_t* temp = q->f;

    if(q->f == q->r){
        q->f = q->r = NULL;
    }else{
        q->f = q->f->next;
    }
    free(temp);
}

void deleteRear(dqueue_t* q){
    if(q->r == NULL){
        printf("Empty\n");
        return;
    }

    node_t* temp = q->r;

    if(q->f == q->r){
        q->f = q->r = NULL;
    }else{
        node_t* pres = q->f;
        while(pres->next != q->r){
            pres = pres->next;
        }
        pres->next = NULL;
        q->r = pres;
    }
    free(temp);
}