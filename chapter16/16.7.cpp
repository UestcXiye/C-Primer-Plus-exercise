#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void show_array(const double ar[], int n);
double *new_d_array(int n, ...);

int main()
{
    double *p1;
    double *p2;

    p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
    show_array(p1, 5);
    show_array(p2, 4);
    free(p1);
    free(p2);

    system("pause");
    return 0;
}

void show_array(const double ar[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%.2lf ", ar[i]);
    }
    printf("\n");
}

double *new_d_array(int n, ...)
{
    va_list ap;      // 声明一个对象储存参数
    va_start(ap, n); // 把ap初始化为参数列表
    double *array = (double *)malloc(n * sizeof(double));

    for (int i = 0; i < n; i++)
        array[i] = va_arg(ap, double); // 访问参数列表中的每一项
    va_end(ap);

    return array;
}