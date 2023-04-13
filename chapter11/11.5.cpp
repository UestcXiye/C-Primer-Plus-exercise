#include <stdio.h>
#include <stdlib.h>
#define STRLEN 100
char *index(char *, char);
int main(void)
{
    char str[STRLEN];
    char ch;
    char *ch_index;

    printf("Enter the string: ");
    gets(str);
    printf("Enter the character: ");
    scanf("%c", &ch);
    ch_index = index(str, ch);
    if (ch_index != NULL)
        printf("I found it! %c is in %p.\n", *ch_index, ch_index);
    else
        printf("%c doesn't exist in the string.\n", ch);

    system("pause");
    return 0;
}
char *index(char *str, char c)
{
    while (*str)
    {
        if (*str == c)
            return str;
        else
            str++;
    }
    return NULL;
}