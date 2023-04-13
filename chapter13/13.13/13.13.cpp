#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main(void)
{
    FILE *fp1, *fp2;
    int a = 20;
    int b = 30;
    int arr1[a][b]; // �����䳤����
    int i, j;
    char ch;

    if ((fp1 = fopen("number.txt", "r")) == NULL)
    {
        fprintf(stderr, "Can't open file:number.txt\n");
        exit(EXIT_FAILURE);
    }
    if ((fp2 = fopen("result.txt", "a+")) == NULL)
    {
        fprintf(stderr, "Can't open file:result.txt\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < a; i++) // ���ļ��������ֵ�����
    {
        for (j = 0; j < 2 * b; j++)
            if ((ch = getc(fp1)) != EOF && isdigit(ch))
                arr1[i][j / 2] = (int)ch - 48;
    }
    if (fclose(fp1) != 0)
        fprintf(stderr, "Error in closing file:number.txt\b");
    for (i = 0; i < 20; i++) // �������е�Ԫ�أ�ת��Ϊ��Ӧ���ַ�����������ļ�
    {
        for (j = 0; j < 30; j++)
        {
            switch (arr1[i][j])
            {
            case 0:
                putc(' ', fp2);
                break;
            case 1:
                putc('.', fp2);
                break;
            case 2:
                putc('\'', fp2);
                break;
            case 3:
                putc(':', fp2);
                break;
            case 4:
                putc('~', fp2);
                break;
            case 5:
                putc('*', fp2);
                break;
            case 6:
                putc('=', fp2);
                break;
            case 7:
                putc('^', fp2);
                break;
            case 8:
                putc('%', fp2);
                break;
            case 9:
                putc('#', fp2);
                break;
            default:
                break;
            }
        }
        putc('\n', fp2);
    }
    rewind(fp2);
    puts("Content output:");
    while ((ch = getc(fp2)) != EOF) // ��ӡ�ļ�������
        putc(ch, stdout);
    if (fclose(fp2) != 0)
        fprintf(stderr, "Error in closing file:result.txt\n");

    system("pause");
    return 0;
}