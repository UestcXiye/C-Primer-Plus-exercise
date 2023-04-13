/* 5.11.7 */
#include <stdio.h>
#include <stdlib.h>
void func(double x)
{
    printf("%lf\n", x * x * x);
}

int main()
{
    double x;
    printf("Please input a number: ");
    scanf("%lf", &x);
    func(x);

    system("pause");
    return 0;
}

