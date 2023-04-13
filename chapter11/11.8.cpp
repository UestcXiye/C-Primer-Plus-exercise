#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define STRLEN 100
void get_nextval(const char *t, int a[], int n);
char *string_in(char *s1, char *s2);
int main(void)
{
    char s1[STRLEN];
    char s2[STRLEN];

    while (true)
    {
        printf("Enter s1: ");
        scanf("%s", s1);
        printf("Enter s2: ");
        scanf("%s", s2);
        char *x = string_in(s1, s2);
        if (x)
            printf("s1 obtains s2, the address of the beginning %c is %p.\n", *x, x);
        else
            printf("s1 doesn't exist s2.\n");
    }

    system("pause");
    return 0;
}
void get_nextval(const char *t, int a[], int n)
{
    int i = 0, j = -1;
    a[0] = -1;
    while (i < n)
    {
        if (j == -1 || t[i] == t[j])
        {
            ++i;
            ++j;
            if (t[i] != t[j])
                a[i] = j;
            else
                a[i] = a[j];
        }
        else
            j = a[j];
    }
}
char *string_in(char *s1, char *s2)
{
    int n2 = 0, n1 = 0;
    char *a = s2;
    while (*a)
    {
        n2++;
        a++;
    }
    a = s1;
    while (*a)
    {
        n1++;
        a++;
    }
    int next[n2];
    get_nextval(s2, next, n2);
    int i = 0, j = -1;
    while (i < n1 && j < n2)
    {
        if (j == -1 || s1[i] == s2[j])
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if (j == n2)
        return &s1[i - n2];

    return NULL;
}