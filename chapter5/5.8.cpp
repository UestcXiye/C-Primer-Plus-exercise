/* 5.11.8 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mod;
    int num;
    printf("This program computes moduli.\nEnter an integer to serve as the second operand: ");
    scanf("%d", &mod);
    printf("Now enter the first operand: ");
    while (~scanf("%d", &num) && num > 0)
    {
        printf("%d %% %d is %d\n", num, mod, num % mod);
        printf("Enter next number for first operand (<= 0 to quit): ");
    }
    printf("Done\n");

    system("pause");
    return 0;
}

