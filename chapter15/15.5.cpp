#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // for CHAR_BIT（一个char的位数）

const int SIZE = CHAR_BIT * sizeof(int);

char *itobs(char *s, int n);
unsigned int rotate_1(unsigned int n, unsigned int b);

int main()
{
    char bin_str1[SIZE + 1], bin_str2[SIZE + 1];
    unsigned int number, count, result;

    printf("Enter an integer (q to quit): \n");
    while (scanf("%d", &number))
    {
        printf("Enter the number of bits to be rotated: \n");
        if (scanf("%d", &count) != 1)
            break;
        result = rotate_1(number, count);
        itobs(bin_str1, number);
        itobs(bin_str2, result);
        printf("%u rotated is %u.\n", number, result);
        printf("%s rotated is %s.\n", bin_str1, bin_str2);
        printf("Enter an integer (q to quit): \n");
    }

    system("pause");
    return 0;
}

char *itobs(char *s, int n)
{
    for (int i = SIZE - 1; i >= 0; i--, n >>= 1)
        s[i] = (01 & n) + '0';
    s[SIZE] = '\0';

    return s;
}

unsigned int rotate_1(unsigned int n, unsigned int b)
{
    unsigned int overflow;

    b %= SIZE;
    overflow = n >> (SIZE - b);
    
    return (n << b) | overflow;
}