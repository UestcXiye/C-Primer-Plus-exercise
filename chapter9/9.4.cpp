#include <stdio.h>
#include <stdlib.h>
double harmonic_average(double, double);
int main(void)
{
    double a, b;

    printf("Enter 2 values of double: ");
    scanf("%lf %lf", &a, &b);
    printf("The harmonic average of %lf and %lf is %lf\n", a, b, harmonic_average(a, b));
    
    system("pause");
    return 0;
}
double harmonic_average(double a, double b)
{
    return 1 / ((1 / a + 1 / b) / 2);
}