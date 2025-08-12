//?     there are three type of delete
// ?    1. Delete at end
// ?    2. Delete at start
// ?    3.Delete at any given point


#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    node_t *next;
}node_t;

typedef struct link{
    node_t* head;
}link_t;


// at end 
void delete_end(link_t* ptr){
    if(ptr->head == NULL){
        printf("list is empty\n");
        return;
    }
    node_t* pres = ptr->head;
    node_t* prev = NULL;
    while(pres->next != NULL){
        prev = pres;
        pres = pres->next;
    }
    if(prev == NULL){
        ptr->head = NULL;
    }else{
        prev->next = NULL;
        free(pres);
    }
}

// at strat
void delete_stat(link_t* ptr){
    if(ptr->head == NULL){
        printf("list is empty\n");
        return;
    }
    node_t* pres = ptr->head;
    ptr->head = pres->next;
    free(pres);
}


// at any point
void delete_at(link_t* ptr,int data){
    if(ptr->head == NULL){
        printf("list is empty\n");
        return;
    }
    node_t* pres = ptr->head;
    node_t* prev = NULL;
    while(pres != NULL && prev->data != data){
        
        prev = pres;
        pres = pres->next;
    }
    if(pres == NULL){
        // element out of bound
        printf("Element out of bound");
        return;
    }
    // if only head is present
    if(prev == NULL){
        ptr->head = pres->next;
    }else{
        // removing the element
        prev->next = prev->next;
        free(pres);
    }
}