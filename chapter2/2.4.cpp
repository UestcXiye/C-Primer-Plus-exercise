// practice2_12_4.c
#include <stdio.h>
#include <stdlib.h>
void jolly(void);
void deny(void);
int main(void)
{
    for(int i=0;i<3;i++) jolly();
    deny();

    system("pause");
    return 0;
}
void jolly(void)
{
    printf("For he's a jolly good fellow!\n");
}
void deny(void)
{
    printf("Which nobody can deny!\n");
}
