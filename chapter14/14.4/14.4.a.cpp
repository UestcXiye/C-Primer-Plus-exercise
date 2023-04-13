#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 15
#define LEN 30

struct names
{
    char fname[N];
    char mname[N];
    char lname[N];
};

struct messages
{
    char ins_num[LEN];
    struct names name;
};

char *s_gets(char *st, int n);
void show(struct messages *p[], int n);

int main()
{
    int count = 0;
    struct messages m[5];
    struct messages *p[5];

    printf("Please enter the insurance number:\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < 5 && s_gets(m[count].ins_num, LEN) && m[count].ins_num[0] != '\0')
    {
        printf("Now enter the former name.\n");
        s_gets(m[count].name.fname, N);
        printf("Now enter the middle name (without, [enter] to the next).\n");
        s_gets(m[count].name.mname, N);
        printf("Now enter the last name.\n");
        s_gets(m[count].name.lname, N);
        if (count++ < 5)
        {
            printf("Enter the next insurance number:\n");
        }
    }
    for (int i = 0; i < count; i++)
        p[i] = &m[i];
    if (count > 0)
    {
        show(p, count);
    }
    else
    {
        printf("No data!\n");
    }

    system("pause");
    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
        {
            *find = '\0';
        }
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }
    return ret_val;
}

void show(struct messages *p[], int n)
{
    printf("All numbers messages:\n");
    for (int i = 0; i < n; i++)
    {
        if (p[i]->name.mname[0] == '\0')
        {
            printf("%s, %s", p[i]->name.fname, p[i]->name.lname);
            printf(" -- %s\n", p[i]->ins_num);
        }
        else
        {
            printf("%s, %s %c.", p[i]->name.fname, p[i]->name.lname, p[i]->name.mname[0]);
            printf(" -- %s\n", p[i]->ins_num);
        }
    }
    return;
}
