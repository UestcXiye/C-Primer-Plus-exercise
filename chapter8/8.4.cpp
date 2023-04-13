#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(void)
{
    char ch;
    FILE *fp;
    char fname[50]; // 存储文件名
    int count_alpha = 0, count_word = 0;
    bool start_count = false;

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
        // 如果没有开始计数并且字符是个字母，则开始计数
        if (isalpha(ch) && start_count == false)
        {
            start_count = true;
        }
        // 如果已经有开始计数并且字符不是个字母，则停止计数，单词数量+1
        else if (!isalpha(ch) && start_count == true)
        {
            start_count = false;
            count_word++;
        }
        // 如果已经有开始计数并且字符是个字母，开始字母计数，字母数量+1
        else if (isalpha(ch) && start_count == true)
        {
            count_alpha++;
        }
    }
    printf("总共读取了%d个单词，%d个字母，平均每个单词%f个字母。\n", count_word, count_alpha, (float)count_alpha / count_word);
    fclose(fp); // 关闭文件

    system("pause");
    return 0;
}
