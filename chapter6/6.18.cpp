/* 6.16.18 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 5;
    for (int i = 1; n <= 150; i++)
    {
        printf("%d\n", n);
        n -= i;
        n *= 2;
    }

    system("pause");
    return 0;
}

