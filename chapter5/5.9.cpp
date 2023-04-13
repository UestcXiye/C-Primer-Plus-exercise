/* 5.11.9 */
#include <stdio.h>
#include <stdlib.h>

void Temperatures(double t)
{
    const double w0 = 5.0 / 9.0;
    const double w1 = 32.0;
    const double k = 273.16;
    
    printf("%.2lf\n", t);
    printf("%.2lf\n", w0 * (t - w1));
    printf("%.2lf\n", k + w0 * (t - w1));
}

int main()
{
    double t;
    printf("Please input a temperature: ");
    while (scanf("%lf", &t) == 1)
    {
        Temperatures(t);
        printf("input again: ");
    }

    system("pause");
    return 0;
}

