#include <stdio.h>
#include <stdlib.h>
#define COLS 3
void copy_arr(double *target1, double *source, int n);
void show_arr(double arr[][COLS], int n);
int main(void)
{
    int n = 3;
    double a[n][COLS] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    double copy[n][COLS];

    printf("Original array: \n");
    show_arr(a, n);
    for (int i = 0; i < n; i++)
    {
        copy_arr(copy[i], a[i], COLS);
    }
    printf("Copy array: \n");
    show_arr(copy, n);

    system("pause");
    return 0;
}
void copy_arr(double *target1, double *source, int n)
{
    for (int i = 0; i < n; i++)
    {
        target1[i] = source[i];
    }
}
void show_arr(double arr[][COLS], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%.2lf ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}