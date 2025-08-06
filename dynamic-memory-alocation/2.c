#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    char name[50];
    int roolno;
    int marks[3];
}student_t;

void read_array(int *arr, int n){
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }    
}

void read_data(student_t *ps){
    printf("Enter the name : ");
    scanf("%s", ps->name);
    printf("Enter rool number : ");
    scanf("%d", &ps->roolno);
    printf("Enter marks : ");
    read_array(ps->marks, 3);
}


int main(){
    student_t *ps = (student_t*)malloc(sizeof(student_t));
    read_data(ps);
    return 0;   
}
