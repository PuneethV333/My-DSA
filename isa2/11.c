#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int key;
    char name[100];
    int mark;
}elem_t;



void insert(elem_t* ht,int size,int key,char *name,int *count){
    int index = key%size;
    int g = index;
    for (int i = 1; i <= size; i++){
        if(ht[g].mark == 0){
            ht[g].key = key;
            strcpy(ht[g].name,name);
            ht[g].mark = 1;
            (*count)++;
            return;
        }
        g = (index + i*i)%size;
    }   
}


void delete(elem_t* ht,int size,int key,int *n){
    int index = key%size;
    int i = index;
    int count = *n;
    int h = 0,j = 0;

    while (j < count){
        if(ht[i].mark == 1){
            j++;
            if(ht[i].key == key){
                ht[i].mark = 0;
                (*n)--;
                return;
            }
        }
        h++;
        i = (index+h*h)%size;
    }
    
    printf("Key not found");
}

int search(elem_t* ht,int size,int key){
    int index = key%size;
    int i = index;
    
    for (int j = 1; j <= size; j++){
        if(ht[i].mark == 1){
            if(ht[i].key == key){
                return i;
            }
        }
        i = (index+j*j)%size;
    }
    return -1;
}

void delete2(elem_t* ht,int size,int key,int *n){
    int res = search(ht,size,key);
    if(res == -1){
        printf("Key not found\n");
        return;
    }
        ht[res].mark = 0;
        (*n)--;
    
}