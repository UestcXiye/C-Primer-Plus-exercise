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
    printf("\n�滻���%d�Σ��滻��̾��%d�Ρ�\n", replace_period, replace_exclamation);

    system("pause");
    return 0;
}