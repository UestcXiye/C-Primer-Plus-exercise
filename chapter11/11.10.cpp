#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRLEN 100
void remove_space(char *str);
int main(void)
{
    char s[STRLEN];

    printf("Enter a string: ");
    gets(s);
    remove_space(s);
    printf("All thr spaces are removed: %s\n", s);

    system("pause");
    return 0;
}
void remove_space(char *str)
{
    int begin = 0;
    int end = 0;
    while (str[end] != '\0')
    {
        if (str[end] != ' ')
        {
            str[begin] = str[end];
            begin++;
            end++;
        }
        else
            end++;
    }
    str[begin] = '\0';
}