#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 41

int main(void)
{
    FILE *fp;
    char name[40];
    char c[256];
    char s[256];

    printf("Please input the filename: ");
    scanf("%s", name);
    if ((fp = fopen(name, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", name);
        exit(EXIT_FAILURE);
    }
    printf("Please input a string: ");
    scanf("%s", c);
    while (fgets(s, 256, fp))
    {
        if (strstr(s, c))
        {
            puts(s);
        }
    }

    system("pause");
    return 0;
}