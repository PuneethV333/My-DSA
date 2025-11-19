#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    bool rthread;
    bool lthread;
} node_t;

typedef struct
{
    node_t *root;
} tree;


void insert(tree *t, int key)
{
    node_t *temp = malloc(sizeof(node_t));
    node_t *crr;

    temp->data = key;
    temp->left = temp->right = NULL;
    temp->lthread = temp->rthread = true;

    crr = t->root;

    if (t->root == NULL)
    {
        t->root = temp;
        return;
    }

    while (1)
    {
        if (key < crr->data)
        {
            if (crr->lthread == false)
                crr = crr->left;
            else
                break;
        }
        else if (key > crr->data)
        {
            if(crr->rthread == false)
                crr = crr->right;
            else
                break;
        }
        else
        {
            // Duplicate key
            free(temp);
            return;
        }
    }

    if(key < crr->data)
    {
        temp->right = crr;
        temp->left = crr->left;
        crr->left = temp;
        crr->lthread = false;
    }
    else
    {
        temp->left = crr;
        temp->right = crr->right;
        crr->right = temp;
        crr->rthread = false;
    }
}


node_t* inorderSuccor(node_t* t)
{
    if(t->rthread == true)
        return t->right;

    t = t->right;
    while (t->lthread == false)
        t = t->left;

    return t;
}


void inorder(tree *t)
{
    node_t *crr = t->root;

    if(crr == NULL)
    {
        printf("Tree is empty\n");
        return;
    }

    while (crr->lthread == false)
        crr = crr->left;

    while (crr != NULL)
    {
        printf("%d ", crr->data);
        crr = inorderSuccor(crr);
    }
    printf("\n");
}
