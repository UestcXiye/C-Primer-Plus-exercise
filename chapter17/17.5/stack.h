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

/*������		��ʼ��ջ											*/
/*ǰ��������	psָ��һ��ջ										*/
/*����������	��ջ��ʼ��Ϊ��										*/
void InitializeStack(Stack *ps);

/*������		���ջ�Ƿ�����										*/
/*ǰ��������	psָ��֮ǰ�ѱ���ʼ����ջ							*/
/*����������	���ջ�Ѿ������ú�������true						*/
bool FullStack(const Stack *ps);

/*������		���ջ�Ƿ�Ϊ��										*/
/*ǰ��������	psָ��֮ǰ�ѱ���ʼ����ջ							*/
/*����������	���ջΪ�գ��ú����Ż�ture�����ߣ�����false			*/
bool EmptyStack(const Stack *ps);

/*������		����ѹ��ջ��										*/
/*ǰ��������	psָ��֮ǰ�ѱ���ʼ����ջ							*/
/*				items�Ǵ�ѹ��ջ������				 				*/
/*����������	���ջ��������item����ջ�����ú�������true��		*/
/*				����ջ���䣬�ú�������false		 				*/
bool Push(Item item, Stack *ps);

/*������		��ջ��ɾ����										*/
/*ǰ��������	psָ��֮ǰ�ѱ���ʼ����ջ							*/
/*����������	���ջ��Ϊ�գ���item������*pitem					*/
/*				ɾ��ջ����item���ú�������true		 				*/
/*				����ò�����ջ��û��������ø���Ϊ��				*/
/*				���ɾ������֮ǰջΪ�գ�ջ���䣬�ú�������false		*/
bool Pop(Item *pitem, Stack *ps);

#endif