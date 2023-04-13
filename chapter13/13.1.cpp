#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ch;
    FILE *fp;
    unsigned count = 0;
    char fileName[50];

    printf("Please input the filename: ");
    gets(fileName);
    if ((fp = fopen(fileName, "r")) == NULL)
    {
        printf("Can't open %s\n", fileName);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("\nFile %s has %lu characters\n", fileName, count);

    system("pause");
    return 0;
}
