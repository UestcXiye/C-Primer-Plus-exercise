#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_LEN 256

void aFunc(FILE *fp1, FILE *fp2)
{
    char file1[LINE_LEN], file2[LINE_LEN];

    while (fgets(file1, LINE_LEN, fp1) && fgets(file2, LINE_LEN, fp2))
    {
        printf("%s\n", file1);
        printf("%s\n", file2);
    }
    while (fgets(file1, LINE_LEN, fp1))
    {
        printf("%s\n", file1);
    }
    while (fgets(file2, LINE_LEN, fp2))
    {
        printf("%s\n", file2);
    }
}

void bFunc(FILE *fp1, FILE *fp2)
{
    char file1[LINE_LEN], file2[LINE_LEN];

    while (fgets(file1, LINE_LEN, fp1) && fgets(file2, LINE_LEN, fp2))
    {
        printf("%s%s\n", file1, file2);
    }
    while (fgets(file1, LINE_LEN, fp1))
    {
        puts(file1);
    }
    while (fgets(file2, LINE_LEN, fp2))
    {
        puts(file2);
    }
}

int main(int argc, char **argv)
{
    FILE *fp1, *fp2;

    if (argc != 3)
    {
        fprintf(stderr, "Usage:%s [filename] [filename]", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fp1 = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((fp2 = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    aFunc(fp1, fp2); // »òbFunc()

    system("pause");
    return 0;
}