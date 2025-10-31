#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    char data;
    struct tnode *left;
    struct tnode *right;
} node_t;
// typedef struct tnode
// {
//     int data;
//     struct tnode *left;
//     struct tnode *right;
// } node_t;

typedef struct tree
{
    node_t *root;
} tree_t;

void init(tree_t *t)
{
    t->root = NULL;
}

// void insert(tree_t *t, int x)
// {
//     node_t *temp = malloc(sizeof(node_t));
//     node_t *crr = NULL;
//     node_t *prev = NULL;

//     temp->data = x;
//     temp->left = NULL;
//     temp->right = NULL;
//     if (t->root == NULL)
//     {
//         t->root = temp;
//     }
//     else
//     {
//         crr = t->root;
//         while (crr != NULL)
//         {
//             prev = crr;
//             if (crr->data > x)
//             {
//                 crr = crr->left;
//             }
//             else
//             {
//                 crr = crr->right;
//             }
//         }
//         if (prev->data > x)
//         {
//             prev->right = temp;
//         }
//         else
//         {
//             prev->left = temp;
//         }
//     }
// }

// void preorder(node_t *t)
// {
//     if (t != NULL)
//     {
//         printf("%d\n", t->data);
//         preorder(t->left);
//         preorder(t->right);
//     }
// }

// void postorder(node_t *t)
// {
//     if (t != NULL)
//     {
//         postorder(t->left);
//         postorder(t->right);
//         printf("%d\n", t->data);
//     }
// }

// void inorder(node_t *t)
// {
//     if (t != NULL)
//     {
//         inorder(t->left);
//         printf("%d\n", t->data);
//         inorder(t->right);
//     }
// }

// int min(node_t *t)
// {
//     if (t == NULL)
//     {
//         printf("tree is empty\n");
//         return -1;
//     }

//     while (t->left != NULL)
//     {
//         t = t->left;
//     }
//     return (t->data);
// }

// int max(node_t *t)
// {
//     if (t == NULL)
//     {
//         printf("tree is empty\n");
//         return -1;
//     }

//     while (t->right != NULL)
//     {
//         t = t->right;
//     }
//     return (t->data);
// }

// int height(node_t *t)
// {
//     int l, r;
//     if (t == NULL)
//     {
//         return -1;
//     }
//     if ((t->left == NULL) && (t->right == NULL))
//     {
//         return 0;
//     }

//     l = height(t->left);
//     r = height(t->right);
//     if (l > r)
//     {
//         return l + 1;
//     }
//     return r + 1;
// }

// int leafnode(node_t *t)
// {
//     int l, r;
//     if (t == NULL)
//     {
//         return 0;
//     }
//     if ((t->left == NULL) && (t->right == NULL))
//     {
//         return 1;
//     }

//     l = leafnode(t->left);
//     r = leafnode(t->right);
//     return (l + r);
// }

// int identical(node_t *t1, node_t *t2)

// {
//     int l, r;
//     if ((t1 == NULL) && (t2 == NULL))
//     {
//         return 1;
//     }
//     if ((t1 != NULL) && (t2 != NULL))
//     {
//         if (t1->data == t2->data)
//         {
//             l = identical(t1->left,t2->left);
//             r = identical(t1->right,t2->right);
//             return (l && r);
//         }
//         return 0;
//     }
//     return 0;
// }

// todo:->expression tree

// ? stack

typedef struct stack
{
    node_t *arr[100];
    int top;
} stack_t;

void init_st(stack_t* st){
    st->top = -1;
}

void push(stack_t *st, node_t *t)
{
    st->arr[++(st->top)] = t;
}

node_t* pop(stack_t *st)
{
    if (st->top == -1) {
        printf("Stack Underflow!\n");
        return NULL;
    }
    return st->arr[(st->top)--];
}


node_t* peek(stack_t* st){
    return (st->arr[st->top]);
}

int isoparator(char ch)
{
    switch (ch)
    {
    case '+':
    case '/':
    case '*':
    case '-':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}


void create_exptree(tree_t* t,char* exp){
    stack_t st;
    init_st(&st);
    int i = 0;
    char ch;
    while (exp[i] != '\0'){
        ch = exp[i];
        node_t* temp = malloc(sizeof(node_t));
        temp->data = ch;
        temp->left = temp->right = NULL;
        if(isoparator(ch)){
            temp->right = pop(&st);
            temp->left = pop(&st);
        }
            push(&st,temp);
        i++;
    }
    t->root = pop(&st);
    
}


int eval(tree_t* t){
    return (evaluate(t->root));
}

int evaluate(node_t* t){
    int a;
    switch (t->data){
    case '+':
        return (evaluate(t->left)+evaluate(t->right));
        
    case '-':
        return (evaluate(t->left)-evaluate(t->right));
        
    case '*':
        return (evaluate(t->left)*evaluate(t->right));
        
    case '/':
        return (evaluate(t->left)/evaluate(t->right));
        
    
    default:
        int a;
        printf("%c =",t->data);
        scanf("%d",&a);
        return a;
    }
}