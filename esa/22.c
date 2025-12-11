#include <stdio.h>
#include <stdio.h>

void dfs(int** M,int v,int strat,int visted[]){
    visted[strat] = 1;
    for(int i = 0;i<v;i++){
        if(M[strat][i] == 1 && !visted[i]){
            dfs(M,v,i,visted);
        }
    }
}

int connectd(int M[100][100],int v){
    int visted[100] = {0};
    dfs(M,v,0,visted);
    for(int i = 0;i < v;i++){
        if(!visted[i]){
            return 0;
        }
    }
    return 1;
}

int stronglyconnected(int M[100][100],int v){
    for(int i = 0;i < v;i++){
        int visted[100] = {0};
        dfs(M,v,0,visted);
        for(int j = 0;j < v;j++){
            if(!visted[j]){
                return 0;
            }
        }
    }
    return 1;
}


void removeEdge(int a[100][100],int b[100][100],int v){
    for(int i = 0;i < v;i++){
        for(int j = 0;j < v;j++){
            b[i][j] = 0;
        }
    }


    for(int i = 0;i < v;i++){
        for(int j = 0;j < v;j++){
            if(a[i][j] == 1){
                b[i][j] = b[j][i] = 1;
            }
        }
    }

}



int findpath(int M[100][100],int start,int goal,int v,int items[],int *lenght,int visted[]){
    visted[start] = 1;
    for(int i = 0;i < v;i++){
        if(M[start][i] == 1 && !visted[i]){
            items[++(*lenght)] = i;
            
            if(i == goal){
                return 1;
            }
            if(findpath(M,i,goal,v,items,lenght,visted)){
                return 1;
            }
            (*lenght)++;
        }
    }
    return 0;
}
