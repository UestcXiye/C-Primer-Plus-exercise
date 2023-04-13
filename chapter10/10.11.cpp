#include <stdio.h>
#include <stdlib.h>
#define COLS 5
void double_arr(int rows, int cols, int arr[][COLS]);
void show_arr(int rows, int cols, int arr[][COLS]);
int main(void)
{
    int n = 3;
    int m = 5;
    int a[n][COLS] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};

    printf("Original array: \n");
    show_arr(n, m, a);
    double_arr(n, m, a);
    printf("After doubling: \n");
    show_arr(n, m, a);

    system("pause");
    return 0;
}
void double_arr(int rows, int cols, int arr[][COLS])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] *= 2;
        }
    }
}
void show_arr(int rows, int cols, int arr[][COLS])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%-3d ", arr[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}