#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int guess = 50;
    int g_max = 100, g_min = 1; // 猜测的最大值和最小值
    char response;

    printf("Pick an integer from 1 to 100. I will try to guess it.\n");
    printf("Respond with a y if my guess is right and with an n if it's wrong.\n");
    printf("Uh...is your number %d?\n", guess);
    while ((response = getchar()) != 'y')
    {
        if (response == 'l')
        {
            g_max = guess;
            guess = (g_min + g_max) / 2;
            printf("Well, then, is it %d?\n", guess);
        }
        else if (response == 'u')
        {
            g_min = guess;
            guess = (g_min + g_max) / 2;
            printf("Well, then, is it %d?\n", guess);
        }
        else
        {
            printf("Sorry, I understand only l, u or y.\n");
        }
        while (getchar() != '\n')
            continue;
    }
    printf("I knew I could do it!\n");

    system("pause");
    return 0;
}
