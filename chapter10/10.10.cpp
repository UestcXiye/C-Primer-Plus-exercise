#include <stdio.h>
#include <stdlib.h>
void show_arr(int *arr, int n);
void add_arr(const int *arr1, const int *arr2, int *sum, int n);
int main(void)
{
    int n = 5;
    int a[n] = {1, 3, 5, 7, 9};
    int b[n] = {2, 4, 6, 8, 10};
    int sum[n];

    printf("array a: ");
    show_arr(a, n);
    printf("array b: ");
    show_arr(b, n);
    add_arr(a, b, sum, n);
    printf("array sum: ");
    show_arr(sum, n);

    system("pause");
    return 0;
}
void show_arr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    putchar('\n');
}
void add_arr(const int *arr1, const int *arr2, int *sum, int n)
{
    for (int i = 0; i < n; i++)
        sum[i] = arr1[i] + arr2[i];
}