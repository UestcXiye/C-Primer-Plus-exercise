/* 6.16.17 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a = 1e6;
    int n = 0;
    while (a > 0)
    {
        n++;
        a *= 1.08;
        a -= 1e5;
    }
    printf("%d\n", n);

    system("pause");
    return 0;
}

