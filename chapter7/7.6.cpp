#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char ch;
    int count = 0; //����ei���ֵĴ���
    bool condition = false; //��������

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
    printf("ei������%d��\n", count);

    system("pause");
    return 0;
}