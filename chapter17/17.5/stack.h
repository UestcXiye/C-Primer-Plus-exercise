#ifndef STACK_H_
#define STACK_H_

#include <stdbool.h>

#define MAXSTACK 10

typedef char Item;
typedef struct stack
{
    int top;
    Item items[MAXSTACK];
} Stack;

/*操作：		初始化栈											*/
/*前提条件：	ps指向一个栈										*/
/*后置条件：	该栈初始化为空										*/
void InitializeStack(Stack *ps);

/*操作：		检查栈是否已满										*/
/*前提条件：	ps指向之前已被初始化的栈							*/
/*后置条件：	如果栈已经满，该函数返回true						*/
bool FullStack(const Stack *ps);

/*操作：		检查栈是否为空										*/
/*前提条件：	ps指向之前已被初始化的栈							*/
/*后置条件：	如果栈为空，该函数放回ture；否者，返回false			*/
bool EmptyStack(const Stack *ps);

/*操作：		把项压入栈顶										*/
/*前提条件：	ps指向之前已被初始化的栈							*/
/*				items是待压入栈顶的项				 				*/
/*后置条件：	如果栈不满，把item放在栈顶，该函数返回true；		*/
/*				否则，栈不变，该函数返回false		 				*/
bool Push(Item item, Stack *ps);

/*操作：		从栈顶删除项										*/
/*前提条件：	ps指向之前已被初始化的栈							*/
/*后置条件：	如果栈不为空，把item拷贝到*pitem					*/
/*				删除栈顶的item，该函数返回true		 				*/
/*				如果该操作后栈中没有项，则重置该项为空				*/
/*				如果删除操作之前栈为空，栈不变，该函数返回false		*/
bool Pop(Item *pitem, Stack *ps);

#endif