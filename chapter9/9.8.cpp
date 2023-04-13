// power.c -- 计算数的整数幂
#include <stdio.h>
#include <stdlib.h>
double power(double n, int p); // ANSI函数原型
int main(void)
{
    double x, xpow;
    int exp;
    printf("Enter a number and the positive integer power");
    printf(" to which\nthe number will be raised.Enter q");
    printf(" to quit.\n");
    while (scanf("%lf%d", &x, &exp) == 2)
    {
        if (x == 0 && exp == 0)
            printf("0 to the power 0 is undefined.\n");
        else
        {
            xpow = power(x, exp); // 函数调用
            printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
        }
        printf("Enter next pair of numbers or q to quit.\n");
    }
    printf("Hope you enjoyed this power trip -- bye!\n");

    system("pause");
    return 0;
}
double power(double n, int p) // 函数定义
{
    double pow = 1;
    int i;
    bool negative; // 判断p的正负
    if (p == 0)
        return 1;
    if (n == 0)
        return 0;
    if (p < 0)
    {
        p = -p;
        negative = true;
    }
    else
        negative = false;
    for (i = 1; i <= p; i++)
        pow *= n;
    if (negative)
        return 1 / pow;
    else
        return pow;
}
