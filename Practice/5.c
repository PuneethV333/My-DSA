#include<stdio.h>
#include<stdlib.h>
// struct col_node {
// 	int col;
// 	int data;
// 	struct col_node *next_col;
// };

// struct row_node {
// 	int row;
// 	struct col_node *next_col;
// 	struct row_node *next_row;
// };

// typedef struct row_node rownode_t;
// typedef struct col_node colnode_t;

// rownode_t *create_rows(int); // create rows
// void insert_end(rownode_t*, int,int); 
// void insert_matrix(rownode_t*, int(*)[],int, int); 
// void display(rownode_t*);

// int main()
// {
//   int a[10][10];
//   int i,j,row,col;
//   rownode_t *head,*p;
//   head=NULL;
//   printf("Enter the row and cols..\n");
//   scanf("%d %d",&row, &col);

  
//   printf("Enter the data for the matrix..\n");
//   for(i=0;i<row;i++)
//   {
//      for(j=0;j<col;j++)
//       scanf("%d",&a[i][j]);
//   }
//   //storing the matrix as a multi list...;
  
//   head=create_rows(row);
//   insert_matrix(head,a,row,col);
//   //displaying the matrix as a list

//   display(head)
// }aaa


typedef struct col_node{
    int col;
    int data;
    struct col_node* next_col;
}col_t;

typedef struct row_node{
    int row;
    struct row_node* next_row;
    struct col_node* next_col;
}row_t;

int main(){


    row_t* head = NULL;

    row_t* row0 = malloc(sizeof(row_t));
    row0->row = 0;
    row0->next_col = NULL;
    row0->next_row = NULL;

    col_t* c00 = malloc(sizeof(col_t));
    c00->col = 0;
    c00->data = 5;
    c00->next_col = NULL;
    row0->next_col = c00;

    col_t* c03 = malloc(sizeof(col_t));
    c03->col = 3;
    c03->data = 8;
    c03->next_col = NULL;
    c00->next_col = c03; 

    head = row0;

    row_t* row1 = malloc(sizeof(row_t));
    row1->row = 1;
    row1->next_col = NULL;
    row1->next_row = NULL;

    col_t* c11 = malloc(sizeof(sizeof(col_t)));
    c11->col = 1;
    c11->data = 10;
    c11->next_col = NULL;
    row1->next_col = c11;

    row0->next_row = row1;

    row_t* row2 = malloc(sizeof(row_t));
    row2->row = 2;
    row2->next_row = NULL;
    row2->next_col = NULL;

    col_t* c20 = malloc(sizeof(row_t));
    


}
