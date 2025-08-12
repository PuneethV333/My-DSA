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
