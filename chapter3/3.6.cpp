#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int quart;
    printf("please input the quart: ");
    scanf("%d", &quart);
    printf("%d quarts of water has %e water molecules.\n", quart, quart * 950 / (3.0e-23));

    system("pause");
    return 0;
}
