#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char ch;
    FILE *fp;
    char fname[50]; // 存储文件名

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
        putchar(ch);
    }
    fclose(fp); // 关闭文件

    system("pause");
    return 0;
}
