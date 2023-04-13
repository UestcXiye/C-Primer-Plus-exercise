#include <stdio.h>
#include <stdlib.h>
void get_n_char(char *, int);
int main(void)
{
    int n;
    printf("Enter the number of char: ");
    scanf("%d", &n);
    getchar();

    char arr[n + 1];
    printf("Enter n characters: ");
    get_n_char(arr, n);
    printf("arr: ");
    puts(arr);

    system("pause");
    return 0;
}
void get_n_char(char *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = getchar();
        if (a[i] == ' ' || a[i] == '\n' || a[i] == '\t')
            break;
    }
    a[n] = '\0';
}