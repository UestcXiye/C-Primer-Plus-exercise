#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char ch;
    FILE *fp;
    char fname[50]; // 存储文件名
    int count = 0;

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

        if (ch == '\n')
        {
            printf("\\n:%d\n", ch);
            count = 0; // 每次遇到换行符打印新的一行
        }
        else if (ch == '\t')
        {
            printf("\\t:%d  ", ch);
        }
        else if (ch == ' ')
        {
            printf("' ':%d  ", ch);
        }
        else if (ch < ' ')
        {
            printf("^%c:%d  ", ch + 64, ch);
        }
        else
        {
            printf("%c:%d ", ch, ch);
        }
        if (++count % 10 == 0)
        {
            count = 0;
            putchar('\n');
        }
    }
    fclose(fp); // 关闭文件

    system("pause");
    return 0;
}
