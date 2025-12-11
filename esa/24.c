#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
    int key;
    char name[100];
    struct node* next;
}node_t;

typedef struct{
    node_t* head;
    int count;
}hash;



void insert(hash *ht,int key,char *name,int size){
    int index = key%size;

    node_t* temp = malloc(sizeof(node_t));
    temp->key = key;
    strcpy(temp->name,name);
    temp->next = ht[index].head;
    ht[index].count++;
    ht[index].head = temp;
}


void delete(hash* ht,int key,int size){
    int index = key%size;
    node_t* temp = ht[index].head;
    node_t* prev = NULL;

    while (temp != NULL && temp->key != key){
        prev = temp;
        temp = temp->next;
    }
    
    if(temp == NULL){
        printf("key not found\n");
        return;
    }

    if(prev == NULL){
        ht[index].head = temp->next;
    }else{
        prev->next = temp->next;
    }
    free(temp);
    (ht[index].count)--;
}