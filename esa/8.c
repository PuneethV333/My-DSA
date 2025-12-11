#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

char peek()
{
    return stack[top];
}

int isEmty()
{
    return top == -1;
}

int priority(char x)
{
    switch (x)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

char *convertinfuxPostFix(char *infix)
{
    int n = strlen(infix);
    char *postfix = malloc(sizeof(char) * n);
    int j = 0;
    char ch;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (!isEmty() && peek() != '(')
            {
                postfix[j++] = pop();
            }
            pop();
        }
        else
        {
            while (!isEmty() && priority(peek()) >= priority(ch))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (!isEmty())
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    return postfix;
}

int postfixEval(char *postfix)
{
    int i = 0;
    int a;
    while (postfix[i] != '\0')
    {
        if (isalpha(postfix[i]))
        {
            printf("%c -> ",postfix[i]);
            scanf("%d",&a);
            push(a);

        }
        else
        {
            int op2 = pop();
            int op1 = pop();

            switch (postfix[i])
            {
            case '+':
                push(op1 + op2);
                break;
            case '-':
                push(op1 - op2);
                break;
            case '*':
                push(op1 * op2);
                break;
            case '/':
                push(op1 / op2);
                break;
            }
        }
        i++;
    }
    return pop();
}



int isMatchingPair(char open,char close){
    if(open == '{' && close == '}') return 1;
    if(open == '[' && close == ']') return 1;
    if(open == '(' && close == ')') return 1;
    return 0;
}


int match(char* exp){
    char ch;
    for(int i = 0;exp[i] != '\0';i++){
        ch = exp[i];
        if(ch == '{' || ch == '(' || ch == '['){
            push(ch);
        }else if(ch == '}' || ch == ')' || ch == ']'){
            if(isEmty()){
                return 0;
            }
            if(!isMatchingPair(pop(),ch)){
                return 0;
            }
        }
    }
    return isEmty();
}
