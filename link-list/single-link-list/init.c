#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    node_t *next;
}node_t;

typedef struct link{
    node_t* head;
}link_t;


void init(link_t* ptr_link){
    ptr_link->head = NULL;
}
