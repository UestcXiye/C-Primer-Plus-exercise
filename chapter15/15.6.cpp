#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 字体是否粗体 */
#define BOLD_ON 1
#define BOLD_OFF 0
/* 字体对齐方式 */
#define LEFT 0
#define RIGHT 1
#define CENTER 2
/* 字体是否斜体 */
#define ITALIC_ON 1
#define ITALIC_OFF 0
/* 字体是否有下划线 */
#define UNDERLINE_ON 1
#define UNDERLINE_OFF 0
#define FONT_ID_MASK 0xFFFFFF00   // 1111 1111 1111 1111 1111 1111 0000 0000
#define FONT_SIZE_MASK 0xFFFF80FF // 1111 1111 1111 1111 1000 0000 1111 1111

struct font
{
    unsigned int font_id : 8;
    unsigned int font_size : 7;
    unsigned int : 1;
    unsigned int alignment : 2;
    unsigned int bold : 1;
    unsigned int italic : 1;
    unsigned int underline : 1;
    unsigned int : 3;
}; // 从左到右（从高位到低位）依次为空白位(3), underline(1), italic(1), bold(1), alignment(2), 空白位(1), font_size(7), font_id(8)

void show(const struct font *ft);
int getlet(const char *);
int getmenu(void);
void eatline(void);

int main()
{
    struct font ft = {1, 12, LEFT, BOLD_OFF, ITALIC_OFF, UNDERLINE_OFF}; // 初始化font结构
    int choice;
    int id, size, align;

    show(&ft);
    putchar('\n');
    while ((choice = getmenu()) != 'q')
    {
        switch (choice)
        {
        case 'f':
            printf("Enter font id (0-255): ");
            while (scanf("%d", &id) != 1 || id < 0 || id > 255)
            {
                printf("您输入的不是一个整数，或者范围不在0到255之间\n");
                while (getchar() != '\n')
                    ;
                continue;
                printf("Enter font id (0-255): ");
            }
            eatline();
            ft.font_id = (ft.font_id & FONT_ID_MASK) | id;
            putchar('\n');
            show(&ft);
            break;
        case 's':
            printf("Enter font size (0-127): ");
            while (scanf("%d", &size) != 1 || size < 0 || size > 255)
            {
                printf("您输入的不是一个整数，或者范围不在0到127之间\n");
                while (getchar() != '\n')
                    ;
                continue;
                printf("Enter font size (0-127): ");
            }
            eatline();
            ft.font_size = ((ft.font_size & FONT_SIZE_MASK) >> 8) | size;
            putchar('\n');
            show(&ft);
            break;
        case 'a':
            printf("Select alignment: \n");
            puts("l) left c) center r)right");
            align = getlet("lcr");
            switch (align)
            {
            case 'l':
                ft.alignment = LEFT;
                break;
            case 'c':
                ft.alignment = CENTER;
                break;
            case 'r':
                ft.alignment = RIGHT;
                break;
            }
            putchar('\n');
            show(&ft);
            break;
        case 'b':
            ft.bold = BOLD_ON;
            putchar('\n');
            show(&ft);
            break;
        case 'i':
            ft.italic = ITALIC_ON;
            putchar('\n');
            show(&ft);
            break;
        case 'u':
            ft.underline = UNDERLINE_ON;
            putchar('\n');
            show(&ft);
            break;
        }
    }
    puts("Bye!");

    system("pause");
    return 0;
}

void show(const struct font *ft)
{
    printf("ID\tSIZE\tALIGNMENT\tB\tI\tU\n");
    printf("%d\t%d", ft->font_id, ft->font_size);
    switch (ft->alignment)
    {
    case LEFT:
        printf("%10s", "left");
        break;
    case RIGHT:
        printf("%10s", "right");
        break;
    case CENTER:
        printf("%10s", "center");
        break;
    default:
        printf("unknown alignment");
    }
    printf("%14s%8s%8s\n", ft->bold == BOLD_OFF ? "off" : "on",
           ft->italic == ITALIC_OFF ? "off" : "on",
           ft->underline == UNDERLINE_OFF ? "off" : "on");
    printf("\n");
}

int getlet(const char *s)
{
    char c;

    c = getchar();
    while (strchr(s, c) == NULL)
    {
        printf("请您在%s这串字符串中输入一个字符: \n", s);
        while (getchar() != '\n')
            continue;
        c = getchar();
    }
    while (getchar() != '\n')
        continue;
    return c;
}

int getmenu(void)
{
    int i;

    const char *str[7] = {
        "change font",
        "change size",
        "change alignment",
        "toggle bold",
        "toggle italic",
        "toggle underline",
        "quit"};
    const char pstr[8] = "fsabiuq";

    for (i = 0; i < 7; i++)
    {
        printf("%c) %s   ", pstr[i], str[i]);
        if (i % 3 == 2)
            putchar('\n');
    }
    if (i % 3 != 0)
        putchar('\n');

    return getlet(pstr);
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}