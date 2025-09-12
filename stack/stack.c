#include <stdio.h>
#include <stdlib.h>
#define stack_size 100

typedef struct stack
{
    int top;
    int arr_stack[100];
} stack_t;

typedef struct Stack_char
{
    int top;
    char stack_elem[stack_size];
} stack_c;

void init_st(stack_t *st)
{
    st->top = -1;
}

// for char stack

void push_c(stack_c *st, char ch)
{
    (st->stack_elem)[(st->top)++] = ch;
}

int is_empty(stack_t *st)
{
    if (st->top == -1)
        return 1;
    return 0;
}

int is_overflow(stack_t *st)
{
    if (st->top == stack_size - 1)
        return 1;
    return 0;
}

void display_stack(stack_t *st)
{
    if (st->top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        for (int i = 0; i < st->top; i++)
        {
            printf("%d -> %d\n", (i + 1), (st->arr_stack)[i]);
        }
    }
}

char pop_c(stack_c *st)
{
    return (st->stack_elem[(st->top)--]);
}

int pop(stack_t *st)
{
    if (st->top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        int x = (st->arr_stack)[st->top];
        (st->top)--;
        return x;
    }
}

char push_c(stack_c *st)
{
    char res = (st->stack_elem)[(st->top)--];
    return res;
}

void push(stack_t *st, int x)
{
    if (st->top == stack_size - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        (st->top)++;
        (st->arr_stack)[st->top] = x;
    }
}

int peek(stack_t *st)
{
    if (st->top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        int x = (st->arr_stack)[st->top];
        return x;
    }
}

int is_oper(char ch)
{
    if (ch == '+' | ch == '*' | ch == '-' | ch == '/' | ch == '$')
        return 1;
    return 0;
}

int eval_profix(char *profix)
{
    stack_t st;

    init_st(&st);
    int res;
    for (int i = 0; profix[i] != '\0'; i++)
    {
        char ch = profix[i];
        if (is_oper(ch))
        {
            int op1 = pop(&st);
            int op2 = pop(&st);
            switch (ch)
            {
            case '+':
                res = op2 + op1;
                break;
            case '-':
                res = op2 - op1;
                break;
            case '/':
                res = op2 / op1;
                break;
            case '*':
                res = op2 * op1;
                break;

            default:
                break;
            }
            push(&st, res);
        }
        else
        {
            printf("%c: ", ch);
            int x;
            scanf("%d", &x);
            push(&st, x);
        }
    }
    return res;
}

int presedence(char ch)
{
    if (ch == '$')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return -1;
}

char *infixtopostfix(char *infix)
{
    stack_c st;
    init_st(&st);
    int k = 0;
    int str_len = strlen(infix);
    char *postfix = malloc(2*str_len);
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];
        if (!is_oper(ch) && ch != '(' && ch != ')')
        {
            postfix[k++] = ch;
        }
        else if (ch == '(')
        {
            push_c(&st, ch);
        }
        else if (ch == ')')
        {
            while (st.top != -1 && st.stack_elem[st.top] != '(')
            {
                postfix[k++] = pop_c(&st);
            }
            pop_c(&st);
        }
        else
        {
            while (st.top != -1 && presedence(st.stack_elem[st.top]) >= presedence(ch))
            {
                postfix[k++] = pop_c(&st);
            }
            push_c(&st, ch);
        }
    }
    while (st.top != -1)
    {
        postfix[k++] = pop_c(&st);
    }
    postfix[k] = '\0';
    return postfix;
}