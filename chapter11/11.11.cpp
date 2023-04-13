#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define LIM 10
#define SIZE 100
char *s_gets(char *st, int n);
char menu(void);
void print_origin(char ar[][100], int n);
void print_sort(char *ar[], int n);
void print_len(char *ar[], int n);
void print_first(char *ar[], int n);
int length(char *ar);
int main(void)
{
    char st1[LIM][SIZE];
    char *pt1[LIM];
    int ct = 0;
    printf("Please input the strings, EOF to quit.\n");
    while (ct < LIM && s_gets(st1[ct], SIZE) != NULL && st1[ct][0] != EOF)
    {
        pt1[ct] = st1[ct];
        ct++;
    }
    char ch = menu();
    while (ch != 'q')
    {
        switch (ch)
        {
        case 'a':
            print_origin(st1, ct);
            break;
        case 'b':
            print_sort(pt1, ct);
            break;
        case 'c':
            print_len(pt1, ct);
            break;
        case 'd':
            print_first(pt1, ct);
            break;
        case 'q':
            printf("Bye!\n");
            break;
        default:
            printf("\nI can only understand a, b, c, d, q.\n");
        }
        ch = menu();
    }
    return 0;
}

char menu(void)
{
    char ch;

    printf("Please input your choice:\n");
    printf("-----------------------------------------------------\n");
    printf("a) print origin         b) print sort by ASCII\n");
    printf("c) print by length      d) print by first word length\n");
    printf("q) quit\n");
    printf("-----------------------------------------------------\n");
    
    ch = getchar();
    while (getchar() != '\n')
        continue;
    return ch;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);

    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;

        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

void print_origin(char ar[][100], int n)
{
    int i;
    puts("\nShow the origin: ");
    for (i = 0; i < n; i++)
    {
        puts(ar[i]);
    }
    putchar('\n');
}

void print_sort(char *ar[], int n)
{
    char *temp;
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(ar[i], ar[j]) > 0)
            {
                temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }
    puts("\nHere is the sorted by ASCII:");
    for (i = 0; i < n; i++)
    {
        puts(ar[i]);
    }
    putchar('\n');
}

void print_len(char *ar[], int n)
{
    char *temp;
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strlen(ar[i]) > strlen(ar[j]))
            {
                temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }
    puts("\nHere is show by length: ");
    for (i = 0; i < n; i++)
    {
        puts(ar[i]);
    }
    putchar('\n');
}

void print_first(char *ar[], int n)
{
    char *temp;
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (length(ar[i]) > length(ar[j]))
            {
                temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }
    puts("\nShow the result sort by first word:");
    for (i = 0; i < n; i++)
    {
        puts(ar[i]);
    }
    putchar('\n');
}

int length(char *ar)
{
    int i = 0;
    int j = 0;
    bool inword = false;

    while (ar[i] != '\0')
    {
        if (inword == false && ar[i] != ' ')
            inword = true;
        if (inword == true && ar[i] != ' ')
            j++;
        if (inword == true && ar[i] == ' ')
            break;
        i++;
    }

    if (j != 0)
        return j;
    else
        return i;
}