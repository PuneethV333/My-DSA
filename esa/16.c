#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *item;
    int f,r,size;
}dqueue_t;

void insertStart(dqueue_t* q,int x){
    if((q->f == 0 && q->r == q->size -1) || (q->f == q->r + 1)){
        printf("Full\n");
        return;
    }
    if(q->f == -1){
        q->r = q->f = 0;
    }else if(q->f == 0){
        q->f = q->size -1;
    }else{
        (q->f)--;
    }
    (q->item)[q->f];
}


void insertEnd(dqueue_t* q,int x){
    if((q->f == 0 && q->r == q->f -1) || (q->f == q->r+1)){
        printf("Full\n");
        return;
    }
    if(q->f == -1){
        q->f = q->r = 0;
    }else if (q->r == q->size -1){
        q->r = 0;
    }else{
        q->r++;
    }
    q->item[q->r] = x;
}



void deleteStart(dqueue_t* q){
    if(q->f == -1){
        printf("Empty\n");
        return;
    }
    if(q->f == q->r){
        q->f = q->r -1;
    }else if(q->f == q->size -1){
        q->f = 0;
    }else{
        q->f++;
    }
}


void deleteEnd(dqueue_t* q){
    if(q->f == -1){
        printf("Empty\n");
        return;
    }

    if(q->r == q->f){
        q->f = q->r -1;
    }else if (q->r == 0){
        q->r = q->size -1;
    }else{
        q->r--;
    }
}