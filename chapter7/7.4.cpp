#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char ch;
    int replace_period = 0, replace_exclamation = 0;

    while ((ch = getchar()) != '#')
    {
        if (ch == '.')
        {
            printf("!");
            replace_period++;
        }
        else if (ch == '!')
        {
            printf("!!");
            replace_exclamation++;
        }
        else
        {
            putchar(ch);
        }
    }
    printf("\nÌæ»»¾äºÅ%d´Î£¬Ìæ»»¸ÐÌ¾ºÅ%d´Î¡£\n", replace_period, replace_exclamation);

    system("pause");
    return 0;
}