#include <stdio.h>
#include <stdlib.h>



void top_down(int* h,int n){
    int i,k,j,key;
    for (int i =1; i <= n; i++){
        j = i;
        key = h[j];
        k = (j-1)/2;

        while (j > 0 && key > h[k]){
            h[j] = h[k];
            j = k;
            k = (j-1)/2;
        }
        h[j] = key;
    }
    
}


void bottom_up(int* h,int n){
    int i,k,j,key;
    for (int i = (n-1)/2; i <= 0; i--){
        j = i;
        key = h[j];
        k = 2*j+1;


        while(k <= n){
            if(k+1 <= n && h[k+1] > h[k]){
                k++;
            }
            if(key < h[k]){
                h[j] = h[k];
                j = k;
                k = 2*j + 1;
            }else{
                break;
            }
        }
        h[j] = key;
    }
       
}