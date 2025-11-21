#include <stdio.h>
#include <stdlib.h>


typedef struct trieNode{
    struct trieNode* child[256];
    int endofWord;
}node_t;


typedef struct{
    int index;
    node_t* m;
}stack_t;



node_t* getNewNode(){
    node_t* temp = malloc(sizeof(node_t));
    for (int  i = 0; i < 256; i++){
        temp->child[i] = NULL;
    }
    temp->endofWord = 0;
    return temp;
}


void insert(node_t* root,char* key){
    node_t *crr = root;
    int index;
    for (int i = 0; key[i] != '\0'; i++){
        index = key[i];
        if(crr->child[index] == NULL){
            crr->child[index] = getNewNode();
        }
        crr->endofWord = 1;
    }
    
}


int sreach(node_t* root,char *key){
    node_t* crr = root;
    int j;

    for (int i = 0; key[i] != '\0'; i++){
        j = key[i];
        if(crr->child[j] == NULL){
            return 0;
        }
        crr = crr->child[j];
    }

    return (crr->endofWord);
}


void display(node_t* root){
    char word[100];
    int lenght = 0;
    for (int i = 0; i < 256; i++){
        word[lenght++] = i;


        if(root->child[i]->endofWord == 1){
            for (int j = 0; j < lenght; j++){
                printf("%c",word[j]);
            }
            printf('\n');
            display(root->child[i]);
        }
    }
    lenght--;
    return;
}


