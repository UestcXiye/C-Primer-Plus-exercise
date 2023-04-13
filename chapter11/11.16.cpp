#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define STRLEN 100
void print_original(char *);
void print_upper(char *);
void print_lower(char *);
int main(int argc, char *argv[])
{
    char ch;
    char str[STRLEN];

    if (argc == 1)
        ch = 'p';
    else if (argc == 2)
        ch = argv[1][1];
    if (argc <= 2)
    {
        printf("Enter a string: ");
        scanf("%s", str);
        switch (ch)
        {
        case 'p':
        case 'P':
            print_original(str);
            break;
        case 'u':
        case 'U':
            print_upper(str);
            break;
        case 'l':
        case 'L':
            print_lower(str);
            break;
        }
    }
    else
        printf("arguments error!\n");

    system("pause");
    return 0;
}

void print_original(char *str)
{
    printf("result: %s\n", str);
}

void print_upper(char *str)
{
    int i = 0;

    while (str[i])
    {
        str[i] = toupper(str[i]);
        i++;
    }
    printf("result: %s\n", str);
}

void print_lower(char *str)
{
    int i = 0;

    while (str[i])
    {
        str[i] = tolower(str[i]);
        i++;
    }
    printf("result: %s\n", str);
}