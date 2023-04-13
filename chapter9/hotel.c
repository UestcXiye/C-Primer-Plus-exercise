/*hotel.c --酒店管理函数*/
#include <stdio.h>
#include "hotel.h"

int menu(void)
{
    int code, status;
    printf("Enter the number of ths desired hotel1:\n");
    printf("1) Fairfield Arms            2) Hotel Olympic\n");
    printf("3) Chertworthy Plaza         4) The Stockton\n");
    printf("5) quit\n");
    printf("%s%s\n", STARS, STARS);
    while ((status = scanf("%d", &code)) != 1 ||
           (code < 1 || code > 5))
    {
        if (status != 1)
            scanf("%*s"); //处理非整数输入
        printf("Enter an integer from 1 to 5, please.\n");
    }
    return code;
}

int getnights(void)
{
    int nights;
    printf("How many nights are needed? ");
    while (scanf("%d", &nights) != 1)
    {
        scanf("%*s"); //处理非整数输入
        printf("Please enter an integer ,such as 2.\n");
    }
    return nights;
}
void showprice(double rate, int nights)
{
    int n;
    double total = 0.0;
    double factor = 1.0;

    for (n = 1; n <= nights; n++, factor *= DISCOUNT)
        total += rate * factor;
    printf("THe total cost will be $%0.2f.\n", total);
    printf("%s%s\n", STARS, STARS);
}