#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *link;
} node_t;

typedef struct list
{
    node_t *head;
} list_t;

void init_list(list_t *ptr)
{
    ptr->head = NULL;
}

void insert_head(list_t *ptr, int data)
{
    node_t *temp = malloc(sizeof(node_t));
    temp->key = data;
    temp->link = ptr->head;
    ptr->head = temp;
}

void display(list_t *ptr)
{
    if (ptr->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node_t *temp = ptr->head;
    while (temp != NULL)
    {
        printf("%d\n", temp->key);
        temp = temp->link;
    }
}

node_t *insert_head_st(list_t *ptr, int data)
{
    node_t *temp = malloc(sizeof(node_t));
    temp->key = data;
    temp->link = ptr->head;
    return temp;
}

void insert_end(list_t *ptr, int data)
{
    node_t *temp = malloc(sizeof(node_t));
    temp->key = data;
    temp->link = NULL;
    if (ptr->head == NULL)
    {
        ptr->head = temp;
        return;
    }
    node_t *pres = ptr->head;
    while (pres->link != NULL)
    {
        pres = pres->link;
    }
    pres->link = temp;
}

node_t *inser_st(list_t *ptr, int data)
{
    node_t *temp = malloc(sizeof(node_t));
    temp->key = data;
    temp->link = NULL;
    if (ptr->head == NULL)
    {
        return temp;
    }
    node_t *pres = ptr->head;
    while (pres->link != NULL)
    {
        pres = pres->link;
    }
    pres->link = temp;
    return (ptr->head);
}

void delete_first(list_t *ptr)
{
    if (ptr->head == NULL)
    {
        printf("list is empty\n");
        return;
    }
    node_t *pres = ptr->head;
    ptr->head = pres->link;
    free(pres);
}

void delete_last(list_t *ptr)
{
    if (ptr->head == NULL)
    {
        printf("list is empty\n");
        return;
    }
    node_t *pres = ptr->head;
    node_t *post = NULL;
    while (pres->link != NULL)
    {
        post = pres;
        pres = pres->link;
    }
    if (post == NULL)
    {
        ptr->head = NULL;
    }
    else
    {
        post->link = NULL;
    }
    free(pres);
}

void revers_linklist(list_t *ptr)
{
    node_t *temp = NULL;
    node_t *prev = NULL;
    node_t *pres = ptr->head;
    while (pres->link != NULL)
    {
        temp = pres->link;
        pres->link = prev;
        prev = pres;
        pres = temp;
    }
    ptr->head = prev;
}

void insert_pos(list_t *ptr, int data, int pos)
{
     if (pos <= 0) {
        printf("invalid pos\n");
        return;
    }
    node_t *temp = malloc(sizeof(node_t));
    temp->key = data;
    temp->link = NULL;
    int cer_pos = 1;
    node_t *pres = ptr->head;
    node_t *prev = NULL;
    while ((pres != NULL) && (cer_pos < pos))
    {
        prev = pres;
        pres = pres->link;
        cer_pos++;
    }
    if (pres != NULL)
    {
        if (prev == NULL)
        {
            temp->link = pres;
            ptr->head = temp;
        }
        else
        {
            temp->link = pres;
            prev->link = temp;
        }
    }
    else
    {
        if (cer_pos == pos)
        {
            prev->link = temp;
        }
        else
        {
            printf("invalid pos\n");
        }
    }
}

void delete_node(list_t *ptr, int x)
{
    if (ptr->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node_t *pres = ptr->head;
    node_t *prev = NULL;
    while ((pres != NULL) && (pres->key != x))
    {
        prev = pres;
        pres = pres->link;
    }
    if (pres != NULL)
    {
        if (prev == NULL)
        {
            ptr->head = pres->link;
        }
        else
        {
            prev->link = pres->link;
        }
        free(pres);
    }
    else
    {
        printf("node not found\n");
    }
}

void delete_pos(list_t *ptr, int pos){
    node_t *pres = ptr->head;
    node_t *prev = NULL;
    int cur_pos = 1;
    if (ptr->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while ((pres != NULL) && (cur_pos < pos))
    {
        prev = pres;
        pres = pres->link;
        cur_pos++;
    }
    if (pres != NULL)
    {
        if (prev == NULL)
        {
            ptr->head = pres->link;
        }
        else
        {
            prev->link = pres->link;
        }
        free(pres);
    }
    else
    {
        printf("node not found\n");
    }
}

void insert_order(list_t* ptr,int data){
    node_t* temp = malloc(sizeof(node_t));
    temp->key = data;
    temp->link = NULL;
    if(ptr->head == NULL){
        temp->link = ptr->head;
        
    }else{
        node_t* pres = ptr->head;
        node_t* prev = NULL;
        while ((pres != NULL) && (pres->key < data) ){
            prev = pres;
            pres = pres->link;
        }
        if(pres == NULL){
            prev->link = temp;
        }else{
            if(prev == NULL){
                temp->link = pres;
                ptr->head = temp;
            }else{
                temp->link = pres;
                prev->link = temp;
            }
        }
    }
    
}

void create_list(list_t* ptr){
    int x;
    while (1){
        printf("Enter data(>0) : ");
        scanf("%d",&x);
        if(x == 0){
            break;
        }
        insert_order(ptr,x);
    }
    
}

int main()
{
    list_t l;
    int ch, n, pos;
    init_list(&l);
    // l.head=NULL;
    while (1)
    {
        display(&l);
        printf("\n1..Insert at end");
        printf("\n2..display");
        printf("\n3..Insert at head");
        printf("\n4..delete_last");
        printf("\n5.delete first");
        printf("\n6..delete node");
        printf("\n7 delete position");
        printf("\n8.insert at a position");
        printf("\n9. Exit");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the element to be inserted..");
            scanf("%d", &n);
            insert_end(&l, n);
            // l.head = insert_head_st(&l,n);
            break;

        case 2:
            display(&l);
            break;

        case 3:
            printf("\nEnter the element to be inserted..");
            scanf("%d", &n);
            insert_head(&l, n);
            // l.head = inser_st(&l,n);
            break;
        case 4:
            delete_last(&l);
            break;
        case 5:
            delete_first(&l);
            break;
        case 6:
            printf("\nEnter the element to be deleted..");
            scanf("%d", &n);
            delete_node(&l, n);
            break;
        case 7:
            printf("\nEnter the position..");
            scanf("%d", &n);
            delete_pos(&l, n);
            break;
        case 8:
            printf("\nEnter the value and position..");
            scanf("%d %d", &n, &pos);
            insert_pos(&l, n, pos);
            break;
        case 9:
            exit(0);
        }
    }
}