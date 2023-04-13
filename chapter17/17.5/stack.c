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
    if (FullStack(ps)) // ���ջ�������ش���
        return false;

    ps->items[ps->top] = item; // ����ջ��
    ps->top++;                 // ѹջ
    return true;
}

bool Pop(Item *pitem, Stack *ps)
{
    if (FullStack(ps))
        return false;

    ToBeTrueIndex(&ps->top);
    *pitem = ps->items[ps->top]; // ̧ջ
    //	ps->top--;						//����ջ��

    if (ps->top == 0) // ���ջȫ�汻̧��ͳ�ʼ��ջ
        InitializeStack(ps);

    return true;
}

static void ToBeTrueIndex(int *index)
{
    --(*index); // ָ��ջ������
}