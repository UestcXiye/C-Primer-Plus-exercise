#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "months.h"

int days(char *input); // 获取月份名，计算天数

int main()
{
    char input[20];
    int total_days;

    printf("请输入月份名：(按q退出程序)\n");
    while (scanf("%s", input) == 1 && input[0] != 'q') // 输入q才停止循环
    {
        total_days = days(input); // 调用函数
        if (total_days > 0)       // 总天数大于0，说明有对应月份号
        {
            printf("总天数是：%d\n", total_days);
        }
        else
        {
            printf("输入有误。\n");
        }
        printf("请输入下一个月份名：(按q退出程序)\n");
    }
    printf("程序结束\n");

    system("pause");
    return 0;
}

int days(char *input)
{
    int i;
    int total = 0;
    int num = 0;

    input[0] = toupper(input[0]);      // 第一个字母转成大写
    for (i = 1; input[i] != '\0'; i++) // 循环到输入为止，都转为小写字母
    {
        input[i] = tolower(input[i]);
    }
    for (i = 0; i < 12; i++)
    {
        if (strcmp(input, months[i].name) == 0) // 和结构数组每一个元素的名字比较
        {
            num = months[i].monumb; // 找到对应月份，把月份号赋值给num
            break;
        }
    }
    if (num == 0) // 没有对应月份号
    {
        total = 0;
    }
    else
    {
        for (i = 0; i < num; i++) // 有对应月份号
        {
            total += months[i].days; // 求和
        }
    }
    return total; // 返回总天数
}
