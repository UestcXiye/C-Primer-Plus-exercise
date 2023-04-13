/* 6.16.11 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[8];
    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 7; i > -1; i--)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    system("pause");
    return 0;
}

