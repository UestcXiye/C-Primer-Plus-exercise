#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    float num;
    printf("Enter a floating-point value: ");
    scanf("%f", &num);
    printf("fixed-point natation: %.6f\n", num);
    printf("exponential notation: %.6e\n", num);
    printf("p notation: %.2a\n", num);

    system("pause");
    return 0;
}
