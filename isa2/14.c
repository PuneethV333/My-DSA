#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct{
    int key;
    char name[100];
    bool mark;
}node_t;


void insert(node_t* ht,int key,int size,int *count,char* name){
    int index = key%size;
    int j = index;
    for (int i = 0; i < size; i++){
        if(ht[j].mark == false){
            ht[j].key = key;
            strcpy(ht[j].name,name);
            ht[j].mark = true;
            (*count)++;
            return;
        }
        j = (index + i*hash1(key))%size;
    }
    

    printf("cannot insert..\n");
    return;
}


int hash1(int key){
    return (5 - (key%5));
}


int search(node_t* ht,int key,int size){
    int index = key%size;
    int j = index;

    for (int i = 0; i < size; i++){
        if(ht[j].mark == true && ht[j].key == key){
            return j;
        }
        j = (index + i*hash1(key))%size;
    }
    return -1;
}

void delete(node_t* ht,int key,int size,int *count){
    const int res = search(ht,key,size);
    if(res == -1){
        printf("Key not found\n");
        return;
    }

    ht[res].mark = false;
    (*count)--;
}