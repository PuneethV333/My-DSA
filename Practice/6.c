#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int key;
	 struct node *link;
}node_t;


//last : pointer to last node
typedef struct list{
	node_t *last;
}clist_t;


void init_list(clist_t *ptr){
    ptr->last = NULL;
}

void display(clist_t* ptr){
    if(ptr->last == NULL){
        printf("List is empty");
        return;
    }
    node_t *end = ptr->last;
    node_t* pres = end->link;
    while (pres != end){
        printf("%d\n",pres->key);
        pres = pres->link;
    }
    printf("%d\n",pres->key);
}

void insert_head(clist_t *ptr,int data){
    node_t* temp = malloc(sizeof(node_t));
    temp->key = data;
    temp->link = temp;
    if(ptr->last == NULL){
        ptr->last = temp;
    }else
    {
        node_t* end = ptr->last;
        temp->link = end->link;
        end->link = temp;
    }
}

void insert_tail(clist_t* ptr,int data){
    node_t* temp = malloc(sizeof(node_t));
    temp->key = data;
    temp->link = temp;
    if (ptr->last == NULL){
        ptr->last = temp;
    }else{
        node_t* end = malloc(sizeof(node_t));
        temp->link = end->link;
        end->link = temp;
        ptr->last = temp;
    }
}

void delete_node(clist_t* ptr,int data){
    node_t* end = ptr->last;
    node_t* pres = end->link;
    node_t* prev = end;
    while ((pres != end) && (pres->key != data)){
        prev = pres;
        pres = pres->link;
    }
    if(pres->key == data){
        if (pres->link = pres){
            ptr->last = NULL;
        }else{
            if(pres == end){
                ptr->last = prev;
            }
        }
        free(pres);       
    }else{
        printf("node not found\n");
    }
}

int main()
{
	int ch,key,pos;
	clist_t l;
	init_list(&l);

    while(1)
	{
		display(&l);
		printf("\n1..insert_head");
		printf("\n2..insert_tail");
		printf("\n3..Display");
		printf("\n4.Delete a node");
		printf("\n5..Exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter the key...");
			             scanf("%d",&key);
			            insert_head(&l,key);
			            break;
			case 2:printf("\nEnter the key...");
			             scanf("%d",&key);
			             insert_tail(&l,key);
			            break;			 
			case 3:display(&l);
			             break;
			 
			case 4:printf("\nEnter the key...");
			             scanf("%d",&key);
			            delete_node(&l,key);	
                       		           break;	
					   
			case 5:exit(0);
		}
	}
}