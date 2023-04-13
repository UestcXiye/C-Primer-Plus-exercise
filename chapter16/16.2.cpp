#include <stdio.h>
#include <stdlib.h>

#define HARMONIC_MEAN(X, Y) 2 / (1 / (X) + 1 / (Y))

int main()
{
    float a, b;
    printf("Please give me two numbers, and I'will calculate the harmonic mean:\n");
    scanf("%f %f", &a, &b);

    printf("The harmonic mean of %.2f and %.2f is %.2f.\n", a, b, HARMONIC_MEAN(a, b));

    system("pause");
    return 0;
}