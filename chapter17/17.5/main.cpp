#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main()
{
    Item temp[MAXSTACK];
    Stack box;
    int i;
    Item t; // 应该为字符 不应该是指针

    printf("Enter a string, I will give you string of reverse\n");
    while (scanf("%s", temp))
    {
        InitializeStack(&box); // 初始化栈

        for (i = 0; i < strlen(temp); i++) // 将字符压栈
            Push(temp[i], &box);
        for (i = 0; i < strlen(temp); i++) // 将字符弹栈
        {
            Pop(&t, &box);
            printf("%c", t);
        }

        puts("\n");
        printf("Enter a string, I will give you string of reverse(enter ^C to quit)\n");
    }
    printf("Bye!");

    system("pause");
    return 0;
}