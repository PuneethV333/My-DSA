#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    node_t *next;
}node_t;

typedef struct link{
    node_t* head;
}link_t;

void display(link_t* ptr_link){
    if(ptr_link->head == NULL){
        printf("List is empty\n");
        return;
    }
    node_t* present = ptr_link->head;
    while (present != NULL){
        printf("%d\n",present->data);
        present = present->next;
    }    
}