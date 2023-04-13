#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
struct pack
{
    struct book book;
    bool delete_me;
};
// 删除或修改该记录的选择
int getlet(const char *);
// 修改该记录
void update(struct pack *);
// 从键盘获得输入
char *s_gets(char *, int);

int getbook(struct pack *);

int main(void)
{
    struct pack library[MAXBKS];
    int count = 0;
    int deleted = 0;
    int index, filecount, open;
    FILE *pbooks;
    int size = sizeof(struct book);

    if ((pbooks = fopen("book.dat", "r")) != NULL)
    {
        while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
        {
            if (count == 0)
                puts("Current contents of book.dat: ");
            printf("%s by %s: $%.2f\n", library[count].book.title, library[count].book.author, library[count].book.value);
            printf("Do you wish to change or delete this entry?<y/n> ");
            if (getlet("yn") == 'y')
            {
                printf("Enter c to change, d to delete this entry.<c/d> ");
                if (getlet("cd") == 'd') // 删除该记录(并不立即实现该功能)
                {
                    library[count].delete_me = true;
                    deleted++;
                    puts("Entry marked for deletion.");
                }
                else
                    update(&library[count]); // 修改该记录(修改要比删除简单)
            }
            count++;
        }
        fclose(pbooks);
    }

    filecount = count - deleted;
    if (count == MAXBKS)
    {
        fputs("The book.dat file is full.", stderr);
        exit(1);
    }
    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");
    open = 0;
    while (filecount < MAXBKS)
    {
        if (filecount < count)
        {
            while (library[open].delete_me == false)
                open++;
            if (getbook(&library[open]) == 1)
                break;
        }
        else if (getbook(&library[filecount]) == 1)
            break;
        filecount++;
        if (filecount < MAXBKS)
            puts("Enter the new book title.");
    }
    puts("Here is the list of your books: ");
    for (index = 0; index < filecount; index++) // 此处应该为count
        if (library[index].delete_me == false)
            printf("%s by %s: $%.2f\n", library[index].book.title, library[index].book.author, library[index].book.value);
    if ((pbooks = fopen("book.dat", "w")) == NULL)
    {
        puts("Can't open book.dat file for output.");
        exit(2);
    }
    for (index = 0; index < filecount; index++) // 此处应该为count
        if (library[index].delete_me == false)
            fwrite(&(library[index].book), size, 1, pbooks);
    puts("Bye.\n");
    fclose(pbooks);

    system("pause");
    return 0;
}
int getlet(const char *s)
{
    char c;

    c = getchar();
    while (strchr(s, c) == NULL)
    {
        printf("Enter the characters in the list %s\n", s);
        while (getchar() != '\n')
            continue;
        c = getchar();
    }
    while (getchar() != '\n')
        continue;
    return c;
}
int getbook(struct pack *item)
{
    int status = 0;

    if (s_gets(item->book.title, MAXTITL) == NULL || item->book.title[0] == '\0')
        status = 1;
    else
    {
        printf("Now enter the author: ");
        s_gets(item->book.author, MAXAUTL);
        printf("Now enter the value: ");
        while (scanf("%f", &item->book.value) != 1)
        {
            puts("Please use numeric input");
            scanf("%*s");
        }
        while (getchar() != '\n')
            continue;
        item->delete_me = false;
    }
    return status;
}
void update(struct pack *item)
{
    struct book copy;
    char c;

    copy = item->book;
    puts("Enter the letter that indicates your choice: ");
    puts("t) modify title       a) modify author");
    puts("v) modify value       s) quit, saving changes");
    puts("q) quit, ignore changes");
    while ((c = getlet("tavsq")) != 's' && c != 'q')
    {
        switch (c)
        {
        case 't':
            puts("Enter new title: ");
            s_gets(copy.title, MAXTITL);
            break;
        case 'a':
            puts("Enter new author: ");
            s_gets(copy.author, MAXAUTL);
            break;
        case 'v':
            puts("Enter new value: ");
            while (scanf("%f", &copy.value) != 1)
            {
                puts("Enter a numeric value: ");
                scanf("%*s"); // *放在%和说明符之间，使得函数跳过相应的输入项目
            }
            while (getchar() != '\n')
                continue;
            break;
        }
        puts("t) modify title       a) modify author");
        puts("v) modify value       s) quit, saving changes");
        puts("q) quit, ignore changes");
    }
    if (c == 's')
        item->book = copy;
}
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(ret_val, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}