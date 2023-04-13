#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define LINE_LEN 256

int main(int argc, char **argv)
{
    FILE *fp;
    int count;
    char ch;

    if (argc < 2)
    {
        fprintf(stderr, "Usage:%s [character] / [character] [filename] ... \n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (strlen(argv[1]) != 1)
    {
        fprintf(stderr, "The second parameter should be a character.\n");
        exit(EXIT_FAILURE);
    }
    if (argc == 2)
    {
        count = 0;
        char a[LINE_LEN];

        for (int j = 0; j < LINE_LEN; ++j)
        {
            a[j] = getchar();
        }
        for (int i = 0; i < LINE_LEN; ++i)
        {
            if (a[i] == argv[1][0])
                count++;
        }
        printf("There are %d \'%c\' in the input.\n", count, argv[1][0]);
    }
    else
    {
        for (int i = 2; i < argc; ++i)
        {
            count = 0;
            if ((fp = fopen(argv[i], "r")) == NULL)
            {
                fprintf(stderr, "Can't open %s\n", argv[i]);
                continue;
            }
            while ((ch = getc(fp)) != EOF)
            {
                if (ch == argv[1][0])
                    count++;
            }
            printf("There are %d \'%c\' in %s.\n", count, argv[1][0], argv[i]);
        }
    }

    system("pause");
    return 0;
}