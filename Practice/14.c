#include <stdlib.h>
#include <stdio.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node_t;
struct queue
{
    node_t *front;
    node_t *rear;
};
typedef struct queue queue_t;

void qinsert(int data, queue_t *ptr){
    node_t* temp = malloc(sizeof(node_t));
    temp->data = data;
    temp->next = NULL;

    if (ptr->front == NULL){
        ptr->front = ptr->rear = temp;
    }else{
        ptr->rear->next = temp;
        ptr->rear = temp;
    }
}

int qdelete(queue_t *ptr){
    if (ptr->front == NULL){
        printf("Queue is Empty");
        return -1;
    }
    node_t* pres = ptr->front;
    int x = pres->data;
    if (ptr->front == ptr->rear){
        ptr->front = ptr->rear = NULL;
    }else{
        ptr->front = pres->next;
    }
    free(pres);
    return x;
}

void qdisplay(queue_t *ptr){
    if (ptr->front == NULL){
        printf("Queue is empty\n");
        return;
    }
    node_t* pres = ptr->front;
    while (pres != ptr->rear){
        printf("%d\n",pres->data);
        pres = pres->next;
    }
    printf("%d\n",pres->data);   
}

void init(queue_t *ptr){
    ptr->front = ptr->rear = NULL;
}

int main()
{
    int k, x, ch;

    queue_t q;
    init(&q);

    while (1)
    {
        qdisplay(&q);
        printf("\n1..insert");
        printf("\n2..remove");
        printf("\n3..display");
        printf("\n4..EXIT");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value..");
            scanf("%d", &x);
            qinsert(x, &q);

            break;
        case 2:
            k = qdelete(&q);
            if (k >= 0)
                printf("The element deleted = %d\n", k);
            break;
        case 4:
            exit(0);
        }
    }
}