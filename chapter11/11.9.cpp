#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRLEN 100
void swap(char *, char *);
void reverse(char str[]);
int main(void)
{
    char s[STRLEN];

    printf("Enter a string: ");
    scanf("%s", s);
    reverse(s);
    printf("reverse: %s\n", s);

    system("pause");
    return 0;
}
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
void reverse(char str[])
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
        swap((str + i), (str + len - 1 - i));
}