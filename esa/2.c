#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node_t;



void init(){
    node_t* head = malloc(sizeof(node_t));
    if(head == NULL){
        printf("Something went wrong\n");
        return;
    }
    head->next = NULL;
}

void insert_Start(node_t** head,int x){
    node_t* temp = malloc(sizeof(node_t));
    temp->data = x;
    temp->next = *head;
    *head = temp;
}

void insertEnd(node_t** head,int x){
    node_t* temp = malloc(sizeof(node_t));
    temp->next = NULL;
    temp->data = x;
    if(*head == NULL){
        *head = temp;
        return;
    }
    node_t* pres = *head;
    while(pres->next != NULL){
        pres = pres->next;
    }
    pres->next = temp;
}

void insert_pos(node_t** head,int x,int pos){
    if(pos <= 0){
        printf("Invalid pos\n");
        return;
    }
    node_t* temp = malloc(sizeof(node_t));
    temp->data = x;
    temp->next = NULL;
    if(pos == 1){
        temp->next = *head;
        *head = temp;
        return;
    }
    node_t *pres = *head;
    for(int i = 1;i < pos - 1 && pres != NULL;i++){
        pres = pres->next;
    }
    if(pres == NULL){
        printf("invalid pos\n");
        free(temp);
        return;
    }
    temp->next = pres->next;
    pres->next = temp;
}

void print(node_t* head){
    while(head != NULL){
        printf("%d -> ",head->data);
        head = head->next;
    }
    printf("/n");
}



void deleteStart(node_t** head){
    if(*head == NULL){
        printf("Link list is empty\n");
        return;
    }
    node_t* temp = *head;
    *head = temp->next;
    free(temp);
}

void deleteEnd(node_t** head){
    if(*head == NULL){
        printf("Link list is empty\n");
        return;
    }
    node_t *temp = *head;
    node_t* prev = NULL;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    if(prev == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    prev->next = NULL;
    free(temp);
} 


void deletePos(node_t** head,int val){
    if(*head == NULL){
        printf("Link list is empty\n");
        return;
    }
    node_t* pres = *head;
    node_t* prev = NULL;
    while(pres != NULL && pres->data != val){
        prev = pres;
        pres = pres->next;
    }
    if(pres == NULL){
        printf("Elem. Not found\n");
        return;
    }

    if(prev == NULL){
        *head = pres->next;
    }else{
        prev->next = pres->next;
    }
    free(pres);
}

void revers(node_t** head){
    node_t* pres = *head;
    node_t* prev = NULL;
    node_t* next = NULL;

    while(pres != NULL){
        next = pres->next;
        pres->next = prev;
        prev = pres;
        pres = next;
    }
    *head = prev;
}

void merge(node_t** h1,node_t* h2){
    if(*h1 == NULL){
        *h1 = h2;
        return;
    }

    node_t* temp = *h1;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = h2;
}