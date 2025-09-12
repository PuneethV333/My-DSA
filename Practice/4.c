#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int key;
	struct node *next;
  	struct node *prev;
} node_t;

typedef struct dlist{
	node_t *head;
} dlist_t;

void init_list(dlist_t *ptr){
	ptr->head = NULL;
}

void insert_head(dlist_t *ptr, int data){
	node_t* temp = malloc(sizeof(node_t));
	temp->key = data;
	temp->next = ptr->head;
	temp->prev = NULL;
	if(ptr->head == NULL){
		ptr->head = temp;
	}else{
		ptr->head->prev = temp;
		ptr->head = temp;
	}
}

void display(dlist_t *ptr){
	if(ptr->head == NULL){
		printf("List is empty\n");
		return;
	}
	node_t* pres = ptr->head;
	while (pres->next != NULL){
		printf("%d\n",pres->key);
		pres = pres->next;
	}
}

void insert_tail(dlist_t *ptr, int data){
	node_t* temp = malloc(sizeof(node_t));
	temp->key = data;
	temp->next = temp->prev = NULL;
	if(ptr->head == NULL){
		ptr->head = temp;
	}else{
		node_t* pres = ptr->head;
		while (pres->next != NULL){
			pres = pres->next;
		}
		pres->next = temp;
		temp->prev = pres;
	}
}

void delete_first(dlist_t *ptr){
	if(ptr->head == NULL){
		printf("List is empty\n");
		return;
	}
	node_t* pres = ptr->head;
	if(pres->next == NULL){
		ptr->head = NULL;
	}else{
		pres->next->prev = NULL;
		ptr->head = pres->next;
	}
	free(pres);
}

void delete_last(dlist_t *ptr){
	if(ptr->head == NULL){
		printf("List is empty\n");
		return;
	}
	node_t* pres = ptr->head;
	if(pres->next == NULL){
		ptr->head = NULL;
	}else{
		while (pres->next != NULL){
			pres = pres->next;
		}
		pres->prev->next = NULL;		
	}
	free(pres);
}

void delete_node(dlist_t *ptr,int data){
	if(ptr->head == NULL){
		printf("List is empty");
		return;
	}
	node_t* pres = ptr->head;
	while ((pres != NULL) && (pres->key != data)){
		pres = pres->next;
	}
	if(pres == NULL){
		printf("Node not found\n");
	}else{
		if(pres->prev == NULL){
			pres->next->prev = NULL;
			ptr->head = pres->next;
		}else if (pres->next == NULL){
			pres->prev->next = NULL;
		}else if ((pres->next == NULL) && (pres->prev == NULL)){
			ptr->head = NULL;			
		}else{
			pres->next->prev = pres->prev;
			pres->prev->next = pres->next;
		}	
	}
	free(pres);
}

void delete_pos(dlist_t *ptr,int pos){
	if(ptr->head == NULL){
		printf("list is empty\n");
		return;
	}
	node_t* pres = ptr->head;
	int crr_pos = 1;
	while ((pres != NULL) && (crr_pos < pos)){
		pres = pres->next;
		crr_pos++;			
	}
	if (pres == NULL){
		printf("Node not found\n");
	}else{
		if((pres->next == NULL) && (pres->prev == NULL)){
			ptr->head = NULL;
		}else if (pres->prev == NULL){
			pres->next->prev = NULL;
			ptr->head = pres->next;
		}else if (pres->next == NULL){
			pres->prev->next = NULL;
		}else{
			pres->next->prev = pres->prev;
			pres->prev->next = pres->next;
		}
	}
	free(pres);	
}

void insert_pos(dlist_t *ptr, int data, int pos){
	if(pos < 1){
		printf("Invalid position\n");
	}
	node_t* temp = malloc(sizeof(node_t));
	temp->key = data;
	temp->next = NULL;
	temp->prev = NULL;
	node_t* pres = ptr->head;
	int crr_pos = 1;
	while ((pres != NULL) && (crr_pos<pos)){
		pres = pres->next;
		crr_pos++;
	}
	if(crr_pos == pos){
		if (pres->prev == NULL){
			pres->prev = temp;
			temp->next = pres;
			ptr->head = temp;
		}else{
			pres->prev->next = temp;
			temp->prev = pres->prev;
			temp->next = pres;
			pres->prev = temp;
		}
	}else if (crr_pos == pos - 1){
		pres->next = temp;
		temp->prev = pres;
	}else{
		printf("not valid postion");
	}
	







}
void insert_after(dlist_t *, int, int);
void insert_before(dlist_t *, int, int);

int main()
{
	int ch, key, pos, value;
	dlist_t l;
	init_list(&l);

	while (1)
	{
		display(&l);
		printf("\n1..insert_head");
		printf("\n2..insert_tail");
		printf("\n3..Display");
		printf("\n4.delete first node");
		printf("\n5. Delete Last Node..");
		printf("\n6 .Delete a node given value");
		printf("\n7.Delete at a position");
		printf("\n8.Insert at a Given Position");
		printf("\n9. Insert after given value..\n");
		printf("\n10. Insert before given value..\n");
		printf("\n11.Exit");

		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("\nEnter the key...");
			scanf("%d", &key);
			insert_head(&l, key);
			break;
		case 2:
			printf("\nEnter the key...");
			scanf("%d", &key);
			insert_tail(&l, key);
			break;
		case 3:
			display(&l);
			break;
		case 4:
			delete_first(&l);
			break;
		case 5:
			delete_last(&l);
			break;
		case 6:
			printf("\nEnter the key...");
			scanf("%d", &key);
			delete_node(&l, key);
			break;
		case 7:
			printf("\nEnter the position");
			scanf("%d", &pos);
			delete_pos(&l, pos);
			break;
		case 8:
			printf("\nEnter the key and position");
			scanf("%d %d", &key, &pos);
			insert_pos(&l, key, pos);
			break;
		case 9:
			printf("\nEnter the value and key");
			scanf("%d %d", &value, &key);
			insert_after(&l, value, key);
			break;
		case 10:
			printf("\nEnter the value and key");
			scanf("%d %d", &value, &key);
			insert_before(&l, value, key);
			break;
		case 11:
			exit(0);
		}
	}
}