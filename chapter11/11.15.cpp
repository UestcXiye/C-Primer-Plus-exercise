#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <typeinfo>
#define STRLEN 100
int my_atoi(char *);
int main(void)
{
    char s[STRLEN];

    printf("Enter a string: ");
    scanf("%s", s);
    if (my_atoi(s))
    {
        printf("turn to integer: %d.\n", my_atoi(s));
        printf("my_atoi(s) is %s.\n", typeid(my_atoi(s)).name());
    }
    else
        printf("not all digits!\n");

    system("pause");
    return 0;
}
int my_atoi(char *str)
{
    int n = 0;
    while (*str != '\0')
    {
        n *= 10;
        if (!isdigit(*str))
            return 0;
        else
        {
            n += *str - '0';
            str++;
        }
    }
    return n;
}