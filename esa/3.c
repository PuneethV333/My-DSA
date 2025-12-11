#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node_t;

typedef struct {
    node_t* head;
}list_t;


void init(list_t* head){
    head->head = NULL;
}

void insetStart(list_t* ptr,int x){
    node_t* temp = malloc(sizeof(node_t));
    temp->data = x;
    temp->next = ptr->head;
    temp->prev = NULL;
    if(ptr->head == NULL){
        ptr->head = temp;
    }else{
        ptr->head->prev = temp;
        ptr->head = temp;
    }
}


void insertEnd(list_t* ptr,int x){
    node_t* temp = malloc(sizeof(node_t));
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;

    if(ptr->head == NULL){
        ptr->head = temp;
        return;
    }

    node_t *pres = ptr->head;
    while(pres->next != NULL){
        pres = pres->next;
    }

    pres->next = temp;
    temp->prev = pres;

}



void insert_pos(list_t* ptr,int x,int pos){
    if(pos <= 0){
        printf("Invalid pos\n");
        return;
    }
    
    node_t* temp = malloc(sizeof(node_t));
    temp->data = x;
    temp->next = temp->prev = NULL;

    if(pos == 1){
        temp->next = ptr->head;
        if(ptr->head != NULL){
            ptr->head->prev = temp;
        }
        ptr->head = temp;
        return;
    }

    node_t* pres = ptr->head;

    for(int i = 1; pres != NULL && i < pos-1;i++){
        pres = pres->next;
    }

    if(pres == NULL){
        printf("Invalid pos...\n");
        free(temp);
        return;
    }

    temp->next = pres->next;
    temp->prev = pres;
    if(pres->next != NULL){
        pres->next->prev = temp;
    }
    pres->next = temp;
}


void deleteStart(list_t* ptr){
    if(ptr->head == NULL){
        printf("Link list is empty\n");
        return;
    }
    node_t* pres = ptr->head;
    ptr->head = pres->next;

    if(ptr->head != NULL){
        ptr->head->prev = NULL;
    }
    free(pres);
}



void deleteEnd(list_t* ptr){
    if(ptr->head == NULL){
        printf("Link list is empty\n");
        return;
    }

    node_t* pres = ptr->head;
    if(pres->next == NULL){
        ptr->head = NULL;
        free(pres);
        return;
    }

    while(pres->next != NULL){
        pres = pres->next;
    }
    pres->prev->next = NULL;
    free(pres);
}

void deleteByData(list_t* ptr,int x){
    if(ptr->head == NULL){
        printf("Link list is empty\n");
        return;
    }

    node_t* pres = ptr->head;
    while(pres != NULL && pres->data == x){
        pres = pres->next;
    }

    if(pres == NULL){
        printf("Elem. not found\n");
        return;
    }


    if(pres->prev==NULL){
        ptr->head = pres->next;
        if(ptr->head != NULL){
            ptr->head->prev = NULL;
        }
    }else{
        pres->prev->next = pres->next;
    }

    if(pres->next != NULL){
        pres->next->prev = pres->prev;
    }

    free(pres);
}


void deleteByPos(list_t* ptr,int pos){
    if(ptr->head == NULL){
        printf("Link list is empty\n");
        return;
    }

    if(pos <= 0){
        printf("Invalid pos\n");
        return;
    }

    node_t* temp = ptr->head;
    if(pos == 1){
        ptr->head = temp->next;
        if(ptr->head != NULL){
            ptr->head->prev = NULL;
        }
        free(temp);
        return;
    }

    for(int i = 1; i < pos-1 && temp != NULL;i++){
        temp = temp->next;
    }


    if(temp == NULL){
        printf("Invalid pos\n");
        return;
    }

    if(temp->prev != NULL){
        temp->prev->next = temp->next;
    }

    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    }

    free(temp);

}




