/* 6.16.8 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double a, b;
    printf("input a and b:");
    while (scanf("%lf %lf", &a, &b) == 2)
    {
        printf("%lf\n", (a - b) / (a * b));
        printf("input again(input two q to exit):");
    }
    printf("Bye!");

    system("pause");
    return 0;
}

