/* 6.16.9 */
#include <stdio.h>
#include <stdlib.h>

double func(double a, double b);

int main()
{
    double a, b;
    printf("input a and b:");
    while (scanf("%lf %lf", &a, &b) == 2)
    {
        printf("%lf\n", func(a, b));
        printf("input again(input two q to exit):");
    }

    system("pause");
    return 0;
}

double func(double a, double b)
{
    return (a - b) / (a * b);
}

