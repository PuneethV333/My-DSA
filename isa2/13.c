#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int key;
    int mark;
    char name[100];
}node_t;


void insert(node_t* ht,int size,int key,char* name,int *count){

    if(size == count){
        printf("Table is full..\n");
        return;
    }
    int index = key%size;

    while (ht[index].mark != 0){
        index = (index+1)%size;
    }

    ht[index].key = key;
    strcpy(ht[index].name,name);
    ht[index].mark = 1;

    (*count)++;
}

int search(node_t* ht,int size,int key,int count){
    if(count == 0){
        return -2;
    }    
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
    int res = search(ht,size,key,*count);
    if(res == -1){
        printf("Key not found\n");
        return;
    }
    
    if(res == -2){
        printf("table is empty\n");
        return;
    }

    ht[res].mark = 0;
    (*count)--;


}