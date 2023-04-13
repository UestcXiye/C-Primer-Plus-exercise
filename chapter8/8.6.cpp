#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char get_first(FILE *fp);
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
    ch = get_first(fp);
    printf("%c\n", ch);
    fclose(fp);

    system("pause");
    return 0;
}
char get_first(FILE *fp)
{
    char ch;
    while (isspace(ch = getc(fp)))
        continue;
    return ch;
}