// practice2_12_7.c
#include <stdio.h>
#include <stdlib.h>
void smile(void);
int main(void)
{
    smile();
    smile();
    smile();
    printf("\n");
    smile();
    smile();
    printf("\n");
    smile();
    printf("\n");
    
    system("pause");
    return 0;
}
void smile(void)
{
    printf("Smile!");
}
