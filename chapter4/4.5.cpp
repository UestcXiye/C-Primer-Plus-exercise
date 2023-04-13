/*4.8.5 -- 打印文件下载时间*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main(void)
{
    float speed;
    float file;
    cout << "Please input the download speed and the file size: ";
    cin >> speed >> file;

    printf("At %.2f megabits per second, a file of %.2f megabytes\ndownloads in %.2f seconds.\n", speed, file, file * 8 / speed);

    system("pause");
    return 0;
}