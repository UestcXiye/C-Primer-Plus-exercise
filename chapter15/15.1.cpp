#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int stoi(const char *s);

int main()
{
    char *pbin = "01001001";
    printf("%s = %d\n", pbin, stoi(pbin));

    system("pause");
    return 0;
}

int stoi(const char *s)
{
    int len = strlen(s);
    int ans = 0;

    for (int i = 0; i < len; i++)
        if (s[i] == '1')
            ans += pow(2, len - 1 - i);

    return ans;
}