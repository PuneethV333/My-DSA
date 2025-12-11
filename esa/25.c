#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int key;
    char name[100];
    int mark;
}node_t;

void insert(node_t* ht,int key,int size,char* name,int *count){
    int index = key%size;

    while(ht[index].mark != 0){
        index = (index + 1)%size;
    }

    ht[index].key = key;
    strcpy(ht[index].name,name);
    ht[index].mark = 1;
    (*count)++;
}


int search(node_t* ht,int key,int count,int size){
    int index = key%size;
    for(int i = 0;i < count;){
        if(ht[index].mark == 1){
            i++;
            if(ht[index].key == key){
                return index;
            }
        }
        index = (index+1)%size;
    }
    return -1;
}


void delete(node_t* ht,int size,int key,int *count){
    int res = search(ht,key,*count,size);
    if(res != -2 && res != -1){
        ht[res].mark = 0;
        (*count)--;
    }
}