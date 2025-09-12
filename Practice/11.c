#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

typedef struct stack{
    char arr[MAX];
    int top;
} stack_t;

void push(stack_t* ptr,char ch){
    ptr->arr[++(ptr->top)] = ch;
}

char pop(stack_t* ptr){
    return (ptr->arr[(ptr->top)--]);
}

char peek(stack_t* ptr){
    return (ptr->arr[ptr->top]);
}

int input_prec(char ch){
    switch (ch){
        case '+': case '-': return 1;
        case '*': case '/': return 3;
        case '(': return 7;
        case ')': return 0;
        default: return 5;   // operands
    }
}

int stack_prec(char ch){
    switch (ch){
        case '+': case '-': return 2;
        case '*': case '/': return 4;
        case '(': return 0;
        case '#': return -1;
        default: return 6;   // operands
    }
}

char* infixtopostfix(char* infix){
    int len = strlen(infix);
    char* postfix = malloc((sizeof(char)*len)*2);
    
    stack_t temp;
    temp.top = -1;

    push(&temp,'#');
    int pos = 0;

    for (int i = 0; i < len; i++){
        char ch = infix[i];

        if(isalnum(ch)){  // operand
            postfix[pos++] = ch;
        }
        else if (ch == '('){
            push(&temp, ch);
        }
        else if (ch == ')'){
            while (peek(&temp) != '('){
                postfix[pos++] = pop(&temp);
            }
            pop(&temp); // remove '('
        }
        else { // operator
            while(stack_prec(peek(&temp)) >= input_prec(ch)){
                postfix[pos++] = pop(&temp);
            }
            push(&temp,ch);
        }
    }

    while (peek(&temp) != '#'){
        postfix[pos++] = pop(&temp);
    }
    postfix[pos] = '\0';
    return postfix;
}

int main() {
    char infix[] = "A+B*(C-D)";
    char* postfix = infixtopostfix(infix);
    printf("Infix:   %s\n", infix);
    printf("Postfix: %s\n", postfix);
    free(postfix);
    return 0;
}
