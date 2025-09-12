#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int key;
	struct node *link;
}node_t;

void insert_end(node_t** ptr,int data){
    node_t* temp = malloc(sizeof(node_t));
    temp->key = data;
    temp->link = NULL;
    if(*ptr == NULL){
        *ptr = temp;
        return;
    }
    node_t* pres = *ptr;
    while (pres->link != NULL){
        pres = pres->link;
    }
    pres->link = temp;
}

void insert_head(node_t** ptr,int data){
	node_t* temp = malloc(sizeof(node_t));
	temp->key = data;
	temp->link = NULL;
	if(*ptr == NULL){
		*ptr = temp;
	}
	temp->link = *ptr;
	*ptr = temp;
}

void delete_last(node_t** ptr){
	if(*ptr == NULL){
		printf("List is empty\n");
		return;
	}
	node_t* prev = NULL;
	node_t* pres = *ptr;
	while (pres->link != NULL){
		prev = pres;
		pres = pres->link;
	}
	if(prev == NULL){
		*ptr = NULL;
	}else{
		prev->link = NULL;

	}
	free(pres);
}

void delete_first(node_t**);
void display(node_t*);
void delete_node(node_t **,int);
void delete_pos(node_t ** , int);
void insert_pos(node_t ** , int,int);

int main(){
    int ch,n,pos;
	node_t *head;
   head=NULL;
   while(1)
   {
	   display(head);
	   printf("\n1..Insert at end");
	   printf("\n2..display");
	   printf("\n3..Insert at head");
	   printf("\n4..delete_last");
	   printf("\n5.delete first");
	   printf("\n6..delete node");
	   printf("\n7 delete position");
	   printf("\n8.insert at a position");
	   printf("\n9. Exit");
	   scanf("%d",&ch);
	   switch(ch)
	   {
		case 1: printf("\nEnter the element to be inserted..");
		                 scanf("%d",&n);
						insert_end(&head,n);
						break;  
						
		  case 2:display(head);
		               break;
		
	      case 3: printf("\nEnter the element to be inserted..");
		                 scanf("%d",&n);
						insert_head(&head,n);
						break;  
		case 4:delete_last(&head);
						break;  			
		case 5:delete_first(&head);
						break;
		case 6:printf("\nEnter the element to be deleted..");
		                 scanf("%d",&n);
						 delete_node(&head,n);
						 break;
			case 7:printf("\nEnter the position..");
		                 scanf("%d",&n);
						 delete_pos(&head,n);
						 break;
			case 8:printf("\nEnter the value and position..");
		                 scanf("%d %d",&n,&pos);
						 insert_pos(&head,n,pos); 
						 break; 
			case 9:exit(0);
	    }
    }
    return 0;				  
}	