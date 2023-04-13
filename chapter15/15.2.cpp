#include <stdio.h> //提供CHAR_BIT的定义，表示每字节的位数，在这是8位
#include <stdlib.h>
#include <string.h>
#include <limits.h>

const int SIZE = CHAR_BIT * sizeof(int);
const int LEN = SIZE + 1; // 字符数组最大长度33，最后一个是空字符

char *s_gets(char *s, int n);
bool check(const char *s);
int btoi(const char *s);
char *itob(char *s, int n);

int main()
{

    char input1[LEN], input2[LEN]; // 二进制字符串
    char temp[LEN];                // 临时数组
    int num1, num2;                // 字符串的十进制值

    printf("Please enter the first binary string: ");
    while (s_gets(input1, LEN) && check(input1) == false)
    {
        printf("Error! Try again: ");
    }
    printf("Please enter the second binary string: ");
    while (s_gets(input2, LEN) && check(input2) == false)
    {
        printf("Error! Try again: ");
    }

    num1 = btoi(input1);
    num2 = btoi(input2);

    printf("~%s = %s\n", input1, itob(temp, ~num1));
    printf("~%s = %s\n", input2, itob(temp, ~num2));
    printf("%s & %s = %s\n", input1, input2, itob(temp, (num1 & num2)));
    printf("%s | %s = %s\n", input1, input2, itob(temp, (num1 | num2)));
    printf("%s ^ %s = %s\n", input1, input2, itob(temp, (num1 ^ num2)));

    system("pause");
    return 0;
}

char *s_gets(char *s, int n) // 输入字符串
{
    char *ret_val;
    char *find;

    ret_val = fgets(s, n, stdin);
    if (ret_val)
    {
        find = strchr(s, '\n');
        if (find)
        {
            *find = '\0';
        }
        else
        {
            while (getchar() != '\n')
            {
                continue;
            }
        }
    }

    return ret_val;
}

bool check(const char *s) // 检查输入的字符串是否都为'0'和'1'
{
    bool is_bin = true; // 标记

    while (is_bin && *s != '\0') // 标记为1且没到字符串末尾
    {
        if (*s != '0' && *s != '1')
        {
            is_bin = false; // 字符串不是二进制，标记为0
        }
        s++;
    }

    return is_bin;
}
int btoi(const char *s)
{
    int total = 0; // 计数，计算二进制字符串的十进制值

    while (*s != '\0') // 没到字符串末尾
    {
        total = total * 2 + (*s - '0');
        s++;
    }

    return total;
}

char *itob(char *s, int n) // 十进制转成二进制字符串
{
    for (int i = SIZE - 1; i >= 0; i--) // 从字符串右端开始
    {
        s[i] = (01 & n) + '0'; // 掩码01，获取十进制在该位的值
        n >>= 1;
    }
    s[SIZE] = '\0'; // 结尾

    return s;
}
