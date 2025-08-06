#include <stdio.h>
#include <stdlib.h>

int main(){
    int *array = (int*)malloc(100*sizeof(int));
    if(array == NULL){
        printf("Error!!!\n");
        return 1;
    }
    for(int i = 0; i<5 ; i++){
        array[i] = i+1;
    }
    for(int i = 0; i<5 ; i++){
        printf("%d\n",array[i]);
    }
    free(array);
    return 0;
}
