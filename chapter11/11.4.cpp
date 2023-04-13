#include <stdio.h>
#include <stdlib.h>
void get_word(char *, int);
int main(void)
{
    int n;
    printf("Enter maximum number of characters: ");
    scanf("%d", &n);
    char arr[n + 1];

    get_word(arr, n);
    puts(arr);

    system("pause");
    return 0;
}
void get_word(char *a, int n)
{

    char ch;
    int i = 0;

    while ((ch = getchar()) <= ' ')
        continue;
    while (ch > ' ' && i++ < n)
    {
        *a = ch;
        a++;
        ch = getchar();
    }
}