#include <stdio.h>
#include <stdlib.h>
double min(double, double);
int main(void)
{
    double a, b;

    printf("Enter 2 values of double :");
    if (scanf("%lf %lf", &a, &b) == 2)
    {
        printf("The smaller one in %lf and %lf is %lf\n", a, b, min(a, b));
    }
    system("pause");
    return 0;
}
double min(double x, double y)
{
    return x > y ? y : x;
}