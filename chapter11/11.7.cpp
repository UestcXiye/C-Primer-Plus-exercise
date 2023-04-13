#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRLEN 100
char *mystrncpy(char *, char *, int);
int main(void)
{
    char s1[STRLEN];
    char s2[STRLEN];
    int n;

    while (true)
    {
        printf("Enter s1: ");
        scanf("%s", s1);
        printf("Enter s2: ");
        scanf("%s", s2);
        printf("Enter n: ");
        scanf("%d", &n);
        mystrncpy(s1, s2, n);
        printf("after copying, s1: %s\n", s1);
    }

    system("pause");
    return 0;
}
char *mystrncpy(char *str1, char *str2, int n)
{
    char *s = str1;
    while (*str2 && n--)
    {
        *str1 = *str2;
        str1++;
        str2++;
    }
    if (n)
        *str1 = '\0';
    return s;
}