#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define LEN 12

struct month
{
    char name[10];
    char abbrev[4];
    int days;
    int monumb;
};

struct month months[LEN] =
    {
        {"January", "Jan", 31, 1},
        {"February", "Feb", 28, 2},
        {"March", "Mar", 31, 3},
        {"April", "Apr", 30, 4},
        {"May", "May", 31, 5},
        {"June", "Jun", 30, 6},
        {"July", "Jul", 31, 7},
        {"August", "Aug", 31, 8},
        {"September", "Sep", 30, 9},
        {"October", "Oct", 31, 10},
        {"November", "Nov", 30, 11},
        {"December", "Dec", 31, 12}};

void leap_year(int year);
int days_result(char *month, int days);

int main()
{
    int n, val;
    int day, year;
    char month[LEN];

    printf("Please enter day, month and year (q to quit): ");
    while (scanf("%d %11s %d", &day, month, &year) == 3)
    {
        leap_year(year);
        val = days_result(month, day);
        if (val > 0)
        {
            printf("There are %d days from the beginning of %d to %s %d\n", val, year, month, day);
        }
        else
        {
            printf("input error\n");
        }
        months[1].days = 28; // 2�·�������ԭΪ������ʱ������
        printf("You can enter day, month and year again (q to quit): ");
    }
    printf("Done.\n");

    system("pause");
    return 0;
}

void leap_year(int year) // �ж��Ƿ�������
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        months[1].days = 29; // ��������2�·�������Ϊ29��;
    }
    return;
}

int days_result(char *month, int days)
{
    int i;
    int total = 0;
    int temp = atoi(month);

    if (days < 1 || days > 31)
    {
        return -1; // �����������������ֹ������
    }
    if (0 == temp) // �û�������·ݲ�������ʱҪ����ת��
    {
        month[0] = toupper(month[0]);
        for (i = 1; month[i] != '\0'; i++)
        {
            month[i] = tolower(month[i]);
        }
    }
    for (i = 0; i < LEN; i++)
    {
        if ((temp == months[i].monumb) ||
            (strcmp(month, months[i].name) == 0) ||
            (strcmp(month, months[i].abbrev) == 0))
        {
            if (days > months[i].days)
            {
                return -1; // ����������������·ݵĹ���
            }
            else
            {
                return total + days; // �ۼӵ����º���ϱ�������
            }
        }
        else
        {
            total += months[i].days;
        }
    }
    return -1; // �����·���������ֹ����
}
