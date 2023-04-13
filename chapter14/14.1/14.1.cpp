#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "months.h"

int days(char *input); // ��ȡ�·�������������

int main()
{
    char input[20];
    int total_days;

    printf("�������·�����(��q�˳�����)\n");
    while (scanf("%s", input) == 1 && input[0] != 'q') // ����q��ֹͣѭ��
    {
        total_days = days(input); // ���ú���
        if (total_days > 0)       // ����������0��˵���ж�Ӧ�·ݺ�
        {
            printf("�������ǣ�%d\n", total_days);
        }
        else
        {
            printf("��������\n");
        }
        printf("��������һ���·�����(��q�˳�����)\n");
    }
    printf("�������\n");

    system("pause");
    return 0;
}

int days(char *input)
{
    int i;
    int total = 0;
    int num = 0;

    input[0] = toupper(input[0]);      // ��һ����ĸת�ɴ�д
    for (i = 1; input[i] != '\0'; i++) // ѭ��������Ϊֹ����תΪСд��ĸ
    {
        input[i] = tolower(input[i]);
    }
    for (i = 0; i < 12; i++)
    {
        if (strcmp(input, months[i].name) == 0) // �ͽṹ����ÿһ��Ԫ�ص����ֱȽ�
        {
            num = months[i].monumb; // �ҵ���Ӧ�·ݣ����·ݺŸ�ֵ��num
            break;
        }
    }
    if (num == 0) // û�ж�Ӧ�·ݺ�
    {
        total = 0;
    }
    else
    {
        for (i = 0; i < num; i++) // �ж�Ӧ�·ݺ�
        {
            total += months[i].days; // ���
        }
    }
    return total; // ����������
}
