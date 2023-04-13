#include <stdio.h> //�ṩCHAR_BIT�Ķ��壬��ʾÿ�ֽڵ�λ����������8λ
#include <stdlib.h>
#include <string.h>
#include <limits.h>

const int SIZE = CHAR_BIT * sizeof(int);
const int LEN = SIZE + 1; // �ַ�������󳤶�33�����һ���ǿ��ַ�

char *s_gets(char *s, int n);
bool check(const char *s);
int btoi(const char *s);
char *itob(char *s, int n);

int main()
{

    char input1[LEN], input2[LEN]; // �������ַ���
    char temp[LEN];                // ��ʱ����
    int num1, num2;                // �ַ�����ʮ����ֵ

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

char *s_gets(char *s, int n) // �����ַ���
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

bool check(const char *s) // ���������ַ����Ƿ�Ϊ'0'��'1'
{
    bool is_bin = true; // ���

    while (is_bin && *s != '\0') // ���Ϊ1��û���ַ���ĩβ
    {
        if (*s != '0' && *s != '1')
        {
            is_bin = false; // �ַ������Ƕ����ƣ����Ϊ0
        }
        s++;
    }

    return is_bin;
}
int btoi(const char *s)
{
    int total = 0; // ����������������ַ�����ʮ����ֵ

    while (*s != '\0') // û���ַ���ĩβ
    {
        total = total * 2 + (*s - '0');
        s++;
    }

    return total;
}

char *itob(char *s, int n) // ʮ����ת�ɶ������ַ���
{
    for (int i = SIZE - 1; i >= 0; i--) // ���ַ����Ҷ˿�ʼ
    {
        s[i] = (01 & n) + '0'; // ����01����ȡʮ�����ڸ�λ��ֵ
        n >>= 1;
    }
    s[SIZE] = '\0'; // ��β

    return s;
}
