#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void func(int a, int b, int arr[][])
{
    float temp;
    int i, j;
    for (i = 1; i < a - 1; i++)
        for (j = 1; j < b - 1; j++)
        {
            if (abs(arr[i][j] - arr[i - 1][j]) > 1 && // 与上下左右做比较
                abs(arr[i][j] - arr[i + 1][j] > 1) &&
                abs(arr[i][j] - arr[i][j - 1] > 1) &&
                abs(arr[i][j] - arr[i][j + 1] > 1))
            {
                arr[i][j] = (arr[i - 1][j] + arr[i + 1][j] + arr[i][j - 1] + arr[i][j + 1]) / 4;
                temp = ((arr[i - 1][j] + arr[i + 1][j] + arr[i][j - 1] + arr[i][j + 1]) / 4.0 - arr[i][j]) >= 0.5 ? 1 : 0; // 四舍五入
                arr[i][j] += temp;
            }
        }
}

int main(void)
{
    FILE *fp1, *fp2;
    int a = 20;
    int b = 30;
    int arr1[a][b];
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
    for (i = 0; i < a; i++) // 把文件中的数字保存到数组中
        for (j = 0; j < 2 * b; j++)
            if ((ch = getc(fp1)) != EOF && isdigit(ch))
                arr1[i][j / 2] = (int)ch - 48;
    func(a, b, arr1); // 消除失真
    if (fclose(fp1) != 0)
        fprintf(stderr, "Error in closing file number.txt\n");
    for (i = 0; i < a; i++) // 按照数组中的数字，转换为相应的字符，并输入到文件中
    {
        for (j = 0; j < b; j++)
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
    while ((ch = getc(fp2)) != EOF) // 打印处理失真后的文件的内容
        putc(ch, stdout);
    if (fclose(fp2) != 0)
        fprintf(stderr, "Error in closing result.txt\n");

    system("pause");
    return 0;
}
