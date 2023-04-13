#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    char ch;
    int blank = 0, newline = 0, other = 0;
    while ((ch = getchar()) != '#')
    {
        switch (ch)
        {
        case ' ':
            blank++;
            break;
        case '\n':
            newline++;
            break;
        default:
            other++;
        }
    }
    printf("空格数：%d，换行符数：%d，其他字符数：%d\n", blank, newline, other);

    system("pause");
    return 0;
}