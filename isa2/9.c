#include <stdio.h>
#include <stdlib.h>

void dfs(int M[100][100],int v,int start,int visted[]){
    visted[start] = 1;
    for (int i = 0; i < v; i++){
        if(M[start][i] == 1 && visted[i] == 0){
            dfs(M,v,i,visted);
        }
    }
}


int connected(int M[100][100],int v){
    int visted[100] = {0};
    dfs(M,v,0,visted);
    for (int i = 0; i < v; i++){
        if(visted[i] == 0){
            return 0;
        }
    }
    return 1;   
}


int stronglyConnected(int M[100][100],int v){
    for (int i = 0; i < v; i++){
        int visted[100] = {0};
        dfs(M,v,i,visted);

        for (int j = 0; j < v; j++){
            if(visted[j] == 0)
                return 0;
        }
    }
    return 1;
}

int weakConnection(int M[100][100],int v){
    int visted[100] = {0};
    dfs(M,v,0,visted);
    for (int i = 0; i < v; i++){
        if(visted[i] == 0){
            return 0;
        }
    }
    return 1;
}


void removeEdge(int a[100][100],int b[100][100],int v){
    for (int i = 0; i < v; i++){
        for (int j = 0; j < v; j++){
            b[i][j] = 0;
        }
    }

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if(a[i][j] == 1){
                b[i][j] = b[j][i] = 1;
            }
        }
        
    }
    

}



void createGraph(int M[100][100],int v){
    for (int i = 0; i < v; i++){
        for (int j = 0; j < v; j++){
            M[i][j] = 0;
        }
    }
    int a,b;
    while(1){
        printf("Enter values : \n");
        scanf("%d %d",&a,&b);


        if(a == -9 && b == -9){
            break;
        }

        M[a][b] = 1;
    }
    
}


int findPath(int M[100][100],int start,int destination,int v,int items[],int *lenght,int visted[]){
    visted[start] = 1;
    for (int i = 0; i < v; i++){
        if(M[start][i] == 1 && visted[i] == 0){
            items[++*lenght] = i;
            
            if(i == destination){
                return 1;
            }

            if(findPath(M,i,destination,v,items,lenght,visted)){
                return 1;
            }

            (*lenght)--;
        }
    }
    return 0;
}
