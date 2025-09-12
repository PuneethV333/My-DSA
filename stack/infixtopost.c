#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define stack_size 100

typedef struct STACK
{
    int top;
    char *stack[stack_size];
} stack_t;

void init_st(stack_t *st)
{
    st->top = -1;
}

void push(stack_t *st, char ch)
{
    (st->stack)[(st->top)++] = ch;
}

char pop(stack_t *st)
{
    return (st->stack)[(st->top)--];
}
char peek(stack_t st)
{
    return (st.stack)[(st.top)];
}

int presidence(char ch)
{
    switch (ch)
    {
    case '$':
        return 3;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;

    default:
        return -1;
        break;
    }
}



int isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*'|| ch == '/'|| ch == '$')
        return 1;
    return 0;
}





char *inftopost(char *infix)
{
    stack_t *temp;
    init_st(temp);
    int k = 0;
    int str_len = strlen(infix);
    char *postfix = malloc(2*str_len);
    for (int i = 0; infix[i] != '\0' ; i++){
        char curElem = infix[i];
        if(!isOperator(curElem) && curElem != '('  && curElem != ')'){
            postfix[k++] = curElem;
        }else if (curElem == '('){
            push(temp,curElem);            
        }else if (curElem == ')'){
            while (temp->top != -1 && temp->stack[temp->top] != '(' ){
                postfix[k++] = pop(temp);
            }
            pop(temp);
        }
        else{
            while(temp->top != -1 && presidence((temp->stack)[temp->top]) >= presidence(curElem)){
                postfix[k++] = pop(temp);
            }
            push(&temp,curElem);
        }
    }
    while (temp->top != -1){
        postfix[k++] = pop(temp);
    }
    postfix[k] = '\0';
    return postfix;
    
}