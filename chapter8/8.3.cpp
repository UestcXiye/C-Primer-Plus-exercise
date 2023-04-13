#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(void)
{
    char ch;
    FILE *fp;
    char fname[50]; // 存储文件名
    int count_upper = 0, count_lower = 0;

    printf("Enter the file name: ");
    scanf("%s", fname);
    fp = fopen(fname, "r"); // 只读模式打开文件
    if (fp == NULL)
    {
        printf("Failed to open file.\n");
        exit(1); // 退出程序
    }
    // getc(fp)从打开的文件中获取一个字符
    while ((ch = getc(fp)) != EOF)
    {
        if (isupper(ch))
            count_upper++;
        if (islower(ch))
            count_lower++;
    }
    printf("大写字母个数：%d，小写字母个数：%d\n", count_upper, count_lower);
    fclose(fp); // 关闭文件

    system("pause");
    return 0;
}
