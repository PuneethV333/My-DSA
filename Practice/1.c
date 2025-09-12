#include <stdio.h>
#include <stdlib.h>

int main()
{

    int row, col;
    printf("row : ");
    scanf("%d", &row);
    printf("col : ");
    scanf("%d", &col);
    int **p = malloc(sizeof(int *) * row);
    for (int i = 0; i < row; i++)
    {
        p[i] = malloc(sizeof(int) * col);
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d", p[i][j]);
        }
        printf('\n');
    }
    return 0;
}