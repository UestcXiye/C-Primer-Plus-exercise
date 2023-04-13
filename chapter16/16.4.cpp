#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(double a);

int main()
{
    double a;

    printf("Enter a number of seconds(q to quit): ");
    while (scanf("%lf", &a) == 1)
    {
        delay(a);
        printf("Enter a number of seconds(q to quit): ");
    }
    printf("Bye!\n");
    
    system("pause");
    return 0;
}

void delay(double a)
{
    double s = (double)clock();
    double f = 0;
    while ((a - f) > 0.00000001)
    {
        f = ((double)clock() - s) / CLOCKS_PER_SEC;
    }
    printf("%.2lfs have passed.\n", f);
}