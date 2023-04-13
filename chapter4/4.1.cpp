/*4.8.1 -- 打印姓名*/
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
int main(void)
{
    char name[40];//�?
    char surname[40];//�?
    cout<<"Please enter your name: ";
    cin>>name;
    cout<<"and enter your surname: ";
    cin>>surname;
    cout<<name<<","<<surname<<endl;

    system("pause");
    return 0;
}