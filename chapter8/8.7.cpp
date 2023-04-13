#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define PAY_RATE1 8.75
#define PAY_RATE2 9.33
#define PAY_RATE3 10.00
#define PAY_RATE4 11.20
#define TIME_BASE 40
#define OVERTIME 1.5
#define BREAK1 300
#define BREAK2 450
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25
void print_prompt(void);
int main(void)
{
    char ch;
    bool judge = false; // 这里的标志位必须为false,以防用户一开始就输入非数字
    double pay_rate;
    double hours;
    double gross, tax, net;

    print_prompt();
    while (scanf("%c", &ch) == 1)
    {
        judge = true; //每次循环标志位置为true
        switch (ch)
        {
        case 'a':
            pay_rate = PAY_RATE1;
            break;
        case 'b':
            pay_rate = PAY_RATE2;
            break;
        case 'c':
            pay_rate = PAY_RATE3;
            break;
        case 'd':
            pay_rate = PAY_RATE4;
            break;
        case 'q':
            printf("Bye!\n");
            break;
        default:
            printf("\nSorry, I understand only a, b, c, d, q, Please try again:\n");
            while (getchar() != '\n')
                continue;
            print_prompt();
            judge = false;
        }

        if (judge)
            break;
    }
    if (judge && ch != 'q')
    {
        printf("Enter your work hours in a week: ");
        scanf("%lf", &hours);
        if (hours > TIME_BASE)
            hours = TIME_BASE + (hours - TIME_BASE) * OVERTIME;
        gross = hours * pay_rate;
        if (gross < BREAK1)
            tax = gross * RATE1;
        else if (gross < BREAK2)
            tax = BREAK1 * RATE1 + (gross - BREAK1) * RATE2;
        else
            tax = BREAK1 * RATE1 + (BREAK2 - BREAK1) * RATE2 + (gross - BREAK2) * RATE3;
        net = gross - tax;
        printf("gross: %.2lf, tax: %.2lf, net: %.2lf\n", gross, tax, net);
    }

    system("pause");
    return 0;
}
void print_prompt(void)
{
    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("a) $8.75/hr         b) $9.33/hr\n");
    printf("c) $10.00/hr        d) $11.20/hr\n");
    printf("q) quit\n");
    printf("******************************************************************\n");
}