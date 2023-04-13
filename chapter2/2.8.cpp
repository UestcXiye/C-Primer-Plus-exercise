// practice2_12_8.c
#include <stdio.h>
#include <stdlib.h>
void one(void);
void two(void);
int main(void)
{
    printf("starting now:\n");
    one();
    two();
    printf("three\ndone!\n");

    system("pause");
    return 0;
}
void one(void)
{
    printf("one\n");
}
void two(void)
{
    printf("two\n");
}
