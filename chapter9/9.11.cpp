#include <stdio.h>
#include <stdlib.h>
int fibonacci(int i);
int main()
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%d\t\n", fibonacci(i));
    }
    system("pause");
    return 0;
}
int fibonacci(int n)
{
    int a = 1, b = 1, sum;
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 1;
    for (int i = 3; i <= n; i++)
    {
        sum = a + b;
        a = b;
        b = sum;
    }
    return sum;
}