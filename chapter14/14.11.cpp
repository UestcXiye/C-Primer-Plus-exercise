#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM 100

double twice(double x) { return 2.0 * x; }
double half(double x) { return x / 2.0; }
void init(double *arr, int n);
void transform(double *source, double *target, int n, double (*fp)(double));
void show(const double *arr, int n);

int main()
{
    double source[NUM];
    double target0[NUM];
    double target1[NUM];
    double target2[NUM];
    double target3[NUM];
    double (*fp[NUM])(double) = {twice, half, sqrt, sin};

    init(source, NUM);
    transform(source, target0, NUM, twice);
    transform(source, target1, NUM, half);
    transform(source, target2, NUM, sqrt);
    transform(source, target3, NUM, sin);
    puts("--------------------------target0数组--------------------------");
    show(target0, NUM);
    puts("--------------------------target1数组--------------------------");
    show(target1, NUM);
    puts("--------------------------target2数组--------------------------");
    show(target2, NUM);
    puts("--------------------------target3数组--------------------------");
    show(target3, NUM);
    puts("Bye.");

    system("pause");
    return 0;
}
void init(double *arr, int n)
{
    for (int i = 0; i < NUM; i++)
        arr[i] = i + 1;
}

void transform(double *source, double *target, int n, double (*fp)(double))
{
    for (int i = 0; i < n; i++)
        target[i] = (*fp)(source[i]);
}

void show(const double *arr, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%7.2f", arr[i]);
        if (i % 10 == 9)
            putchar('\n');
    }
    if (i % 10 != 9)
        putchar('\n');
}