#include <stdio.h>
#include <stdlib.h>

// create 2 stuctures one for storing head and another one for creating node
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct dlist
{
    struct node *head;
};

void insert_first(struct dlist *ptr, int key)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = key;
    temp->next = temp->prev = NULL;
    if (ptr->head == NULL)
    {
        ptr->head = temp;
    }
    else
    {
        temp->next = ptr->head;
        ptr->head->prev = temp;
        ptr->head = temp;
    }
}

void insert_end(struct dlist *ptr, int key)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = key;
    temp->next = temp->prev = NULL;
    if (ptr->head == NULL)
    {
        ptr->head = temp;
    }
    else
    {
        struct node *pres = ptr->head;
        while (pres->next != NULL)
        {
            pres = pres->next;
        }
        temp->prev = pres;
        pres->next = temp;
    }
}

void delete_first(struct dlist *ptr)
{
    if (ptr->head == NULL)
    { // case i -> if no elements
        printf("Empty linked list\n");
    }
    else if (ptr->head->next == NULL)
    { // case ii -> only one element
        free(ptr->head);
        ptr->head = NULL;
    }
    else
    { // iii -> normal case
        struct node *pres = ptr->head;
        ptr->head = pres->next;
        pres->next->prev = NULL;
        free(pres);
    }
}