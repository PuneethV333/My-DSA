#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    node_t *next;
}node_t;

void init(node_t* ptr_link){
    ptr_link->next = NULL;
}

void insert_end(node_t** ptr,int n){
    node_t* temp = malloc(sizeof(node_t));
    temp->data = n;
    temp->next = NULL;
    if(*ptr == NULL){
        *ptr = temp;
    }else{
        node_t* pres = *ptr;
        while (pres->next != NULL){
            pres = pres->next;
        }
        pres->next = temp;
    }
}

void insert_front(node_t** ptr,int n){
    node_t* temp = malloc(sizeof(node_t));
    temp->data = n;
    temp->next = *ptr;
    *ptr = temp;    
}

node_t* insert_front_2(node_t** ptr,int n){
    node_t* temp = malloc(sizeof(node_t));
    temp->data = n;
    temp->next = *ptr;
    return temp;
}

node_t * insert_end_2(node_t** ptr,int n){
    // retuen head 
    node_t* temp = malloc(sizeof(node_t));
    temp->data = n;
    temp->next = NULL;
    if(*ptr == NULL){
        return temp;
    }else{
        node_t* pres = *ptr;
        while(pres->next != NULL){
            pres = pres->next;
        } 
        pres->next = temp;
        return ptr;
    }
}








int main(){
    node_t* head;
    init(head);

}