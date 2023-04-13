#include <stdio.h>
#include <stdlib.h>
void large_of(double *, double *);
int main(void)
{
    double a, b;

    printf("Enter 2 values of double: ");
    scanf("%lf %lf", &a, &b); //注意参数是指针
    large_of(&a, &b);
    printf("We will change both values to the larger one.\nNow, a is %lf, b is %lf.\n", a, b);

    system("pause");
    return 0;
}
void large_of(double *a, double *b)
{
    int max = *a > *b ? *a : *b;
    *a = *b = max;
}