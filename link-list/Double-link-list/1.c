#include <stdio.h>
#include <stdlib.h>


// create 2 stuctures one for storing head and another one for creating node
struct node{
    int n;
    struct node* prev;
    struct node* next;
};

struct dlist{
    struct node* head;
};