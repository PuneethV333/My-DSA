// PROGRAM TO EVALUATE A GIVEN POSTFIX EXPRESSION
// INPUT IS OF THE FORM (eg. abc*+)
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct stack
{
    int *s;
    int size;
    int top;
};

typedef struct stack stack_t;

void init_stk(stack_t *ptr)
{
    ptr->top = -1;
}

void push(stack_t *ptr, int data)
{
    if (ptr->top = ptr->size - 1)
    {
        printf("Stack is full\n");
        return;
    }
    ptr->s[++(ptr->top)] = data;
}

int peek(stack_t* ptr){
    return (ptr->s[ptr->top]);
}

int pop(stack_t *ptr)
{
    if (ptr->top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    return (ptr->s[(ptr->top)--]);
}

int postfix_eval(char *postfix)
{
    stack_t st;
    init_stk(&st);
    int i = 0;
    while (postfix[i] != '\0')
    {
        char ch = postfix[i];
        if (is_oper(ch))
        {
            int op1 = pop(&st);
            int op2 = pop(&st);
            int res;
            switch (ch)
            {
            case '+':
                res = op2 + op1;
                break;
            case '/':
                res = op2 / op1;
                break;
            case '^':
                res = op2 ^ op1;
                break;
            case '*':
                res = op2 * op1;
                break;
            case '-':
                res = op2 - op1;
                break;
            }
        }

        else
        {
            int x;
            printf("%c = ", ch);
            scanf("%d", &x);
            push(&st, x);
        }

        i++;
    }
}

int isEmpty(stack_t* st){
    return (st->top == -1);
}

int is_oper(char ch)
{
    switch (ch)
    {
    case '+':
    case '^':
    case '/':
    case '*':
    case '-':
        return 1;
    default:
        return 0;
    }
}

void sort_stack(stack_t* st){
    stack_t temp;
    while (!isEmpty(st)){
        int crr = pop(st);
        while (!isEmpty(&temp) && peek(&temp) > crr){
            push(st,peek(&temp));
        }
        push(&temp,crr);
    }
    while (!isEmpty(&temp)){
        push(st,pop(&temp));
    }   
}

void NGE(stack_t* st){
    int NGE[MAX];
    stack_t temp;
    init_stk(&temp);
    for (int i = st->top; i >= 0; i--){
        while (!isEmpty(&temp) && st->s[i] >= peek(&temp)){
            pop(&temp);
        }
        if (isEmpty(&temp)){
            NGE[i] = -1;
        }else{
            NGE[i] = peek(&temp);
        }
        push(&temp,st->s[i]);
    }
    for (int i = 0; i <= st->top; i++){
        printf("%d\n",NGE[i]);
    }
}

int main()
{

    char postfix[100];
    printf("\nenter the postfix expression\n");
    scanf("%s", postfix);
    int result = postfix_eval(postfix);
    printf("\nthe result=%d\n", result);
}