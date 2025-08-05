#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    char name[50];
    int marks[3];
    int rool_no;
}STUDENT_T;

typedef struct result{
    int total;
    float avg;
}RESEUT_T;


void read_array(int arr[3]){
    for (int i = 0; i < 3; i++)
    {
        printf("%d.\t",(i+1));
        scanf("%d",&arr[i]);
    }
    
}



STUDENT_T input() {
    STUDENT_T temp;
    printf("Enter the name : ");
    scanf("%s",temp.name);
    printf("Enter the marks : \n");
    read_array(temp.marks);
    printf("Enter the rool number : ");
    scanf("%d",&temp.rool_no);
    
    return temp;
}


RESEUT_T compute_result(STUDENT_T *s){
    RESEUT_T temp;
    temp.total = 0;
    for (int i = 0; i < 3; i++){
        temp.total += s->marks[i];
    }
    temp.avg = temp.total/3; 
    return temp;
}











int main(){
    STUDENT_T s = input();
    RESEUT_T r = compute_result(&s);
    return 0;
}