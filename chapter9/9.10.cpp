#include <stdio.h>
#include <stdlib.h>
void to_base_n(unsigned long n, unsigned int x);
int main(void)
{

    unsigned long number;
    unsigned int base;
    char prompt[] = "Enter an integer and a base(2~10):\n(Enter q to quit) ";

    printf("%s", prompt);
    while (scanf("%lu %hd", &number, &base) == 2)
    {
        printf("Equivalent: ");
        to_base_n(number, base);
        putchar('\n');
        printf("%s", prompt);
    }
    printf("Done.\n");

    system("pause");
    return 0;
}
void to_base_n(unsigned long n, unsigned int x) // 递归函数
{

    int r;
    if (x < 2 || x > 10)
    {
        printf("Base Error! Please try again.\n");
        return;
    }
    r = n % x;
    if (n >= x)
        to_base_n(n / x, x);
    printf("%d", r);

    return;
}