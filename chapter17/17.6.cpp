#include <stdio.h>
#include <stdlib.h>
#include <math.h> //for pow()

#define MAX 1024

void Init_Array(int *arr, int n);
int Binary_Search(int *target, int n, int key);

int main()
{
    int data[MAX];
    int num;

    Init_Array(data, MAX);
    printf("Enter a number, I'll tell you if it's in the array(enter q to quit): ");
    while (scanf("%d", &num) == 1)
    {
        printf("%d\n", Binary_Search(data, MAX, num));
        printf("Try again: ");
    }
    printf("Bye!\n");

    system("pause");
    return 0;
}

void Init_Array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
}

int Binary_Search(int *target, int n, int key)
{
    int i;
    int index;
    int min = 0, max = n;
    int step = 0;
    int answer = 0;

    while (pow(2, step) < n) // 判断是多少2^n - 1以内
        step++;

    index = n / 2; // 到中间的位置
    for (i = 0; i < step; i++)
    {
        if (key < target[index])
        {
            max = index;
            index = (min + index) / 2;
        }
        else if (key > target[index])
        {
            min = index;
            index = (index + max) / 2;
        }
        else
            answer = 1;
    }

    return answer;
}
