#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int number;
    int count_even = 0, count_odd = 0;
    int sum_even = 0, sum_odd = 0;

    while (scanf("%d", &number) == 1 && number != 0)
    {
        if (number % 2)
        {
            count_odd++;
            sum_odd += number;
        }
        else
        {
            count_even++;
            sum_even += number;
        }
    }
    printf("奇数个数:%d,奇数平均值:%f\n偶数个数:%d,偶数平均值:%f\n", count_odd, (float)sum_odd / count_odd, count_even, (float)sum_even / count_even);

    system("pause");
    return 0;
}