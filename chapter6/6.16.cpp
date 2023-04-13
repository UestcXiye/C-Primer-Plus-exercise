/* 6.16.16 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    double a = 100.0, b = 100.0;
    while (b <= a)
    {
        a += 10.0;
        b *= 1.05;
        n++;
    }
    printf("%d %lf %lf\n", n, a, b);

    system("pause");
    return 0;
}
