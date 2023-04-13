/* 5.11.6 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count, sum, d;
    count = 0;
    sum = 0;
    printf("input d: ");
    scanf("%d", &d);
    while (count++ < d)
    {
        sum = sum + count * count;
    }
    printf("sum = %d\n", sum);

    system("pause");
    return 0;
}

