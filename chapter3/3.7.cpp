#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int height;
    printf("Please input your height(inch): ");
    scanf("%d", &height);
    printf("%d inchs is equaled to %f cm.\n", height, height * 2.54);

    system("pause");
    return 0;
}
