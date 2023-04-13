#include <stdio.h>
#include <stdlib.h>
#define COLS 5
void copy_arr(int rows, int cols, double target[][COLS], double source[][COLS]);
void show_arr(int rows, int cols, double arr[][COLS]);
int main(void)
{
    int n = 3;
    int m = 5;
    double a[n][COLS] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
    double copy[n][COLS];

    printf("Original array: \n");
    show_arr(n, m, a);
    copy_arr(n, m, copy, a);
    printf("Copy array: \n");
    show_arr(n, m, copy);

    system("pause");
    return 0;
}
void copy_arr(int rows, int cols, double target[][COLS], double source[][COLS])
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            target[i][j] = source[i][j];
}
void show_arr(int rows, int cols, double arr[][COLS])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%-5.2lf ", arr[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}