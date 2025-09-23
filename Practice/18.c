#include <stdlib.h>
#include <stdio.h>
struct dequeue
{
    int *q;
    int size;
    int f, r;
};
typedef struct dequeue dequeue_t;

void init(dequeue_t* dq){
    printf("Enter the size of queue : ");
    scanf("%d",&(dq->size));
    dq->q = malloc(sizeof(int)*dq->size);
    dq->f = dq->r = -1;
}

void qinsertfront(dequeue_t* dq,int data){
    if (((dq->f == 0) && (dq->r == dq->size - 1)) || (dq->f == dq->r + 1)){
        printf("Queue is full\n");
        return;
    }
    if (dq->f == -1){
        dq->f = 0;
        dq->r = 0;
    }else if (dq->f == 0){
        dq->f = dq->size - 1;
    }else{
        dq->f = dq->f - 1;
    }
    dq->q[dq->f] = data;
}

void qinsertrear(dequeue_t* ptr, int data){
    if ((ptr->r+1)%ptr->size == ptr->f){
        printf("Queue is full\n");
        return;
    }
    ptr->r = (ptr->r + 1)%(ptr->size);
    ptr->q[ptr->r] = data;
    if (ptr->f == -1){
        ptr->f = 0;
    }
}

int qdeleterear(dequeue_t* ptr){
    
}

int qdeletefront(dequeue_t *);
void display(dequeue_t *);

int main()
{

    int ch, k, x;
    dequeue_t dq;
    init(&dq);
    while (1)
    {
        display(&dq);
        printf("\n1..Insert front of Queue");
        printf("\n2..Delete rear of the Queue");
        printf("\n3..Insert rear of Queue");
        printf("\n4..Delete front of the Queue");
        printf("\n5..Display the Queue");
        printf("\n6..EXIT");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value..");
            scanf("%d", &x);
            qinsertfront(&dq, x);
            break;
        case 2:
            k = qdeleterear(&dq);
            if (k > 0)
                printf("element deleted=%d\n", k);
            break;
        case 3:
            printf("Enter the value..");
            scanf("%d", &x);
            qinsertrear(&dq, x);
            break;
        case 4:
            k = qdeletefront(&dq);
            if (k > 0)
                printf("element deleted=%d\n", k);
            break;
        case 5:
            display(&dq);
            break;
        case 6:
            exit(0);
        }
    }
}
