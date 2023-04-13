#include <stdio.h> //�ṩCHAR_BIT�Ķ��壬��ʾÿ�ֽڵ�λ����������8λ
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

bool is_open(int num, int index)
{
    num >>= index;
    if ((01 & num) == 1)
        return true;
    else
        return false;
}
