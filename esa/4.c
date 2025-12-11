#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node_t;

typedef struct {
    node_t* head;
}list_t;

void insertStrat(list_t* ptr,int x){
    node_t* temp = malloc(sizeof(node_t));
    temp->data = x;
    temp->next = NULL;

    if(ptr->head == NULL){
        temp->next = temp;
        ptr->head = temp;
        return;
    }

    node_t* last = ptr->head;
    while(last->next != ptr->head){
        last = last->next;
    }


    temp->next = ptr->head;
    last->next = temp;
    ptr->head = temp;
}


void insertEnd(list_t* ptr,int x){
    node_t* temp = malloc(sizeof(node_t));
    temp->data = x;
    temp->next = NULL;
    if(ptr->head== NULL){
        temp->next = temp;
        ptr->head = temp;
        return;
    }

    node_t* last = ptr->head;
    while(last->next != ptr->head){
        last = last->next;
    }


    temp->next = ptr->head;
    last->next = temp;
}


void deleteStart(list_t* ptr){
    if(ptr->head == NULL){
        printf("Link list is empty\n");
        return;
    }

    if(ptr->head->next == ptr->head){
        free(ptr->head);
        ptr->head = NULL;
        return;
    }


    node_t* last = ptr->head;
    while(last->next != ptr->head){
        last = last->next;
    }

    node_t* temp = ptr->head;
    ptr->head = temp->next;
    last->next = ptr->head;
    free(temp);
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
    

    node_t* last = ptr->head;
    node_t* prev = NULL;
    while(last->next != ptr->head){
        prev = last;
        last = last->next;
    }


    prev->next = ptr->head;
    free(last);
}


void display(list_t* ptr){
    if(ptr->head == NULL){
        printf("Link list is empty/n");
        return;
    }
    node_t* head = ptr->head;
    do{
        printf("%d -> ",head->data);
        head = head->next;
    }while(head != ptr->head);
    printf("(HEAD)\n");
}