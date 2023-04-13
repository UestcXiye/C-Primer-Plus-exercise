#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void func(double *, double *, double *);
int main(void)
{
    double x, y, z;

    printf("Enter 3 values of double: ");
    scanf("%lf %lf %lf", &x, &y, &z);
    func(&x, &y, &z);
    printf("After sorting, now x is %lf, y is %lf, z is %lf.\n", x, y, z);

    system("pause");
    return 0;
}
void func(double *a, double *b, double *c)
{
    double max = *a, mid, min;
    if (*b > max)
        max = *b;
    if (*c > max)
        max = *c;
    if (*a == max)
    {
        mid = *b > *c ? *b : *c;
        min = *b > *c ? *c : *b;
    }
    if (*b == max)
    {
        mid = *a > *c ? *a : *c;
        min = *a > *c ? *c : *a;
    }
    if (*c == max)
    {
        mid = *a > *b ? *a : *b;
        min = *a > *b ? *b : *a;
    }
    *a = min;
    *b = mid;
    *c = max;
}