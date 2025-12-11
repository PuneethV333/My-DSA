#include <stdio.h>
#include <stdlib.h>

void top_down(int* h,int n){
    for(int i = 1;i <= n;i++){
        int j = i;
        int key = h[j];
        int k = (j-1)/2;


        while(j > 0 && key > h[k]){
            h[j] = h[k];
            j = k;
            k = (j-1)/2;
        }
        h[j] = key;
    }
}

void bottom_up(int* h,int n){
    for(int i = (n-1)/2; i >= 0;i--){
        int j = i;
        int key = h[j];
        int k = 2*j+1;

        while(k <= n){
            if(k+1 <= n && h[k+1] > h[k]){
                h[j] = h[k];
                j = k;
                k = 2*i+1;
            }else{
                break;
            }
        }
        h[j] = key;
    }
}


typedef struct{
    int data;
    int pty;
}elem_t;



void insert(elem_t* hpq,int n,int pty,int *count){
    elem_t temp;
    temp.data = n;
    temp.pty = pty;
    int i = *count;
    (*count)++;
    int j = (i-1)/2;
    while(i > 0 && temp.pty < hpq[j].pty){
        hpq[i] = hpq[j];
        i = j;
        j = (i-1)/2;
    }
    hpq[i] = temp;
}


elem_t delete(elem_t* hpq,int* count){
    elem_t temp = hpq[0];
    (*count)--;
    hpq[0] = hpq[*count];
    heapify(hpq,*count -1);
    return temp;
}


void heaplify(elem_t* hpq,int n){
    elem_t key = hpq[0];
    int j = 0;
    int i = 2*j +1;

    while(i <= n){
        if(i+1 <= n && hpq[i+1].pty < hpq[i].pty){
            i++;
        }
        if(key.pty < hpq[i].pty){
            hpq[j] = hpq[i];
            i = j;
            j = 2*i +1;
        }else{
            break;
        }
    }
    hpq[j] = key;
}