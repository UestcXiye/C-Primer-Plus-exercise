#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char c;
    printf("Please input a number: ");
    scanf("%d", &c);
    printf("%d in ASCII is %c.\n", c, c);

    system("pause");
    return 0;
}
