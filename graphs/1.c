#include <stdio.h>


int main()
 {
   int i,ch,v; 
   int a[100][100],n;
   printf("Enter the number of vertices..");
   scanf("%d",&n);
   creategraph(a,n);
   while(1)
  {
    printf("\n1. Indegree..\n");
    printf("2. Outdgree..\n");
	printf("3.Display..\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: printf("Enter the vertex..\n");
                   scanf("%d",&v);
                   i=indegree(a, n, v);
                   printf("Indegree of a vertex =%d",i);
                   break;
     case 2:   printf("Enter the vertex..\n");
                   scanf("%d",&v);
                   i=outdegree(a,n,v);
                   printf("out degree of a vertex =%d",i);
                   break;     
      case 3: display(a,n);
                   break;
    }
  }
}


void display(int (*a)[100],int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
}

void creategraph(int (*a)[100],int n){
    int i,j;
    for ( i = 0; i < n; i++){
        for ( j = 0; j < n; j++){
            a[i][j] = 0;
        }
    }
    while (1){
        printf("enter for i >> ");
        scanf("%d",&i);
        printf("enter for j >> ");
        scanf("%d",&j);
        if((i == -9) && (j == -9)){
            break;
        }
        if(i >= 0 && i < n && j >= 0 && j < n){
            a[i][j] = 1;
        }else{
             printf("Invalid vertices! Please enter values between 0 and %d\n", n - 1);
        }   
    }    
}


int indegree(int (*a)[100],int n,int v){
    int count = 0;
    for (int i = 0; i < n; i++){
        if(a[i][v] == 1){
            count++;
        }
    }
    return count;
}

int outdegree(int (*a)[100],int n,int v){
    int count = 0;
    for (int i = 0; i < n; i++){
        if(a[v][i] == 1){
            count++;
        }
    }
    return count;
}

void dfs(int (*a)[100],int n,int v,int visited[]){
    visited[v] = 1;
    printf("%d\n",v);
    for (int i = 0; i < n; i++){
        if(a[v][i] == 1 && !visited[i]){
            dfs(a,n,i,visited);
        }
    }
    
}