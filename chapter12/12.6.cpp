#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n;

    for (int i = 0; i < 10; ++i)
    {
        n = 1000;
        srand(i);
        // srand(time(0));
        int *x = (int *)calloc(11, sizeof(int));
        while (n--)
        {
            x[rand() % 11 + 1]++;
        }
        for (int j = 1; j < 11; ++j)
        {
            printf("%d ", x[j]);
        }
        putchar('\n');
        // free(x);
    }

    system("pause");
    return 0;
}