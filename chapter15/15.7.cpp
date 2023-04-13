#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define UNDERLINE 0x80000 // 1000 0000 0000 0000 0000
#define ITALIC 0x40000    // 0100 0000 0000 0000 0000
#define BOLD 0x20000      // 0010 0000 0000 0000 0000
#define LEFT 0x00000      // 0000 0000 0000 0000 0000
#define CENTER 0x08000    // 0000 1000 0000 0000 0000
#define RIGHT 0x10000     // 0001 0000 0000 0000 0000

#define ID_MASK 0xFF       // 0000 0000 0000 1111 1111
#define SIZE_MASK 0x7F00   // 0000 0111 1111 0000 0000
#define ALIGN_MASK 0x18000 // 0001 1000 0000 0000 0000

#define SIZE_SHIFT 8

typedef unsigned long font;

char do_menu(font *f);
void show_font(font f);
char get_choice(const char *);
void show_menu(void);
void eatline(void);
void get_id(font *f);
void get_size(font *f);
void get_align(font *f);

int main()
{
    // sample = 0100 0000 1100 0000 0001(斜体, 没有预留空隙)
    font sample = 1 | (12 << SIZE_SHIFT) | LEFT | ITALIC;
    // 从左到右（从高位到低位）依次为underline(1), italic(1), bold(1), alignment(2), font_size(7), font_id(8)
    while (do_menu(&sample) != 'q')
        continue;
    puts("Bye!");

    system("pause");
    return 0;
}

char do_menu(font *f)
{
    char response;

    show_font(*f);
    show_menu();
    response = get_choice("fsabiuq");
    switch (response)
    {
    case 'f':
        get_id(f);
        break;
    case 's':
        get_size(f);
        break;
    case 'a':
        get_align(f);
        break;
    case 'b':
        *f ^= BOLD;
        break;
    case 'i':
        *f ^= ITALIC;
        break;
    case 'u':
        *f ^= UNDERLINE;
        break;
    case 'q':
        break;
    default:
        printf("menu problem\n");
    }
    return response;
}

void show_font(font f)
{
    printf("%4s %4s %9s %3s %3s %3s\n", "ID", "SIZE", "ALIGNMENT", "B", "I", "U");
    printf("%4lu %4lu", f & ID_MASK, (f & SIZE_MASK) >> SIZE_SHIFT);
    switch (f & ALIGN_MASK)
    {
    case LEFT:
        printf("%7s", "left");
        break;
    case CENTER:
        printf("%7s", "center");
        break;
    case RIGHT:
        printf("%7s", "right");
        break;
    default:
        printf("%7s", "unknown alignment");
        break;
    }
    printf("%8s %3s %3s\n", (f & BOLD) == BOLD ? "on" : "off",
           (f & ITALIC) == ITALIC ? "on" : "off",
           (f & UNDERLINE) == UNDERLINE ? "on" : "off");
    putchar('\n');
}

char get_choice(const char *s)
{
    char ch;

    ch = getchar();
    ch = tolower(ch);

    while (strchr(s, ch) == NULL)
    {
        printf("Please enter one of the following: %s\n", s);
        eatline();
        ch = tolower(getchar());
    }
    eatline();
    return ch;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

void show_menu(void)
{
    puts("f) change font   s) change size     a) change alignment");
    puts("b) toggle bold   i) toggle italic   u) toggle underline");
    puts("q) quit");
}

void get_id(font *f)
{
    int id;

    printf("Enter font id (0-255): ");
    scanf("%d", &id);
    id = id & ID_MASK;
    *f = (*f & ~ID_MASK) | id; // 相应位要先置为0之后再用|运算符
    eatline();
}

void get_size(font *f)
{
    int size;

    printf("Enter font size (0-127): ");
    scanf("%d", &size);
    *f &= ~SIZE_MASK;
    *f |= (size << SIZE_SHIFT) & SIZE_MASK;
    eatline();
}

void get_align(font *f)
{
    printf("Select alignment: \n");
    printf("l) left  c) center  r) right\n");
    switch (get_choice("lcr"))
    {
    case 'l':
        *f &= ~ALIGN_MASK;
        *f |= LEFT;
        break;
    case 'c':
        *f &= ~ALIGN_MASK;
        *f |= CENTER;
        break;
    case 'r':
        *f &= ~ALIGN_MASK;
        *f |= RIGHT;
        break;
    default:
        printf("unknown alignment\n");
    }
}