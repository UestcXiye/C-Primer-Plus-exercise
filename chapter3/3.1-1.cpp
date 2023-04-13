#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    // unsigned char占2字节，取值范围为：0~256
    unsigned char a = 256 + 1;
    printf("%d\n", a); //输入1

    system("pause");
    return 0;
}

