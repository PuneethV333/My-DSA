//program to implement circular doubly linked List
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node* next;
  struct node* prev;
}node_t;

typedef struct dlist{
	node_t *head;
}dlist_t;

void init_list(dlist_t* ptr){
    ptr->head = NULL;
}

void insert_head(dlist_t* ptr,int data){
    node_t* temp = malloc(sizeof(node_t));
    temp->data = data;
    temp->next = temp->prev = temp;

    node_t* pres = ptr->head;
    if(pres == NULL){
        ptr->head = temp;
    }else{
        pres->prev->next = temp;
        temp->prev = pres->prev;
        temp->next = pres;
        pres->prev = temp;
    }
}

void display(dlist_t* ptr){
    if (ptr->head == NULL){
        printf("list is empty\n");
    }
    node_t* pres = ptr->head;
    node_t* end = pres->prev;
    while(pres != end){
        printf("%d\n",pres->data);
        pres = pres->next;
    }
    printf("%d\n",pres->data);
    
    
}

void insert_tail(dlist_t* ptr,int data){
    node_t* temp = malloc(sizeof(node_t));
    temp->data = data;
    temp->next = temp->prev = temp;
    
    if(ptr->head == NULL){
        ptr->head = temp;
    }else{
        node_t* pres = ptr->head;
        node_t* end = pres->prev;
        end->next = temp;
        temp->next = pres;
        temp->prev = end;
        pres->prev = temp;
    }
}

void delete_node(dlist_t* ptr,int data){
   if(ptr->head == NULL){
    printf("list is empty\n");
    return;
   } 
   node_t* pres = ptr->head;
   node_t* end = pres->prev;

   while ((pres != end) && (pres->data == data)){
        pres = pres->data;
   }

   if(pres->data = data){
        if(pres->next == pres){
            ptr->head = NULL;
        }else{
            pres->prev->next = pres->next;
            pres->next->prev = pres->prev;
            if(pres == ptr->head){
                ptr->head = pres->next;
            }
        }
        free(pres);
   }else{
    printf("Node is empty\n");
   }
}

int main(){
 
  int ch,x,pos;
  
  dlist_t dl;
  
  init_list(&dl);

  while(1)
  { 
    display(&dl);
    printf("\n1..Insert Head\n");
    printf("2..Insert Tail\n");
    printf("3..Delete a Node..\n");
    printf("4..Display\n");
    printf("5..Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1:printf("Enter the number...");
            scanf("%d",&x);
            insert_head(&dl,x);
            break;
     case 2:printf("Enter the number...");
            scanf("%d",&x);
            insert_tail(&dl,x);
            break;
    case 3: printf("Enter the value of the node to be deleted...");
            scanf("%d",&x);
            delete_node(&dl,x);
            break;
   
     case 4:display(&dl);
            break;
     case 5:exit(0);
   }
 }
}