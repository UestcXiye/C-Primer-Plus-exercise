#include <stdio.h>
#include <stdlib.h>
int arr_max_index(double arr[], int n);
int main(void)
{
    double a[5] = {1.0, 3.0, 5.0, 7.0, 9.0};
    printf("The index of the max element in array is %d.\n", arr_max_index(a, 5));

    system("pause");
    return 0;
}
int arr_max_index(double arr[], int n)
{
    double max = arr[0];
    int max_index = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            max_index = i;
        }
    }
    return max_index;
}