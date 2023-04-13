#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int number;
    bool isPrime;

    printf("Enter a positive number: ")''
    scanf("%d", &number);
    for (int i = 2; i <= number; i++)
    {
        isPrime = true;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
            }
        }
        if (isPrime)
        {
            printf("%dÊÇËØÊý¡£\n", i);
        }
    }

    system("pause");
    return 0;
}