#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    char ch;
    FILE *fp1, *fp2;
    unsigned count = 0;

    if (argc != 3)
    {
        fprintf(stderr, "Usage:%s [filename] [filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    else
    {
        if ((fp1 = fopen(argv[1], "rb")) == NULL)
        {
            fprintf(stderr, "Can't open %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        if ((fp2 = fopen(argv[2], "wb")) == NULL)
        {
            fprintf(stderr, "Can't open %s\n", argv[2]);
            exit(EXIT_FAILURE);
        }
    }
    // 拷贝
    while ((ch = getc(fp1)) != EOF)
    {
        if (islower(ch))
            ch = toupper(ch);
        putc(ch, fp2);
        count++;
    }

    fclose(fp1);
    fclose(fp2);
    printf("文件%s的内容已经拷贝到%s，共复制%lu个字符。\n", argv[1], argv[2], count);

    system("pause");
    return 0;
}
