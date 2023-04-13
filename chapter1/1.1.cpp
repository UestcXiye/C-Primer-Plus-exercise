// inch_to_cm.c -- 将英寸单位转换成厘米单位
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    float inch;
    float cm;

    printf("Please input a inch:");
    scanf("%f", &inch);
    cm = 2.54 * inch;
    printf("%f inches is equal to %f cm.\n", inch, cm);

    system("pause");
    return 0;
}