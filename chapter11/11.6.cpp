#include <stdio.h>
#include <stdlib.h>
#define STRLEN 100
int is_within(char *, char);
int main(void)
{
    char str[STRLEN];
    char ch;

    while (true)
    {
        printf("Enter the string: ");
        gets(str);
        printf("Enter the character: ");
        scanf("%c", &ch);
        if (is_within(str, ch))
            printf("%c exist in the string.\n", ch);
        else
            printf("%c doesn't exist in the string.\n", ch);
    }

    system("pause");
    return 0;
}
int is_within(char *str, char c)
{
    while (*str)
    {
        if (*str == c)
            return 1;
        else
            str++;
    }
    return 0;
}