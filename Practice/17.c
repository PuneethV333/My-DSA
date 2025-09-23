#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;
    int pty;
    struct node *link;
};
typedef struct node node_t;

struct list
{
    node_t *head;
};
typedef struct list list_t;

void init_list(list_t *q)
{
    q->head = NULL;
}

void qdisplay(list_t *q){
    node_t *pres;
    pres = q->head;
    if (pres == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        while (pres != NULL)
        {
            printf("%d->%d\n", pres->pty, pres->key);
            pres = pres->link;
        }
    }
}

void pqinsert(list_t *q, int x, int pty)
{
    node_t *temp = malloc(sizeof(node_t));
    temp->key = x;
    temp->pty = pty;
    temp->link = NULL;
    node_t *pres = q->head;
    node_t *prev = NULL;
    if (q->head == NULL)
    {
        q->head = temp;
    }
    else
    {
        while ((pres != NULL) && (pty >= pres->pty))
        {
            prev = pres;
            pres = pres->link;
        }
        if (prev == NULL)
        {
            temp->link = q->head;
            q->head = temp;
        }
        
        else if (pres == NULL)
        {
            prev->link = temp;
        }

        else
        {
            temp->link = pres;
            prev->link = temp;
        }
    }
}

node_t pqdelete(list_t* q){
    node_t* pres = q->head;
    node_t temp;
    temp.key = -1;
    temp.pty = -1;
    temp.link = NULL;
    if (pres == NULL){
        printf("Queue is empty\n");
        
    }else{
        temp.key = pres->key;
        temp.pty = pres->pty;
        if (pres->link == NULL){
            q->head = NULL;
        }else{
            q->head = pres->link;
        }
        free(pres);
    return temp;
    }
    
}

int main()
{
    list_t pq;
    init_list(&pq);
    int x, pty, ch;
    node_t temp;
    while (1)
    {
        qdisplay(&pq);
        printf("\n1..insert");
        printf("\n2..Delete");
        printf("\n3..display");
        printf("\n4..EXIT");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the priority..");

            scanf("%d", &pty);
            printf("Enter the value");
            scanf("%d", &x);
            pqinsert(&pq, x, pty);

            break;
        case 2:
            temp = pqdelete(&pq);
            if (temp.pty > 0)
            {
                printf("deleted element:- priority=%d", temp.pty);
                printf(" Data=%d\n", temp.key);
            }
            break;
        case 4:
            exit(0);
        }
    }
}
