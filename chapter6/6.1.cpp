/* 6.16.1 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char l[26];
    for(int i = 0; i < 26; i++)
    {
        l[i] = 'a' + i;
    }
    for(int i = 0; i < 26; i++)
    {
        printf("%c ", l[i]);
    }
    printf("\n");

    system("pause");
    return 0;
}

