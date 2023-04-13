/*4.8.4 -- 打印身高和姓名*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main(void)
{
    float height;  //单位：英寸
    char name[40]; //姓名
    cout << "Please input your height: ";
    cin >> height;
    cout << "Please input your name: ";
    cin >> name;
    printf("%s, you are %.3f feet tall\n", name, height);

    system("pause");
    return 0;
}