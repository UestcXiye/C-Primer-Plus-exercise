#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void CopyToNode(Item item, Node *pnode);

void InitializeList(List *plist)
{
    (*plist).head = NULL;
    (*plist).end = NULL;
    return;
}

bool ListIsEmpty(const List *plist)
{
    return NULL == (*plist).head;
}

bool ListIsFull(const List *plist)
{
    Node *pt;
    bool full;

    pt = (Node *)malloc(sizeof(Node));
    if (pt == NULL)
    {
        full = true;
    }
    else
    {
        full = false;
    }
    free(pt);
    return full;
}

unsigned int ListItemCount(const List *plist)
{
    unsigned int count = 0;
    Node *pnode = (*plist).head; // ʹָ��ָ���׽��;

    while (pnode != NULL)
    {
        ++count;
        pnode = pnode->next;
    }
    return count;
}

bool AddItem(Item item, List *plist)
{
    Node *pnew;
    Node *scan = (*plist).head;

    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL)
    {
        return false;
    }
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (scan == NULL) // �����׽����ʹͷβ˫ָ��ͬʱָ��˽��;
    {
        (*plist).head = pnew;
        (*plist).end = pnew;
    }
    else
    {
        (*plist).end->next = pnew; // β���ָ����ָ���½��;
        (*plist).end = pnew;       // �½���Ϊβ���;
    }
    return true;
}

void Traverse(const List *plist, void (*pfun)(Item item))
{
    Node *pnode = (*plist).head;

    while (pnode != NULL)
    {
        (*pfun)(pnode->item);
        pnode = pnode->next;
    }
    return;
}

void EmptyTheList(List *plist)
{
    Node *psave;

    while ((*plist).head != NULL)
    {
        psave = (*plist).head->next;
        free((*plist).head);
        (*plist).head = psave;
    }
    return;
}

static void CopyToNode(Item item, Node *pnode)
{
    pnode->item = item;
    return;
}
