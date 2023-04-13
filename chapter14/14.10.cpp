#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM 4

double twice(double x) { return 2.0 * x; }
double half(double x) { return x / 2.0; }
double thrice(double x) { return 3.0 * x; }

void showmenu(void);

int main()
{
    double (*fp[NUM])(double) = {twice, half, thrice, sqrt};
    double val, ans;
    int choice;

    puts("Enter a number (negative to quit): ");
    while (scanf("%lf", &val) == 1 && val > 0)
    {
        showmenu();
        while (scanf("%d", &choice) == 1 && choice >= 0 && choice <= 3)
        {
            ans = (*fp[choice])(val); // ans = fp[choice](val);
            printf("answer = %.2f\n", ans);
            showmenu();
        }
        puts("Enter a number (negative to quit): ");
    }
    puts("Bye.");

    system("pause");
    return 0;
}

void showmenu(void)
{
    puts("Enter one of the following choices: ");
    puts("0) double the value            1) halve the value");
    puts("2) triple the value            3) squareroot the value");
    puts("4) next number");
}
