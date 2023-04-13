/* 6.16.3 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    for(int i = 0; i < 6; i++)
    {
        char c = 'F';
        for(int j = 0; j < i + 1; j++)
        {
            printf("%c", c - j);
        }
        printf("\n");
    }
    system("pause");
    return 0;
    }
}

