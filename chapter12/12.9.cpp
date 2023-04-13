#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n;

    printf("How many words do you wish to enter? ");
    scanf("%d", &n);
    printf("Enter %d words now:\n", n);
    char **a = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        char b[100];
        scanf("%s", b);
        int n = strlen(b);
        char *str = (char *)malloc((n + 1) * sizeof(char));
        for (int j = 0; j < n; j++)
        {
            str[j] = b[j];
        }
        str[n] = '\0';
        a[i] = str;
    }
    printf("Here are your words:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", a[i]);
    }

    system("pause");
    return 0;
}