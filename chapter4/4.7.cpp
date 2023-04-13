/*4.8.7 -- 打印浮点数*/
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <iostream>
using namespace std;
int main(void)
{
    float n1 = 1.0 / 3.0;
    double n2 = 1.0 / 3.0;
    printf("n1: %.6f %.12f %.16f\n", n1, n1, n1);
    printf("n2: %.6f %.12f %.16f\n", n2, n2, n2);
    printf("FLT_DIG: %f\n",FLT_DIG);
    printf("DBL_DIG: %f\n",DBL_DIG);
    
    system("pause");
    return 0;
}