#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tnode{
    int data;
    bool lthread;
    bool tthread;
    struct tnode* left;
    struct tnode* right;
}node_t;


typedef struct tree{
    node_t* root;
}tree_t;



