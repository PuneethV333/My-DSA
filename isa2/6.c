#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int data;
    int pty;
}elem_t;


void insert(elem_t* hpq,elem_t key,int *count){
    int i = *count;
    hpq[i] = key;
    ++(*count);
    int j = (i-1)/2;

    while (i > 0 && key.pty < hpq[j].pty){
        hpq[i] = hpq[j];
        i = j;
        j = (i-1)/2;
    }
    hpq[i] = key;
}


elem_t delete(elem_t* hpq,int *count){
    elem_t key = hpq[0];
    hpq[0] = hpq[*count-1];
    --*count;
    heapify(hpq,*count-1);
    return key;
}



void heapify(elem_t* hpq,int n){
    elem_t key;
    int i,j;
    j = 0;
    i = 2*j+1;
    key = hpq[0];


    while (i <= n){
        if((i+1) <= n && hpq[i+1].pty < hpq[i].pty){
            i++;
        }
        if(key.pty < hpq[i].pty){
            hpq[j] = hpq[i];
            i = j;
            j = 2*i+1;
        }
        else{
            break;
        }
    }
    hpq[j] = key;
}