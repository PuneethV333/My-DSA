#include <stdio.h>
#include <stdlib.h>

typedef struct trieNode{
    struct trieNode* child[256];
    int endOfWord;
}node_t;

typedef struct{
    int index;
    node_t* m;
}stack_t;


node_t* getnode(){
    node_t* temp = malloc(sizeof(node_t));
    for(int i = 0;i < 256;i++){
        (temp->child)[i] = NULL;
    }
    temp->endOfWord = 0;
    return temp;
}


void insert(node_t* root,char* key){
    node_t* crr = root;
    int index;
    for(int i = 0;key[i] != '\0';i++){
        index = key[i];
        if((crr->child)[index] == NULL){
            (crr->child)[index] = getnode();
        }
        crr = crr->child[index];
    }
    crr->endOfWord = 1;
}


int serach(node_t* root,char *key){
    node_t* crr = root;
    for(int i = 0;key[i] != '\0';i++){
        int j = key[i];
        if(crr->child[j] == NULL){
            return 0;
        }
        crr = crr->child[j];
    }
    return crr->endOfWord;
}

void display(node_t* root){
    char word[100];
    int lenght = 0;
    for(int i = 0;i < 256;i++){
        word[lenght++] = i;
        if(root->child[i]->endOfWord == 1){
            for(int j = 0;j < lenght;j++){
                printf("%c ",word[j]);
            }
            printf('\n');
            display(root->child[i]);
        }
    }
    lenght--;
    return;
}

int isEmpty(node_t* root){
    for(int i = 0;i < 256;i++){
        if(root->child[i] != NULL){
            return 0;
        }
    }
    return 1;
}


node_t* delete(node_t* root,char* key,int depth){
    if(root == NULL){
        return NULL;
    }

    if(key[depth] == '\0'){
        if(root->endOfWord == 1){
            root->endOfWord = 0;
        }

        if(isEmpty(root)){
            free(root);
            root = NULL;
        }
        return root;
    }
    int index = (unsigned char)key[depth];
    root->child[index] = delete(root->child[index],key,depth+1);

    if(isEmpty(root) && root->endOfWord == 0){
        free(root);
        root = NULL;
    }
    return root;
}