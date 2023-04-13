/* 5.11.2 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    printf("Please input a integer: ");
    scanf("%d",&n);
    for(int i=0;i<11;i++)
    {
        printf("%d ",n++);
    }
    printf("\n");

    system("pause");
    return 0;
}

