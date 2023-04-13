/*4.8.6 -- 打印姓名和字符长度*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
int main(void)
{
    char name[40];    //名
    char surname[40]; //姓

    cout << "Please enter your name: ";
    cin >> name;
    cout << "and enter your surname: ";
    cin >> surname;

    printf("%s %s\n", name, surname);
    printf("%*d %*d\n", strlen(name), strlen(name), strlen(surname), strlen(surname));
    printf("%s %s\n", name, surname);
    printf("%-*d %-*d\n", strlen(name), strlen(name), strlen(surname), strlen(surname));
    system("pause");
    return 0;
}