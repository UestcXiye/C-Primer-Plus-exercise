#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char get_first(void);
char get_choice(void);
float get_num(void);
void add(void);
void subtract(void);
void multiply(void);
void divide(void);
int main(void)
{
    char choice;
    while ((choice = get_choice()) != 'q')
    {
        switch (choice)
        {
        case 'a':
            add();
            break;
        case 's':
            subtract();
            break;
        case 'm':
            multiply();
            break;
        case 'd':
            divide();
            break;
        default:
            printf("\nSorry, I understand only a, s, m, d, q, Please try again:\n");
            break;
        }
    }
    printf("Bye!\n");

    system("pause");
    return 0;
}

char get_first(void)
{
    int ch;

    while (isspace(ch = getchar()))
        ;
    while (getchar() != '\n')
        ;
    return ch;
}

char get_choice(void)
{
    int ch;

    printf("Enter the operation of your choice:\n");
    printf("a. add          s. subtract\n");
    printf("m.multiply      d. divide\n");
    printf("q.quit\n");
    ch = get_first();
    return ch;
}

float get_num(void)
{
    float number;
    char ch;

    while (scanf("%f", &number) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch); // 处理错误输出
        printf(" is not a number.\n");
        printf("Please enter a number, such as 15, -1.78E8, or 3: ");
    }
    return number;
}

void add(void)
{
    float num1, num2;
    printf("Enter first number: ");
    num1 = get_num();
    printf("Enter second number: ");
    num2 = get_num();
    printf("%f + %f = %f\n", num1, num2, num1 + num2);
}

void subtract(void)
{
    float num1, num2;
    printf("Enter first number: ");
    num1 = get_num();
    printf("Enter second number: ");
    num2 = get_num();
    printf("%f - %f = %f\n", num1, num2, num1 - num2);
}

void multiply(void)
{
    float num1, num2;
    printf("Enter first number: ");
    num1 = get_num();
    printf("Enter second number: ");
    num2 = get_num();
    printf("%f * %f = %f\n", num1, num2, num1 * num2);
}

void divide(void)
{
    float num1, num2;
    printf("Enter first number: ");
    num1 = get_num();
    printf("Enter second number: ");
    while ((num2 = get_num()) == 0)
    {
        printf("Enter a number other than 0: ");
    }
    printf("%f / %f = %f\n", num1, num2, num1 / num2);
}