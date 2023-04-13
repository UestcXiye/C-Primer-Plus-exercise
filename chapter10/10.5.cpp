#include <stdio.h>
#include <stdlib.h>
double difference(double arr[], int n);
int main(void)
{
    double a[5] = {1.0, 3.0, 5.0, 7.0, 9.0};
    printf("The index of the max element in array is %.2lf.\n", difference(a, 5));

    system("pause");
    return 0;
}
double difference(double arr[], int n)
{
    double max, min;
    max = min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    return max - min;
}