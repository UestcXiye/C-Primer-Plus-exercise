#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    FILE *fp1, *fp2;
    int number[20][30]; // 保存数字的数组
    int character[20][31]; // 保存字符的数组
    int i, j;
    char ch;

    if ((fp1 = fopen("number.txt", "r")) == NULL)
    {
        fprintf(stderr, "Can't open file:%s\n", "number.txt");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < 20; i++) // 从文件读入数字到数组
        for (j = 0; j < 60; j++)
        {
            if ((ch = getc(fp1)) != EOF && isdigit(ch))
                number[i][j / 2] = (int)ch - 48;
        }
    if (fclose(fp1) != 0)
        fprintf(stderr, "Error in closing file number.txt\n");
    for (i = 0; i < 20; i++) //  把数字转换为字符，并存入到character数组中
        for (j = 0; j < 30; j++)
        {
            switch (number[i][j])
            {
            case 0:
                character[i][j] = ' ';
                break;
            case 1:
                character[i][j] = '.';
                break;
            case 2:
                character[i][j] = '\'';
                break;
            case 3:
                character[i][j] = ':';
                break;
            case 4:
                character[i][j] = '~';
                break;
            case 5:
                character[i][j] = '*';
                break;
            case 6:
                character[i][j] = '=';
                break;
            case 7:
                character[i][j] = '^';
                break;
            case 8:
                character[i][j] = '%';
                break;
            case 9:
                character[i][j] = '#';
                break;
            default:
                break;
            }
        }
    for (i = 0; i < 20; i++)
        character[i][30] = '\0';
    if ((fp2 = fopen("result.txt", "a+")) == NULL)
    {
        fprintf(stderr, "Can't open file:%s\n", "result.txt");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < 20; i++) // 把character数组的字符，读入到文件中
    {
        for (j = 0; j < 31; j++)
            putc(character[i][j], fp2);
        putc('\n', fp2);
    }
    rewind(fp2);
    puts("Content output:");
    while ((ch = getc(fp2)) != EOF) // 输出文件的内容
        putc(ch, stdout);
    if (fclose(fp2) != 0)
        fprintf(stderr, "Error in closing file result.txt\n");

    system("pause");
    return 0;
}