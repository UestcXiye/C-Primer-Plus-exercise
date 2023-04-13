#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int age;
    printf("please input your age: ");
    scanf("%d", &age);
    printf("You've been alive for %f seconds.\n", age * 3.156e7);

    system("pause");
    return 0;
}
