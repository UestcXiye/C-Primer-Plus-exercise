#include <stdio.h>
#include <stdlib.h>
int arr_max(int arr[], int n);
int main(void)
{
    int a[5] = {1, 3, 5, 7, 9};
    printf("The max element in array is %d.\n", arr_max(a, 5));

    system("pause");
    return 0;
}
int arr_max(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}