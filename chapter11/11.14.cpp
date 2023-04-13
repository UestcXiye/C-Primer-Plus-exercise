#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    float base = atof(argv[1]);
    int power = atoi(argv[2]);
    double sum = 1;

    if (argc != 3)
        printf("arguments error!\n");
    else
    {
        for (int i = 0; i < power; i++)
            sum *= base;
        printf("result: %lf\n", sum);
    }

    system("pause");
    return 0;
}