#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int *deckRevealedIncreasing(int *deck, int n, int *returnSize)
{
    int *res = (int *)malloc(n * sizeof(int));
    *returnSize = n;

    qsort(deck, n, sizeof(int), cmp);

    int *queue = (int *)malloc(n * sizeof(int));
    int head = 0, tail = 0;

    for (int i = 0; i < n; i++)
    {
        queue[tail++] = i;
    }

    for (int i = 0; i < n; i++)
    {

        int idx = queue[head % n];
        head++;
        res[idx] = deck[i];

        if (head < tail)
        {
            queue[tail % n] = queue[head % n];
            tail++;
            head++;
        }
    }

    free(queue);
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);

    int *deck = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &deck[i]);
    }

    int returnSize;
    int *ans = deckRevealedIncreasing(deck, n, &returnSize);

    for (int i = 0; i < returnSize; i++)
    {
        printf("%d\n", ans[i]);
    }

    free(deck);
    free(ans);
    return 0;
}
