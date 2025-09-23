#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct node{
	int key;
	struct node *link;
}node_t;

typedef struct stack{
	node_t *top;
}stack_t;

void init(stack_t* ptr){
    ptr->top = NULL;
}

int push(stack_t *ptr, int data){
    node_t* temp = malloc(sizeof(node_t));
    temp->key = data;
    temp->link = ptr->top;
    ptr->top = temp;
    return 1;
}

int pop(stack_t* ptr){
    if(ptr->top == NULL){
        printf("Stack is empty\n");
        return -1;
    }
    node_t* pres = ptr->top;
    int res = pres->key;
    ptr->top = pres->link;
    free(pres);
    return res;
}

void display(stack_t* ptr){
    if (ptr->top == NULL){
        printf("stack is empty\n");
        return;
    }
    node_t* pres = ptr->top;
    while (pres != NULL){
        printf("%d\n",pres->key);
        pres = pres->link;
    }
}

int main(){
	stack_t st;
	int ch,key,k;
	
	init(&st);
	while(1)
	{
		display(&st);
		printf("\n1..push");
		printf("\n2.pop");
		printf("\n3. display");
		printf("\n4.exit");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: printf("enter the element..");
						  scanf("%d",&key);
						  k=push(&st,key);
						  if(k>0)
							  printf("Element pushed successfully");
						  break;
			case 2: k=pop(&st);
						  if(k>0)
							    printf("The element popped = %d\n",k);
						  break;			  
			case 3: display(&st);
						break;
			case 4 : exit(0);
		}
	}
}

int is_opr(char ch){
	if(ch == '+' ||ch == '/' ||ch == '*' ||ch == '-'){
		return 1;
	}else{
		return 0;
	}
}




















int postfix_eval(char* postfix){
	int i = 0;
	int op1,op2,a,ch,res;
	stack_t st;
	init(&st);
	
	while (postfix[i] != '\0'){
		ch = postfix[i];
		if(is_opr(ch)){
			op1 = pop(&st);
			op2 = pop(&st);
			switch (ch)
			{
			case '+':
				res = op1+op2;
				break;
			case '-':
				res = op2-op1;
				break;
			case '*':
				res = op1*op2;
				break;
			case '/':
				res = op2/op1;
				break;
			}
			push(&st,res);
		}else{
			printf("%c = ",ch);
			scanf("%d",&a);
			push(&st,a);
		}
		i++;

	}
	
	return pop(&st);
}


int prefix_eval(char* prefix){
	int i = strlen(prefix) - 1;
	int ch,a,res,op1,op2;
	stack_t st;
	init(&st);
	for (i; i >= 0 ; i--){
		ch = prefix[i];

		if(is_opr(ch)){
			op1 = pop(&st);
			op2 = pop(&st);
			switch (ch){
			case '+':
				res = op2+op1;
				break;
			case '-':
				res = op2-op1;
				break;
			case '*':
				res = op2*op1;
				break;
			case '/':
				res = op2/op1;
				break;
			}
			push(&st,res);
		}else{
			printf("%c = ",ch);
			scanf("%d",&a);
			push(&st,a);
		}
	}
	return pop(&st);
	
}