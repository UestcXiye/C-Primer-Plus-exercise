/* 6.16.15 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[256];
    scanf("%s", a);
    int n = strlen(a);
    for (int i = n - 1; i > -1; i--)
    {
        printf("%c", a[i]);
    }
    printf("\n");

    system("pause");
    return 0;
}

