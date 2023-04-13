/*4.8.2 -- 多格式打印名�?*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
int main(void)
{
    char name[40];
    cout << "Please enter your name: ";
    cin >> name;
    printf("\"%s\"\n", name);
    printf("\"%20s\"\n", name);
    printf("\"%-20s\"\n", name);
    printf("%*s\n", strlen(name) + 3, name);

    system("pause");
    return 0;
}