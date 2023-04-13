#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

#define LEN 19
#define SIZE 31

struct athlete
{
    int index;        // 球员号码
    char lname[SIZE]; // 名
    char fname[SIZE]; // 姓
    int play_times;   // 上场次数
    int hit_numbers;  // 击中数
    int base_numbers; // 走垒数
    int rbi;          // 跑点数
    double hit_rate;  // 安打率
};

// 初始化结构数组
void init_athletes(struct athlete *, int);
// 计算每个球员的安打率
void cal_hit_rate(struct athlete *, int);
// 显示每个球员的累计数据
void show(struct athlete *, int);
// 对整个时期显示一行综合统计数据
void show_statistical_data(struct athlete *, int);

int main()
{
    struct athlete athletes[LEN];
    struct athlete temp; // 临时结构
    FILE *fp;
    char file[SIZE];
    int index;

    init_athletes(athletes, LEN);
    // 读取文本文件
    puts("请输入要读取的文本文件：");
    gets(file);
    if ((fp = fopen(file, "r")) == NULL)
    {
        fprintf(stderr, "不能打开文件%s\n", file);
        exit(EXIT_FAILURE);
    }
    // 把文本文件的数据存储到一个结构数组中
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
        if (ath[i].play_times > 0) // 只打印上过场的球员的信息
        {
            printf("球员%s %s的累计数据为：\n", ath[i].fname, ath[i].lname);
            printf("上场次数：%d\n", ath[i].play_times);
            printf("击中数：%d\n", ath[i].hit_numbers);
            printf("走垒数：%d\n", ath[i].base_numbers);
            printf("跑点数：%d\n", ath[i].rbi);
            printf("安打率：%.2f%%\n", ath[i].hit_rate * 100);
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
    printf("**********************综合统计数据*******************************\n");
    printf("所有球员的上场次数总和为：%d\n", temp.play_times);
    printf("击中数总和为：%d\n", temp.hit_numbers);
    printf("走垒数总和为：%d\n", temp.base_numbers);
    printf("跑点数总和为：%d\n", temp.rbi);
    printf("平均安打率为：%.2f%%\n", (double)temp.hit_numbers / temp.play_times * 100);
}