#include <stdio.h>
#include <stdlib.h>
void chline(char, int, int);
int main(void)
{
    char c;
    int rows, cols;
    printf("Enter a character: ");
    scanf("%c", &c);
    printf("Enter the rows and cols: ");
    scanf("%d %d", &rows, &cols);
    chline(c, rows, cols);

    system("pause");
    return 0;
}
void chline(char ch, int i, int j)
{
    for (int row = 0; row < j; row++)
    {
        for (int col = 0; col < i; col++)
        {
            putchar(ch);
        }
        printf("\n");
    }
}