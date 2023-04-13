/* 6.16.6 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int l, u;
    printf("Please input lower limit and upper limit:");
    scanf("%d %d", &l, &u);
    for (int i = l; i <= u; i++)
    {
        printf("%10d%10d%10d\n", i, i * i, i * i * i);
    }

    system("pause");
    return 0;
}

