#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

char *s_gets(char *st, int n);
void sort_title(struct book *pb[], int n);
void sort_value(struct book *pb[], int n);

int main()
{
    struct book library[MAXBKS];
    struct book *book[MAXBKS]; // 指向结构体book的指针数组
    int count = 0;
    int index;

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count].value);
        book[count] = &library[count];
        count++;
        while (getchar() != '\n')
            continue;
        if (count < MAXBKS)
        {
            printf("Enter the next title.\n");
        }
    }

    if (count > 0)
    {
        printf("Here is the list of your books:\n");
        // 按照输入图书的顺序输出图书的信息
        for (index = 0; index < count; index++)
        {
            printf("%s by %s: $%.2f\n", library[index].title,
                   library[index].author, library[index].value);
        }
        // 按照标题字母的声明输出图书的信息
        sort_title(book, count);
        printf("\nHere is the list of your books sorted by title letters:\n");
        for (index = 0; index < count; index++)
        {
            printf("%s by %s: $%.2f\n", book[index]->title,
                   book[index]->author, book[index]->value);
        }
        // 按照价格的升序输出图书的信息
        sort_value(book, count);
        printf("\nHere is the list of your books sorted by value(from low to high):\n");
        for (index = 0; index < count; index++)
        {
            printf("%s by %s: $%.2f\n", book[index]->title,
                   book[index]->author, book[index]->value);
        }
    }
    else
    {
        printf("No books? Too bad.\n");
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

void sort_title(struct book *pb[], int n)
{
    struct book *temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(pb[j]->title, pb[i]->title) < 0)
            {
                temp = pb[j];
                pb[j] = pb[i];
                pb[i] = temp;
            }
        }
    }
    return;
}

void sort_value(struct book *pb[], int n)
{
    struct book *temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (pb[j]->value < pb[i]->value)
            {
                temp = pb[j];
                pb[j] = pb[i];
                pb[i] = temp;
            }
        }
    }
    return;
}
