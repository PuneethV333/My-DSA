#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *next;
}node_t;



void createGraph(node_t **a,int n){
    int i,j;
    for (i = 0; i < n; i++){
        a[i] = NULL;
    }

    while (1){
        printf("Enter the source and destination of the edge..");
        scanf("%d %d",&i,&j);

        if(i == -9 && j == -9){
            break;
        }

        insert(a,i,j);
    }
    
    
}

void insert(int **a,int i,int j){
    node_t* temp = malloc(sizeof(node_t));
    temp->data = j;
    temp->next = a[i];
    a[i] = temp;
}


int indegree(int **a,int n,int v){
    node_t* temp = NULL;
    int res = 0;

    for (int i = 0; i < n; i++){
        temp = a[i];
        while (temp != NULL){
            if(temp->data == v){
                res++;
            }

            temp = temp->next;
        }
        
    }
    return res;
}

int outdegree(int **a,int v){
    node_t* temp = NULL;
    int res = 0;

    temp = a[v];
    while (temp != NULL){
        res++;
        temp = temp->next;
    }
    return res;
}



void bfs(node_t** a,int start,int n){
    int visted[100] = {0};
    visted[start] = 1;
    int q[100],f = 0,r = 0;

    q[r++] = start;
    while (f < r){
        int u = q[f++];
        printf("%d\n",u);
        node_t* temp = a[u];
        while (temp != NULL){
            int v = temp->data;

            if(!visted[v]){
                visted[v] = 1;
                q[r++] = v;
            }
            temp = temp->next;
        }   
    }
}


void dfs_util(node_t** a,int v,int visted[]){
    visted[v] = 1;
    printf("%d\n",v);

    node_t *temp  = a[v];

    while (temp != NULL){
        int u = temp->data;
        if(!visted[u]){
            dfs_util(a,u,visted);
        }
        temp = temp->next;
    }
    
}

void dfs(node_t* a[],int start,int n){
    int visited = {0};
    dfs_util(a,start,visited);
}