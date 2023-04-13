/*4.8.3 -- 多格式打印浮点数*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main(void)
{
    float number;
    cout << "Please input a number: ";
    cin >> number;

    printf("The input is %.1f or %.1e.\n", number, number);
    printf("The input is %+.3f or %.3E.\n", number, number);

    system("pause");
    return 0;
}