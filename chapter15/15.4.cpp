#include <stdio.h> //提供CHAR_BIT的定义，表示每字节的位数，在这是8位
#include <stdlib.h>
#include <limits.h>

const int SIZE = CHAR_BIT * sizeof(int);

char *itob(char *s, int n);
bool is_open(int num, int index);

int main()
{
    int num, index;
    char temp[SIZE + 1];

    printf("Please input an integer: ");
    while (scanf("%d", &num) != 1 || getchar() != '\n')
    {
        while (getchar() != '\n')
        {
            continue;
        }
        printf("Input integer error! Try again: ");
    }
    printf("Please input the index: ");
    while (scanf("%d", &index) != 1 || (!(index >= 0 && index <= 31)) || getchar() != '\n')
    {
        while (getchar() != '\n')
        {
            continue;
        }
        printf("Input index error! Try again: ");
    }
    printf("%d = %s\nThe position of the specified bit is %d\n", num, itob(temp, num), is_open(num, index));

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

bool is_open(int num, int index)
{
    num >>= index;
    if ((01 & num) == 1)
        return true;
    else
        return false;
}
