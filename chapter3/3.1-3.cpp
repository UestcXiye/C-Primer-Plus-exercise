#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    float toobig = 3.4e38 * 100.0f;
    float tosmall = 0.1234e-45;

    printf("%f\n", toobig);  //上溢，输出1.#INF00
    printf("%e\n", tosmall); //下溢，输出0.000000e+000

    system("pause");
    return 0;
}
