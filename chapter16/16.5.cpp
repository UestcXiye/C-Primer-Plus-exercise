#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 10

void Print_sd(int *, int, int);
int Find_df(int *, int);

int main()
{
    srand(time(0));

    int data[LEN] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int count;

    printf("Enter a number, I'll pick you randomly(enter q to quit):\n");
    while (scanf("%d", &count) && count <= 10)
    {
        // printf("%d", count);
        Print_sd(data, LEN, count);
    }

    printf("Bye!\n");

    system("pause");
    return 0;
}

void Print_sd(int *ar, int n, int count)
{
    int index[LEN] = {0};
    int i = 0;

    printf("The result of random selection: ");
    while (i < count)
    {
        index[i] = Find_df(index, n);
        // printf("%d ", index[i]);
        printf("%d ", ar[index[i] - 1]);
        i++;
    }
    printf("\n");
}

int Find_df(int *index, int n)
{
    int key = rand() % 10 + 1;

    //    printf("%d", key);
    for (int i = 0; i < n; i++)
        if (key == index[i]) // 如果找到相同的下标，就向下递归
        {
            key = Find_df(index, n);
            break;
        }

    return key;
}