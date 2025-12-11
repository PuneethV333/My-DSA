#include <stdio.h>
#include <stdlib.h>

int sumArr(int arr[],int n){
    if(n == 0){
        return 0;
    }
    return arr[n-1]+sumArr(arr,n-1);
}



int min(int arr[],int n){
    if(n == 0){
        return arr[0];
    }
    int k = min(arr,n-1);
    if(k<arr[n]){
        return k;
    }
    return arr[n];
}


int max(int arr[],int n){
    if(n == 0){
        return arr[0];
    }
    int k = max(arr,n-1);
    if(k>arr[n]){
        return k;
    }
    return arr[n];
}

void towerofHanoi(int n,char src,char aux,char dest){
    if(n == 1){
        printf("move disk 1 from %c to %c\n",src,dest);
        return;
    }
    towerofHanoi(n-1,src,dest,aux);
    printf("Move disk %d from %c to %c\n",n,src,dest);
    towerofHanoi(n-1,aux,src,dest);
}