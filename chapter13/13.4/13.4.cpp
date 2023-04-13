#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main(int argc, char **argv)
{
    FILE *fp;
    char ch;
    
    for (int i = 1; i < argc; i++)
    {
        if ((fp = fopen(argv[i], "r")) != NULL)
        {
            printf("File %d:%s\n", i, argv[i]);
            while ((ch = getc(fp)) != EOF)
            {
                putchar(ch);
            }
            putchar('\n');
            fclose(fp);
        }
        else
        {
            fprintf(stderr, "Open %s failed\n", argv[i]);
            exit(EXIT_FAILURE);
        }
    }
    printf("Done\n");

    system("pause");
    return 0;
}