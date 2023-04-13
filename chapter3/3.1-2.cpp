#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    // signed char占2字节，取值范围为：-128~127
    signed char a = -129;
    signed char b = 128;
    printf("%d\n", a); //下溢，输入127
    printf("%d\n", b); // 上溢，输出-128
    system("pause");
    return 0;
}
