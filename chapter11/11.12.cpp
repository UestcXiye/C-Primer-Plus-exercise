#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void basic(void);
int main(void)
{
    char ch;
    int words = 0;
    int upper = 0;
    int lower = 0;
    int punct = 0;
    int digit = 0;
    bool is_word = false;

    printf("please input strings(EOF to quit): \n");
    while ((ch = getchar()) != EOF)
    {
        if (!isspace(ch) && is_word == false)
        {
            words++;
            is_word = true;
        }
        if (isspace(ch) && is_word == true)
            is_word = false;
        if (isupper(ch))
            upper++;
        if (islower(ch))
            lower++;
        if (ispunct(ch))
            punct++;
        if (isdigit(ch))
            digit++;
    }
    printf("words: %d\n", words);
    printf("upper: %d\n", upper);
    printf("lower: %d\n", lower);
    printf("punct: %d\n", punct);
    printf("digit: %d\n", digit);

    system("pause");
    return 0;
}
