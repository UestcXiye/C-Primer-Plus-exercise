#include <stdio.h>
#include <stdlib.h>
void show_arr(const double arr[], int n);
void swap(double *a, double *b);
void reverse_sort(double arr[], int n);
int main(void)
{
    double a[5] = {1.0, 3.0, 5.0, 7.0, 9.0};
    printf("Original array: ");
    show_arr(a, 5);
    reverse_sort(a, 5);
    printf("After sorting: ");
    show_arr(a, 5);

    system("pause");
    return 0;
}
void show_arr(const double arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%.2lf ", arr[i]);
    printf("\n");
}
void swap(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}
void reverse_sort(double arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
                swap(&arr[i], &arr[j]);
        }
    }
}