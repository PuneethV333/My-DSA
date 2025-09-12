#include <stdio.h>
#include <stdlib.h>

int addDigits(int num)
{
    while (num > 10)
    {
        int res = 0;

        while (num > 0)
        {
            res += num % 10;
            num /= 10;
        }
        num = res;
    }

    return num;
}

int main()
{
    int n;
    scanf("%d", &n);
    int res = addDigits(n);
    printf("%d", res);
    return 0;
}