#include <stdio.h> //提供CHAR_BIT的定义，表示每字节的位数，在这是8位
#include <stdlib.h>
#include <limits.h>

const int SIZE = CHAR_BIT * sizeof(int);

char *itob(char *s, int n);
int bit_num(int n);

int main()
{
    int num;
    char temp[SIZE + 1];

    printf("Please input an integer: ");
    while (scanf("%d", &num) != 1 || getchar() != '\n')
    {
        while (getchar() != '\n')
        {
            continue;
        }
        printf("Error! Try again: ");
    }
    printf("%d = %s, open bit:%d\n", num, itob(temp, num), bit_num(num));

    system("pause");
    return 0;
}

char *itob(char *s, int n) // 十进制转成二进制字符串
{
    for (int i = SIZE - 1; i >= 0; i--) // 从字符串右端开始
    {
        s[i] = (01 & n) + '0'; // 掩码01，获取十进制在该位的值
        n >>= 1;               // 十进制右移一位
    }
    s[SIZE] = '\0'; // 结尾

    return s;
}

int bit_num(int n)
{
    int count = 0;

    for (int i = 0; i < SIZE; i++) // 从字符串右端开始
    {
        if ((01 & n) == 1) // 如果十进制n的最后一位为1
        {
            count++;
        }
        n >>= 1; // 右移一位
    }

    return count;
}
