#include <stdio.h>
#include "stack.h"

static void ToBeTrueIndex(int *index);

void InitializeStack(Stack *ps)
{
    ps->top = 0;
    ps->items[MAXSTACK] = {0};
}

bool FullStack(const Stack *ps)
{
    return ps->top == MAXSTACK - 1;
}

bool EmptyStack(const Stack *ps)
{
    return ps->top == 0;
}

bool Push(Item item, Stack *ps)
{
    if (FullStack(ps)) // 如果栈已满返回错误
        return false;

    ps->items[ps->top] = item; // 放入栈顶
    ps->top++;                 // 压栈
    return true;
}

bool Pop(Item *pitem, Stack *ps)
{
    if (FullStack(ps))
        return false;

    ToBeTrueIndex(&ps->top);
    *pitem = ps->items[ps->top]; // 抬栈
    //	ps->top--;						//调整栈顶

    if (ps->top == 0) // 如果栈全面被抬完就初始化栈
        InitializeStack(ps);

    return true;
}

static void ToBeTrueIndex(int *index)
{
    --(*index); // 指向栈顶数据
}