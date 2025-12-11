#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node_t;


typedef struct{
    node_t* head;
}list_t;


void init(list_t* ptr){
    ptr->head = NULL;
}


void insertStart(list_t* ptr,int x){
    node_t* temp = malloc(sizeof(node_t));
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
    if(ptr->head == NULL){
        temp->next = temp;
        temp->prev = temp;
        ptr->head = temp;
        return;
    }

    node_t* last = ptr->head->prev;

    node_t* head = ptr->head;
    temp->next = head;
    temp->prev = last;
    last->next = temp;
    ptr->head->prev = temp;
    ptr->head = temp;
}


void insertEnd(list_t* ptr,int x){
    node_t* temp = malloc(sizeof(node_t));
    temp->data = x;
    temp->next = temp->prev = NULL;
    if(ptr->head == NULL){
        temp->next = temp;
        temp->prev = temp;
        ptr->head = temp;
        return;
    }

    node_t* last = ptr->head->prev;
    node_t* head  = ptr->head;

    temp->next = head;
    temp->prev = last;
    last->next = temp;
    ptr->head->prev = temp;
}



void deleteStart(list_t* ptr){
    if(ptr->head == NULL){
        printf("Link List is empty\n");
        return;
    }
    if(ptr->head->next == ptr->head){
        free(ptr->head);
        ptr->head = NULL;
        return;
    }
    node_t* head = ptr->head;
    node_t* last = ptr->head->prev;

    ptr->head = head->next;
    last->next = head->next;
    ptr->head->prev = last;
    free(head);
}




void deleteEnd(list_t* ptr){
    if(ptr->head == NULL){
        printf("Link list is empty\n");
        return;
    }

    if(ptr->head->next == ptr->head){
        free(ptr->head);
        ptr->head = NULL;
        return;
    }

    node_t* head = ptr->head;
    node_t* last = ptr->head->prev;
    node_t* temp = last->prev;

    temp->next = ptr->head;
    ptr->head->prev = temp;
    free(last);
}


void display(list_t* ptr){
    if(ptr->head == NULL){
        printf("Link list is empty\n");
        return;
    }

    node_t* head = ptr->head;
    do{
        printf("%d -> ",head->data);
        head = head->next;
    }while(head != ptr->head);
    printf("(HEAD)\n");
}