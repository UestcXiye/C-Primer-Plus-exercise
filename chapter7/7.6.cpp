#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char ch;
    int count = 0; //计数ei出现的次数
    bool condition = false; //触发条件

    while ((ch = getchar()) != '#')
    {
        if (ch == 'e')
        {
            condition = true;
        }
        if (ch == 'i' && condition == true)
        {
            count++;
            condition = false;
        }
        else if (ch != 'e')
        {
            condition = false;
        }
    }
    printf("ei出现了%d次\n", count);

    system("pause");
    return 0;
}