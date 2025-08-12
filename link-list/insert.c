//?     there are three type of insert
// ?    1. Insert at end
// ?    2. Insert at start
// ?    3.Insert at any given point

// struct def
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    node_t *next;
}node_t;

typedef struct link{
    node_t* head;
}link_t;

// insert at end

void insert_end(link_t* ptr_link,int data){
    node_t* temp = (node_t*)malloc(sizeof(node_t));
    if(temp == NULL){
        printf("Error\n");
        return;
    }
    // insalising temp with the data
    temp->data = data;
    temp->next = NULL;
    // reaching the end of link list
    if( ptr_link->head == NULL){
         ptr_link->head = temp;
         return;
    }
    node_t* present = ptr_link->head;
    while (present->next != NULL){
        present = present->next;
    }
    present->next = temp;
}

// insert at starting of list

void insert_start(link_t* ptr,int data){
    // creating a node to insert data
    node_t* temp = malloc(sizeof(node_t));
    if(temp == NULL){
        printf("Error in memory alloction\n");
        return;
    }
    temp->data = data;
    // cheacking for empty list
    temp->next = ptr->head;
    ptr->head = temp;
}



// insert at any given point

void insert_at(link_t* ptr,int data,int pos){
    // pos = 0 ->start
    // pos is same as index value
    // creating a node to insert
    node_t* temp = malloc(sizeof(node_t));
    if(temp == NULL){
        printf("Error\n");
        return;
    }
    temp->data = data;
    temp->next = NULL;

    if(pos == 0 || ptr->head == NULL){
        // insert at start
        temp->next = ptr->head;
        ptr->head = temp;
        return;
    }
    
    node_t* pres = ptr->head;//pos = 0
    int pres_pos = 0;
    // to reach the pos
    while(pres != NULL && pres_pos < pos-1){
        pres = pres->next;
        pres_pos++;
    }
    if(pres == NULL){
        printf("Position out of bounds\n");
        free(temp);
        return;
    }
    temp->next = pres->next;
    pres->next = temp;

}



