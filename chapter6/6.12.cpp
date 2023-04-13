/* 6.16.12 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long t;
    printf("input t:");
    while (scanf("%lld", &t) && t > 0)
    {
        double sum1 = 0, sum2 = 0;
        for (int i = 1; i <= t; i++)
        {
            sum1 += 1.0 / i;
            if (i & 1)
            {
                sum2 += 1.0 / i;
            }
            else
            {
                sum2 -= 1.0 / i;
            }
        }
        printf("%lf %lf\n", sum1, sum2);
        printf("input again:");
    }

    system("pause");
    return 0;
}

