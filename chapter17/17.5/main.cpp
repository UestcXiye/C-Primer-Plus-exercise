#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main()
{
    Item temp[MAXSTACK];
    Stack box;
    int i;
    Item t; // Ӧ��Ϊ�ַ� ��Ӧ����ָ��

    printf("Enter a string, I will give you string of reverse\n");
    while (scanf("%s", temp))
    {
        InitializeStack(&box); // ��ʼ��ջ

        for (i = 0; i < strlen(temp); i++) // ���ַ�ѹջ
            Push(temp[i], &box);
        for (i = 0; i < strlen(temp); i++) // ���ַ���ջ
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