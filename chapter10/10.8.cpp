#include <stdio.h>
#include <stdlib.h>
void copy_arr(double *target1, double *source, int n);
void copy_ptr(double *target2, double *source, int n);
void copy_ptrs(double *target3, double *source1, double *source2);
void print_arr(double *arr, int n);
int main(void)
{

    double source[7] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    double target1[3];
    double target2[3];
    double target3[3];

    print_arr(source, 7);
    copy_arr(target1, source + 2, 3);
    copy_ptr(target2, &source[2], 3);
    copy_ptrs(target3, source + 2, source + 5);
    print_arr(target1, 3);
    print_arr(target2, 3);
    print_arr(target3, 3);

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
void copy_ptr(double *target2, double *source, int n)
{
    for (int i = 0; i < n; i++)
    {
        *(target2 + i) = *(source + i);
    }
}
void copy_ptrs(double *target3, double *source1, double *source2)
{
    double *i;
    int j;
    for (i = source1, j = 0; i < source2; i++, j++)
    {
        *(target3 + j) = *i;
    }
}
void print_arr(double *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%.2lf ", *(arr + i));
    printf("\n");
}