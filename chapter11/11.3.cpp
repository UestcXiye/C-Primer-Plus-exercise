#include <stdio.h>
#include <stdlib.h>
#define STRLEN 100
void get_word(char *);
int main(void)
{
    char arr[STRLEN];

    get_word(arr);
    puts(arr);

    system("pause");
    return 0;
}
void get_word(char *a)
{

    char ch;
    
    while ((ch = getchar()) <= ' ')
        continue;
    while (ch > ' ')
    {
        *a = ch;
        a++;
        ch = getchar();
    }
}