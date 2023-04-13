/* 6.16.5 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char c = 'A';
    for(int i = 1; i < 6; i++)
    {
        for(int j = 1 - i; j <= i - 1; j++)
        {
            printf("%c", c - abs(j));
        }
        printf("\n");
        c++;
    }
    
    system("pause");
    return 0;
}

