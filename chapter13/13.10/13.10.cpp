#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 41

int main(void)
{
    FILE *fp;
    char name[40];
    long pos;
    char ch;

    printf("Please input the filename: ");
    scanf("%s", name);
    if ((fp = fopen(name, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", name);
        exit(EXIT_FAILURE);
    }
    printf("Input the index(q or -1 to quit):");
    while (scanf("%ld", &pos) == 1 && pos > 0)
    {
        fseek(fp, pos, SEEK_SET);
        while ((ch = getc(fp)) != EOF && ch != '\n')
        {
            putchar(ch);
        }
        putchar('\n');
        printf("Input the index(q or -1 to quit):");
    }

    system("pause");
    return 0;
}