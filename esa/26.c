#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int key,mark;
    char name[100];
}elem_t;


void insert(elem_t* ht,int size,int key,char* name,int *count){
    int index = key%size;
    int g = index;
    for(int i = 1;i <= size;i++){
        if(ht[g].mark == 0){
            ht[g].key = key;
            strcpy(ht[g].name,name);
            ht[g].mark = 1;
            (*count)++;
            return;
        }
        g = (index+ i*i)%size;
    }
}


int search(elem_t* ht,int key,int size){
    int index = key%size;
    int j = index;
    for(int i = 1;i <= size;i++){
        if(ht[i].mark == 1){
            if(ht[i].key == key){
                return i;
            }
        }
        j = (index + i*i)%size;
    }
    return -1;
}

void delete(elem_t* ht,int key,int size,int* count){
    int res = search(ht,key,size);
    if(res!= -1){
        ht[res].mark = 0;
        (*count)--;
        return;
    }
}