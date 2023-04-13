/* 5.11.3 */
#include <stdio.h>
#include <stdlib.h>
#define WEEK 7
int main(void)
{
    int day;
    printf("Please input your days(>0): ");
    scanf("%d", &day);
    while (day > 0)
    {
        printf("%d days are %d weeks, %d days.\n", day, day / WEEK, day % WEEK);
        printf("Try again: ");
        scanf("%d", &day);
    }
    printf("Bye!\n");

    system("pause");
    return 0;
}

