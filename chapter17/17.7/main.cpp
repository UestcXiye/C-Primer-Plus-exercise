/* petclub.c -- use a binary search tree */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

char menu(void);
void addpet(Tree *pt, Item *temp);
void droppet(Tree *pt);
void showpets(const Tree *pt);
void findpet(const Tree *pt);
void printitem(Item item);
void uppercase(char *str);
char *s_gets(char *st, int n);

int main()
{
    Tree pets;
    char choice;
    Item temp;
    FILE *fp;

    if ((fp = fopen("words.txt", "r")) == NULL) // 判断是否能打开
    {
        printf("Can't open words.txt\n");
        exit(EXIT_FAILURE);
    }
    InitializeTree(&pets);                     // 初始化树
    while (fscanf(fp, "%s", temp.word) != EOF) // 读入二叉树
    {
        // printf("%s\n", temp.word);
        addpet(&pets, &temp);
    }

    while ((choice = menu()) != 'q')
    {
        switch (choice)
        {
        case 'l':
            showpets(&pets);
            break;
        case 'f':
            findpet(&pets);
            break;
        default:
            puts("Switching error");
        }
        puts("\n");
    }
    DeleteAll(&pets);
    puts("\nBye.");

    system("pause");
    return 0;
}

char menu(void)
{
    int ch;

    puts("Nerfville Pet Club Membership Program");
    puts("Enter the letter corresponding to your choice:");
    puts("l) show list of pets  f) find pets");
    puts("q) quit");
    while ((ch = getchar()) != EOF)
    {
        while (getchar() != '\n') /* discard rest of line */
            continue;
        ch = tolower(ch);
        if (strchr("lfq", ch) == NULL)
            puts("Please enter an l, f or q:");
        else
            break;
    }
    if (ch == EOF) /* make EOF cause program to quit */
        ch = 'q';

    return ch;
}

void addpet(Tree *pt, Item *temp)
{
    if (TreeIsFull(pt))
        puts("No room in the club!");
    else
    {
        uppercase(temp->word);
        temp->frequency = 1;
        AddItem(temp, pt);
    }
}

void showpets(const Tree *pt)
{
    if (TreeIsEmpty(pt))
        puts("No entries!");
    else
        Traverse(pt, printitem);
}

void printitem(Item item)
{
    printf("Word: %-19s  frequency: %-19d\n", item.word,
           item.frequency);
}

void findpet(const Tree *pt)
{
    Item temp;
    int frequency;

    if (TreeIsEmpty(pt))
    {
        puts("No entries!");
        return; /* quit function if tree is empty */
    }

    puts("Please enter word you wish to find:");
    s_gets(temp.word, SLEN);
    uppercase(temp.word);
    temp.frequency = 0;

    printf("%s", temp.word);
    if (frequency = InTree(&temp, pt))
        printf(" is a member %d of frequency.\n", frequency);
    else
        printf(" is not a member.\n");
}

void uppercase(char *str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // look for newline
        if (find)                // if the address is not NULL,
            *find = '\0';        // place a null character there
        else
            while (getchar() != '\n')
                continue; // dispose of rest of line
    }
    return ret_val;
}