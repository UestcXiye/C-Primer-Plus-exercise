#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 40
int main(void)
{
    FILE *fp;
    char words[SIZE];
    int i = 0; // i为单词编号

    if ((fp = fopen("file.txt", "a+")) == NULL)
    {
        fprintf(stderr, "Can't open file.txt.\n");
        exit(EXIT_FAILURE);
    }
    puts("Enter the words,press ");
    puts("# at the beginning of a line to terminate:");
    while (fscanf(fp, "%s", words) == 1) // 统计原有的单词数
        i++;
    while (fscanf(stdin, "%40s", words) == 1 && words[0] != '#') // 遇到空白字符，输入单词结束
        fprintf(fp, "%d%s\n", ++i, words);                       // 读入新单词，并为其编号
    rewind(fp);
    puts("File content:");
    while (fscanf(fp, "%s", words) == 1)
        puts(words);
    while (fclose(fp) != 0)
        fprintf(stderr, "Error in closing file.\n");

    return 0;
}