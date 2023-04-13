// practice2_12_5.c
#include <stdio.h>
#include <stdlib.h>
void br(void);
void ic(void);
int main(void)
{
    br();
    printf(", India, China\n");
    ic();
    printf(",\nBrazil, Russia\n");

    system("pause");
    return 0;
}
void br(void)
{
    printf("Brazil, Russia");
}
void ic(void)
{
    printf("India, China");
}
