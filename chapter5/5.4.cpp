/* 5.11.4 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float m;
    printf("Enter a height in centimeters:");
    while (~scanf("%f", &m) && m > 0)
    {
        int f = m / 31; //不用int型接收的话，用%d打印float类型会因为字节截断输出而出现问题
        printf("%.1f cm = %d feet, %.1f inches\n", m, f, m * 0.39370 - f * 12);
        printf("Enter a height in centimeters (<=0 to quit):");
    }
    printf("bye\n");

    system("pause");
    return 0;
}

