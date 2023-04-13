#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char ch;
    int count=0;

    while ((ch = getchar()) != '#')
    {
        count++;
        putchar(ch);
        printf("-%d ", ch);
        if(count % 8 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
    
    system("pause");
    return 0;
}