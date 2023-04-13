#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    float glass;
    float pint;
    float ounce;
    float spoon;
    float teaspoon;

    printf("How many glasses?\n");
    scanf("%f", &glass);
    pint = glass / 2;
    ounce = 8 * glass;
    spoon = 2 * ounce;
    teaspoon = 3 * spoon;
    printf("%f glasses=%f pints, =%f ounces, =%f spoons, =%f teaspoons\n", glass, pint, ounce, spoon, teaspoon);

    system("pause");
    return 0;
}
