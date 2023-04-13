/*4.8.8 -- 打印里程*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define gallonToLitre 3.785
#define mileToKm 1.609
int main(void)
{
    float mile;   //英里
    float gallon; //加仑
    cout << "Please input the miles and gallons: ";
    cin >> mile >> gallon;
    printf("%f gallon/mile = %.1f L/100km.\n", gallon / mile, gallon * gallonToLitre / (mile * mileToKm * 100));

    system("pause");
    return 0;
}