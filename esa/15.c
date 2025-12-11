#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node_t;

typedef struct
{
    node_t *r;
    node_t *f;
} cqueue_t;

void init(cqueue_t *q)
{
    q->r = NULL;
    q->f = NULL;
}

void enqueue(cqueue_t *q, int x)
{
    node_t *temp = malloc(sizeof(node_t));
    temp->data = x;
    temp->next = NULL;
    if (q->r == NULL || q->f == NULL)
    {
        temp->next = temp;
        q->r = temp;
        q->f = temp;
    }
    else
    {
        temp->next = q->f;
        q->r->next = temp;
        q->r = temp;
    }
}

void dequeue(cqueue_t *q)
{
    if (q->r == NULL)
    {
        printf("Empty\n");
        return;
    }
    node_t *temp = q->f;

    if (q->f == q->r)
    {
        free(temp);
        q->r = NULL;
        q->f = NULL;
    }
    else
    {
        q->f = q->f->next;
        q->r->next = q->f;
        free(temp);
    }
}


void display(cqueue_t* q){
    if(q->r == NULL || q->f == NULL){
        printf("Empty\n");
        return;
    }

    node_t* temp = q->f;

    do{
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp != q->f);
    printf("\n");
}

int josephus(cqueue_t* q,int k){
    node_t* pres = q->f;
    node_t* prev = NULL;

    while(pres->next != pres){
        for(int i = 1;i < k;i++){
            prev = pres;
            pres = pres->next;
        }

        prev->next = pres->next;
        free(pres);
        pres = prev->next;
    }
    return pres->data;
}