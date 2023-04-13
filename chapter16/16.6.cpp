#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM 100
#define LEN 40

struct Name
{
    char first[LEN];
    char last[LEN];
};

struct Name staff[NUM];

void fillarray(struct Name ar[], int n);
void showarray(const struct Name ar[], int n);
int mycomp(const void *p1, const void *p2);

int main()
{
    fillarray(staff, NUM);
    puts("Random list:");
    showarray(staff, NUM);
    qsort((void *)staff, (size_t)NUM, sizeof(struct Name), mycomp);
    puts("\nSorted list:");
    showarray(staff, NUM);

    system("pause");
    return 0;
}

void fillarray(struct Name ar[], int n)
{
    srand((unsigned long)time(0));

    for (int i = 0; i < n; i++)
    {
        int firstLen = rand() % 10 + 1;
        int lastLen = rand() % 10 + 1;
        // 随机生成first
        for (int j = 0; j < firstLen; j++)
        {
            ar[i].first[j] = rand() % 26 + 'a';
        }
        // 随机生成last
        for (int j = 0; j < lastLen; j++)
        {
            ar[i].last[j] = rand() % 26 + 'a';
        }
    }
}

void showarray(const struct Name ar[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%10s.%-10s ", ar[i].first, ar[i].last);
        if (i % 4 == 3)
            putchar('\n');
    }
    if (i % 4 != 0)
        putchar('\n');
}

int mycomp(const void *p1, const void *p2)
{
    const struct Name *ps1 = (const struct Name *)p1;
    const struct Name *ps2 = (const struct Name *)p2;
    int res = strcmp(ps1->last, ps2->last);

    if (res != 0)
        return res;
    else
        return strcmp(ps1->first, ps2->first);
}