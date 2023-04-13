/* 6.16.10 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    printf("Enter lower and upper integer limits:");
    while (scanf("%d %d", &a, &b) == 2 && a < b)
    {
        int sum = 0;
        for (int i = a; i <= b; i++)
        {
            sum += i * i;
        }
        printf("The sums of the squares from %d to %d is %d\n", a * a, b * b, sum);
        printf("Enter next set of limits: ");
    }
    printf("Done\n");

    system("pause");
    return 0;
}

