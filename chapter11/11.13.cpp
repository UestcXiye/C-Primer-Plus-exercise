#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    printf("the command line has %d arguments.\n", argc - 1);
    printf("Print them in reversed order:\n");
    for (int i = 1; i < argc; i++)
        printf("%s ", argv[argc - i]);
    putchar('\n');

    system("pause");
    return 0;
}