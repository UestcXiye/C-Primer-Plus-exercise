#include <stdio.h>
#include <stdlib.h>
void display(char c, int lines, int width);
int main(void)
{
    char ch;
    int rows, cols;

    printf("Enter a character and two integers:\n");
    while ((ch = getchar()) != '\n')
    {
        if (scanf("%d %d", &rows, &cols) != 2)
            break;
        display(ch, rows, cols);
        while (getchar() != '\n')
            continue;
        printf("Enter another character and two integers;\n");
        printf("Enter a newline to quit.\n");
    }
    printf("Bye.\n");

    system("pause");
    return 0;
}
void display(char c, int lines, int width)
{
    for (int row = 0; row < lines; row++)
    {
        for (int col = 0; col < width; col++)
        {
            putchar(c);
        }
        printf("\n");
    }
}