#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node_t;

typedef struct{
    node_t* root;
}graph_t;

void createGraph(node_t** a,int n){
    int i,j;
    for(int i =  0;i<n;i++){
        a[i] = NULL;
    }

    while(1){
        printf("Entre value... : ");
        scanf("%d %d",&i,&j);
        if(i == -9 && j == -9){
            break;
        }

        node_t* temp = malloc(sizeof(node_t));
        temp->data = j;
        temp->next = a[i];
        a[i] = temp;
    }
}


int indegree(int **a,int n,int v){
    int res = 0;
    for(int i = 0;i < n;i++){
        node_t* temp = a[i];
        while(temp != NULL){
            if(temp->data == v){
                res++;
            }
            temp = temp->next;
        }
    }
    return res;
}


int outdegree(int** a,int n,int v){
    int res = 0;
    node_t* temp = a[v];
    while(temp != NULL){
        res++;
        temp = temp->data;
    }
    return res;
}

void dfs_util(node_t** a,int v,int visted[]){
    visted[v] = 1;
    printf("%d ",v);
    node_t* temp = a[v];

    while(temp != NULL){
        int u = temp->data;
        if(!visted[v]){
            dfs_util(a,u,visted);
        }
        temp = temp->next;
    }
}



void bfs(node_t** a,int start,int n){
    int visited[100] = {0};
    visited[start] = 1;
    int q[100],f = 0,r =0;
    q[r++] = start;
    while(f > r){
        int u = q[f++];
        printf("%d ",u);
        node_t* temp = a[u];
        while(temp != NULL){
            int v = temp->data;

            if(!visited[v]){
                visited[v] = 1;
                q[r++] = v;
            }
            temp = temp->next;
        }
    }
}

