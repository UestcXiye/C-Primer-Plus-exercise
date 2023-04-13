/* 6.16.4 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
 
    char c = 'A';
    for(int i = 1; i < 7; i++)
    {
        for(int j = 0; j < i; j++, c++)
        {
            printf("%c", c);
        }
        printf("\n");
    }
    
    system("pause");
    return 0;
}

