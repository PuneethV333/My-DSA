#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *left;
    struct NODE *right;
} tnode_t;

typedef struct Tree
{
    tnode_t *root;
} tree_t;

int height(tnode_t *t)
{
    if (t == NULL)
        return 0;
    if ((t->left == NULL) && (t->right == NULL))
        return 1;

    int l = height(t->left);
    int r = height(t->right);
    if (r > l)
        return r + 1;
    return l + 1;
}

int leafnode(tnode_t *t)
{
    if (t == NULL)
        return 0;
    if ((t->left == NULL) && (t->right == NULL))
        return 1;

    int l = leafnode(t->left);
    int r = leafnode(t->right);

    return r + l;
}

int max(tree_t *t)
{
    tnode_t *temp = t->root;
    if ((t->root == NULL) || (t == NULL))
        return -1;

    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return (temp->data);
}

int min(tree_t *t)
{
    if ((t == NULL) || (t->root = NULL))
        return -1;
    tnode_t *temp = t->root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return (temp->data);
}

void tdelete_t(tree_t *t, int key)
{

    if (t == NULL || t->root == NULL)
    {
        printf("Empty tree\n");
        return;
    }
    tnode_t *curr, *prev, *q, *temp, *p;
    curr = t->root; // get the root
    prev = NULL;

    // search for the key
    while ((curr != NULL) && (curr->data != key))
    {
        prev = curr;
        if (key > curr->data)
            curr = curr->right;
        else
            curr = curr->left;
    }
    if (curr == NULL)
        printf("Key not found.\n");
    // one subtree or no subtrees present
    else if ((curr->left == NULL) || (curr->right == NULL))
    {
        if (curr->left == NULL)
            q = curr->right;
        else
            q = curr->left;
        if (prev == NULL) // deleteing the root
            t->root = q;  // make q the new root
        else if (curr == prev->left)
            prev->left = q;
        else
            prev->right = q;
        free(curr);
    }
    else // both subtrees present
    {
        // find the inorder successor of curr
        p = NULL;
        temp = curr->right;
        while (temp->left != NULL)
        {
            p = temp;
            temp = temp->left;
        }
        // temp is the inorder successor
        curr->data = temp->data; // copy value of temp to curr
        if (p != NULL)
            p->left = temp->right;
        else
            curr->right = temp->right;
        free(temp);
    }
}

int isIdent(tnode_t *t1, tnode_t *t2)
{
    int l, r;
    if ((t1 == NULL) && (t2 == NULL))
    {
        return 1;
    }
    if ((t1 != NULL) && (t2 != NULL))
    {
        if (t1->data == t2->data)
        {
            l = isIdent(t1->left, t2->left);
            r = isIdent(t1->right, t2->right);
            return (l && r);
        }
        return 0;
    }
    return 0;
}
