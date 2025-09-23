#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *link;
} node_t;

typedef struct list
{
    node_t *head;
} list_t;

int min(int arr[],int size){
    if(size == 1){
        return arr[0];
    }
    int min_rest = min(arr,size-1);
    return (arr[size-1] < min_rest) ? arr[size-1] : min_rest;
}

int maximum( list_t *head){
    if(head == NULL){
        return -1;
    }
    if(head->head->link == NULL){
        return head->head;
    }

    int max_res = maximum(head->head->link);
    return (head->head->key > max_res) ? head->head->link : max_res;
}



int minimum(int arr[],int n){
    int k;
    if(n == 0)
        return arr[1];
    k = minimum(arr,n-1);
    if(k<arr[n])
        return k;
    return arr[n];
}