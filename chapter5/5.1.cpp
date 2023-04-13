/* 5.11.1 */
#include <stdio.h>
#include <stdlib.h>
#define MINUTE 60
int main(void)
{
    int minutes;
    printf("Please input your minutes(>0): ");
    scanf("%d", &minutes);
    while (minutes > 0)
    {
        printf("%d minute(s) equal to %d hour(s) and %d minutes.\n", minutes, minutes / MINUTE, minutes % MINUTE);
        printf("Try again: ");
        scanf("%d", &minutes);
    }
    printf("Bye!\n");

    system("pause");
    return 0;
}

