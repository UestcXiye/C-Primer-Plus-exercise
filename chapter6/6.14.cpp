/* 6.16.14 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a[8], b[8];
    for (int i = 0; i < 8; i++)
    {
        scanf("%lf", &a[i]);
        if (i > 0)
        {
            b[i] = b[i - 1] + a[i];
        }
        else
        {
            b[i] = a[i];
        }
    }
    for (int i = 0; i < 8; i++)
    {
        printf("%.2lf ", b[i]);
    }
    printf("\n");

    system("pause");
    return 0;
}

