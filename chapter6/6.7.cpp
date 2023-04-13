/* 6.16.7 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char l[80];
    scanf("%s", &l);
    int n = strlen(l);
    for (int i = n - 1; i > -1; i--)
    {
        printf("%c", l[i]);
    }
    printf("\n");

    system("pause");
    return 0;
}

