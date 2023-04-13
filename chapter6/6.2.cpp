/* 6.16.2 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < i + 1; j++)
        {
            printf("$");
        }
        printf("\n");
    }

    system("pause");
    return 0;
}

