#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

#define LEN 19
#define SIZE 31

struct athlete
{
    int index;        // ��Ա����
    char lname[SIZE]; // ��
    char fname[SIZE]; // ��
    int play_times;   // �ϳ�����
    int hit_numbers;  // ������
    int base_numbers; // ������
    int rbi;          // �ܵ���
    double hit_rate;  // ������
};

// ��ʼ���ṹ����
void init_athletes(struct athlete *, int);
// ����ÿ����Ա�İ�����
void cal_hit_rate(struct athlete *, int);
// ��ʾÿ����Ա���ۼ�����
void show(struct athlete *, int);
// ������ʱ����ʾһ���ۺ�ͳ������
void show_statistical_data(struct athlete *, int);

int main()
{
    struct athlete athletes[LEN];
    struct athlete temp; // ��ʱ�ṹ
    FILE *fp;
    char file[SIZE];
    int index;

    init_athletes(athletes, LEN);
    // ��ȡ�ı��ļ�
    puts("������Ҫ��ȡ���ı��ļ���");
    gets(file);
    if ((fp = fopen(file, "r")) == NULL)
    {
        fprintf(stderr, "���ܴ��ļ�%s\n", file);
        exit(EXIT_FAILURE);
    }
    // ���ı��ļ������ݴ洢��һ���ṹ������
    while (fscanf(fp, "%d %s %s %d %d %d %d", &index, temp.fname, temp.lname,
                  &temp.play_times, &temp.hit_numbers, &temp.base_numbers, &temp.rbi) == 7)
    {
        if (strcmp(athletes[index].fname, temp.fname) != 0)
            strcpy(athletes[index].fname, temp.fname);
        if (strcmp(athletes[index].lname, temp.lname) != 0)
            strcpy(athletes[index].lname, temp.lname);
        athletes[index].play_times += temp.play_times;
        athletes[index].hit_numbers += temp.hit_numbers;
        athletes[index].base_numbers += temp.base_numbers;
        athletes[index].rbi += temp.rbi;
    }
    cal_hit_rate(athletes, LEN);
    show(athletes, LEN);
    show_statistical_data(athletes, LEN);

    system("pause");
    return 0;
}

void init_athletes(struct athlete *ath, int n)
{
    for (int i = 0; i < n; i++)
    {
        ath[i].index = i;
        strcpy(ath[i].lname, "");
        strcpy(ath[i].fname, "");
        ath[i].play_times = 0;
        ath[i].hit_numbers = 0;
        ath[i].base_numbers = 0;
        ath[i].rbi = 0;
        ath[i].hit_rate = 0.0;
    }
}

void cal_hit_rate(struct athlete *ath, int n)
{
    for (int i = 0; i < n; i++)
        ath[i].hit_rate = (double)ath[i].hit_numbers / ath[i].play_times;
}

void show(struct athlete *ath, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (ath[i].play_times > 0) // ֻ��ӡ�Ϲ�������Ա����Ϣ
        {
            printf("��Ա%s %s���ۼ�����Ϊ��\n", ath[i].fname, ath[i].lname);
            printf("�ϳ�������%d\n", ath[i].play_times);
            printf("��������%d\n", ath[i].hit_numbers);
            printf("��������%d\n", ath[i].base_numbers);
            printf("�ܵ�����%d\n", ath[i].rbi);
            printf("�����ʣ�%.2f%%\n", ath[i].hit_rate * 100);
            if (i < 18)
                printf("********************************\n");
        }
    }
}

void show_statistical_data(struct athlete *ath, int n)
{
    struct athlete temp = {0, "", "", 0, 0, 0, 0, 0.0};

    for (int i = 0; i < n; i++)
    {
        temp.play_times += ath[i].play_times;
        temp.hit_numbers += ath[i].hit_numbers;
        temp.base_numbers += ath[i].base_numbers;
        temp.rbi += ath[i].rbi;
    }
    printf("**********************�ۺ�ͳ������*******************************\n");
    printf("������Ա���ϳ������ܺ�Ϊ��%d\n", temp.play_times);
    printf("�������ܺ�Ϊ��%d\n", temp.hit_numbers);
    printf("�������ܺ�Ϊ��%d\n", temp.base_numbers);
    printf("�ܵ����ܺ�Ϊ��%d\n", temp.rbi);
    printf("ƽ��������Ϊ��%.2f%%\n", (double)temp.hit_numbers / temp.play_times * 100);
}