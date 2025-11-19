#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct {
    int data,pty;
}elem;



void pinsert(elem *hpq,elem key,int *count){
    int i,j;
    i = *count;
    hpq[i] = key;

    j = (i-1)/2;
    while ((i>0) && (key.pty < hpq[j].pty)){
        hpq[i] = hpq[j];
        i = j;
        j = (i-1)/2;
    }
    hpq[i] = key;
}

void display(elem *hpq,int count){
    if(count == 0){
        printf("Heap is empty\n");
        return;
    }
    for (int i = 0; i < count; i++){
        printf("%d -> %d\n",hpq[i].data,hpq[i].pty);
    } 
}



void heaplify(elem *hpq,int count){
    elem key = hpq[0];
    int j = 0;
    int i = 2*j + 1;    

    while(i < count){
        if((i+1 < count) && (hpq[i+1].pty < hpq[i].pty)){
            i++;
        }else if(key.pty > hpq[i].pty){
            hpq[j] = hpq[i];
            j = i;
            i = 2*j + 1;
        }else{
            break;
        }
    }
    hpq[j] = key;
}