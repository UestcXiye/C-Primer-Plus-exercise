#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE 45

struct film
{
    char title[TSIZE];
    int rating;
    struct film *next;
    struct film *pre;
};

void positive(struct film *p);  // 正序显示
void reversed(struct film *p);  // 逆序显示
void recursion(struct film *p); // 逆序递归显示

int main()
{
    struct film *head = NULL; // 指向链表头结点的指针，始终指向头结点保持不变
    struct film *current;     // 动态内存分配的地址。
    struct film *prev;        // 尾结点，可变，每次用来更新结构体内指针变量的值和自身的值。
    char input[TSIZE];

    puts("Enter first movie title: ");
    while (gets(input) != NULL && input[0] != '\0')
    {
        if ((current = (struct film *)malloc(sizeof(struct film))) == NULL)
        {
            printf("Failed to malloc memory\n");
            exit(EXIT_FAILURE);
        }

        if (head == NULL)
        {
            head = current;
            current->pre = NULL;
        }
        else
        {
            prev->next = current;
            current->pre = prev;
        }
        current->next = NULL;
        strcpy(current->title, input);
        puts("Enter your rating <0-10>: ");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
            continue;
        puts("Enter next movie title (empty line to stop): ");
        prev = current;
    }
    if (head == NULL)
        printf("No data entered. ");
    else
    {
        printf("Here is the movie list: \n");
        positive(head);
        printf("\n");
        printf("Here is the movie list: \n");
        reversed(prev);
        printf("\n");
        printf("Here is the movie list: \n");
        recursion(head);
    }
    printf("Bye!\n");

    system("pause");
    return 0;
}

void positive(struct film *p)
{
    while (p != NULL)
    {
        printf("Movie: %s Rating: %d\n", p->title, p->rating);
        p = p->next;
    }
}

void reversed(struct film *p)
{
    while (p != NULL)
    {
        printf("Movie: %s Rating: %d\n", p->title, p->rating);
        p = p->pre;
    }
}

void recursion(struct film *p)
{
    if (p->next != NULL)
        recursion(p->next);
    printf("Movie: %s Rating: %d\n", p->title, p->rating);
}
