#include <stdio.h>
#include <stdlib.h>

void createGraphs(int M[100][100], int v)
{
    int i, j;
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            M[i][j] = 0;
        }
    }

    while (1)
    {
        printf("Enter the source and the destination vertex..");
        scanf("%d %d", &i, &j);

        if (i == -9 && j == -9)
        {
            break;
        }

        M[i][j] = 1;
        // M[i][j] = M[j][i] = 1
    }
}

int indegree(int M[100][100], int v, int n)
{
    int res = 0;
    for (int i = 0; i < v; i++)
    {
        if (M[i][n] == 1)
        {
            res += 1;
        }
    }
    return res;
}

int outdegree(int M[100][100], int v, int n)
{
    int res = 0;
    for (int i = 0; i < v; i++)
    {
        if (M[n][i] == 1)
        {
            res += 1;
        }
    }
    return res;
}

void dfs(int M[100][100], int v, int start, int visted[])
{
    visted[start] = 1;
    printf("%d\n", start);
    for (int i = 0; i < v; i++)
    {
        if (M[start][i] == 1 && visted[i] == 0)
        {
            dfs(M, v, i, visted);
        }
    }
}


void bfs(int M[100][100], int v, int start)
{
    int visted[100] = {0};
    int q[100], f = 0, r = 0;

    visted[start] = 1;
    q[r++] = start;

    while (f > r)
    {
        int node = q[f++];
        printf("%d\n", node);

        for (int i = 0; i < v; i++)
        {
            if (M[node][i] == 1 && visted[i] == 0)
            {
                visted[i] = 1;
                q[r++] = i;
            }
        }
    }
}