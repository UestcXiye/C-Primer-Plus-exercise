/* 6.16.13 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[8];
    for (int i = 0, j = 2; i < 8; i++, j *= 2)
    {
        a[i] = j;
    }
    int n = 0;
    do
    {
        printf("%d ", a[n]);
    } while (++n < 8);
    printf("\n");

    system("pause");
    return 0;
}

