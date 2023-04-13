#include <stdio.h>
#include <stdlib.h>
#define BASEPAY1 17850
#define BASEPAY2 23900
#define BASEPAY3 29750
#define BASEPAY4 14875
#define RATE1 0.15
#define RATE2 0.28
void print_prompt();
int main(void)
{
    int type;
    double income;
    double basepay;
    double tax;

    print_prompt();
    while (scanf("%d", &type) == 1)
    {
        switch (type)
        {
        case 1:
            basepay = BASEPAY1;
            break;
        case 2:
            basepay = BASEPAY2;
            break;
        case 3:
            basepay = BASEPAY3;
            break;
        case 4:
            basepay = BASEPAY4;
            break;
        }
        if (type > 0 && type < 5)
        {
            printf("Enter your income: ");
            scanf("%lf", &income);
            printf("\n");
            if (income <= basepay)
            {
                tax = income * RATE1;
            }
            else
            {
                tax = BASEPAY1 * RATE1 + (income - BASEPAY1) * RATE2;
            }
            printf("Your tax is %lf.\n", tax);
            print_prompt();
        }
        else if (type == 5)
        {
            printf("Bye!\n");
            break;
        }
        else
        {
            printf("Please enter right number.\n");
            print_prompt();
        }
    }

    system("pause");
    return 0;
}
void print_prompt()
{
    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired tax type or action:\n");
    printf("1) 单身             2) 户主\n");
    printf("3) 已婚，共有       4) 已婚，离异\n");
    printf("5) quit\n");
    printf("******************************************************************\n");
}