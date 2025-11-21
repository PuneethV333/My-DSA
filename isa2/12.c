#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
    int key;
    char name[100];
    struct node *next;
}node_t;


typedef struct{
    node_t *head;
    int count;
}hash;



void insert(hash* ht,int key,int size,char *name){
    int index = key%size;

    node_t* temp = malloc(sizeof(node_t));
    temp->key = key;
    strcpy(temp->name,name);
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
        printf("Key not found\n");
        return;
    }

    if(prev == NULL){
        ht[index].head = temp->next;
    }else{
        prev->next = temp->next;
    }

    free(temp);
    ht[index].count--;
}


void search(hash* ht,int key,int size){
    int index = key%size;
    node_t* temp = ht[index].head;
    while(temp != NULL && temp->key != key){
        temp = temp->next;
    }

    if(temp != NULL){
        printf("Key found\n");
    }else{
        printf("key not found\n");
    }
}



void display(hash* ht,int size){
    for (int i = 0; i < size; i++){
        printf("%d : ",i);
        node_t* temp = ht[i].head;
        while(temp != NULL){
            printf("%d %s -> ",temp->key,temp->name);
            temp = temp->next;
        }
        printf('\n');
    }
}