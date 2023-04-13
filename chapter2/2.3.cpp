// practice2_12_3.c
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int year;
    int day;

    year = 22;
    day = 365 * year;
    printf("I am %d years old, which equals to %d days.\n", year, day);

    system("pause");
    return 0;
}
