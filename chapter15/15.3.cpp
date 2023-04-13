#include <stdio.h> //�ṩCHAR_BIT�Ķ��壬��ʾÿ�ֽڵ�λ����������8λ
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

char *itob(char *s, int n) // ʮ����ת�ɶ������ַ���
{
    for (int i = SIZE - 1; i >= 0; i--) // ���ַ����Ҷ˿�ʼ
    {
        s[i] = (01 & n) + '0'; // ����01����ȡʮ�����ڸ�λ��ֵ
        n >>= 1;               // ʮ��������һλ
    }
    s[SIZE] = '\0'; // ��β

    return s;
}

int bit_num(int n)
{
    int count = 0;

    for (int i = 0; i < SIZE; i++) // ���ַ����Ҷ˿�ʼ
    {
        if ((01 & n) == 1) // ���ʮ����n�����һλΪ1
        {
            count++;
        }
        n >>= 1; // ����һλ
    }

    return count;
}
