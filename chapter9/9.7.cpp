#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int char_to_index(char);
int main(void)
{
    FILE *fp;
    char fname[50];
    char ch;

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
        int index;
        if ((index = char_to_index(ch)) > 0)
            printf("%c is a alpha, it's index is %d.\n", ch, index);
    }
    fclose(fp); // 关闭文件

    system("pause");
    return 0;
}
int char_to_index(char ch)
{
    if (isalpha(ch))
    {
        if (isupper(ch))
            return ch - 'A' + 1;
        else
            return ch - 'a' + 1;
    }
    else
        return -1;
}