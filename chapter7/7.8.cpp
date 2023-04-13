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

int main(void)
{
    int num;
    bool judge = false; // 这里的标志位必须为false,以防用户一开始就输入非数字
    double pay_rate;
    double hours;
    double gross, tax, net;

    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $8.75/hr         2) $9.33/hr\n");
    printf("3) $10.00/hr        4) $11.20/hr\n");
    printf("5) quit\n");
    printf("******************************************************************\n");
    //读取正确输入，直达是1-5之间才退出循环
    while (scanf("%d", &num) == 1)
    {
        judge = true; //每次循环标志位置为true
        switch (num)
        {
        case 1:
            pay_rate = PAY_RATE1;
            break;
        case 2:
            pay_rate = PAY_RATE2;
            break;
        case 3:
            pay_rate = PAY_RATE3;
            break;
        case 4:
            pay_rate = PAY_RATE4;
            break;
        case 5:
            printf("Bye!\n");
            break;
        default:
            printf("\nPlease enter the right number!\n");
            printf("*****************************************************************\n");
            printf("Enter the number corresponding to the desired pay rate or action:\n");
            printf("1) $8.75/hr         2) $9.33/hr\n");
            printf("3) $10.00/hr        4) $11.20/hr\n");
            printf("5) quit\n");
            printf("******************************************************************\n");
            judge = false;
        }

        if (judge)
            break;
    }
    if (judge && num != 5)
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