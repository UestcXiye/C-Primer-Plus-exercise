#include <stdio.h>
#include <stdlib.h>
double factorial(unsigned int i);
int main()
{
    int i = 15;
    printf("%d 的阶乘为：%f\n", i, factorial(i));

    system("pause");
    return 0;
}
double factorial(unsigned int i)
{
    if (i <= 1)
    {
        return 1;
    }
    return i * factorial(i - 1);
}