/* list.c -- functions supporting list operations */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/* local function prototype */
static void CopyToNode(Item item, Node *pnode);
static void CopyToItem(Item item, Item *entries, int n);

/* interface functions   */
/* set the list to empty */
void InitializeList(List *plist)
{
    plist->entries[MAXSIZE] = {0};
    plist->items = 0;
}

/* returns true if list is empty */
bool ListIsEmpty(const List *plist)
{
    if (plist->items == 0) // 直接借用items当下标 所以为0~99
        return true;
    else
        return false;
}

/* returns true if list is full */
bool ListIsFull(const List *plist)
{
    Node *pt;
    bool full;

    pt = (Node *)malloc(sizeof(Node));
    if (pt == NULL)
        full = true;
    else
        full = false;
    free(pt);

    return full;
}

/* returns number of nodes */
unsigned int ListItemCount(const List *plist)
{
    //    unsigned int count = 0;
    //    Node * pnode = *plist;    /* set to start of list */
    //
    //    while (pnode != NULL)
    //    {
    //        ++count;
    //        pnode = pnode->next;  /* set to next node     */
    //    }

    return plist->items; // 一句到位
}

/* creates node to hold item and adds it to the end of */
/* the list pointed to by plist (slow implementation)  */
bool AddItem(Item item, List *plist)
{
    //    Node * pnew;
    //    Node * scan = *plist;

    //    pnew = (Node *) malloc(sizeof(Node));
    //    if (pnew == NULL)
    //        return false;     /* quit function on failure  */

    //    CopyToNode(item, pnew);
    //    pnew->next = NULL;
    //    if (scan == NULL)          /* empty list, so place */
    //        *plist = pnew;         /* pnew at head of list */
    //    else
    //    {
    //        while (scan->next != NULL)
    //            scan = scan->next;  /* find end of list    */
    //        scan->next = pnew;      /* add pnew to end     */
    //    }
    if (plist->items >= MAXSIZE)
        return false;

    CopyToItem(item, plist->entries, plist->items);
    plist->items++;

    return true;
}

/* visit each node and execute function pointed to by pfun */
void Traverse(const List *plist, void (*pfun)(Item item))
{
    //    Node * pnode = *plist;    /* set to start of list   */
    //
    //    while (pnode != NULL)
    //    {
    //        (*pfun)(pnode->item); /* apply function to item */
    //        pnode = pnode->next;  /* advance to next item   */
    //    }

    int i;

    for (i = 0; i < plist->items; i++)
        (*pfun)(plist->entries[i]);
}

/* free memory allocated by malloc() */
/* set list pointer to NULL          */
void EmptyTheList(List *plist)
{
    //    Node * psave;
    //
    //    while (*plist != NULL)
    //    {
    //        psave = (*plist)->next; /* save address of next node */
    //        free(*plist);           /* free current node         */
    //        *plist = psave;         /* advance to next node      */
    //    }

    plist->entries[MAXSIZE] = {0};
    plist->items = 0;
}

/* local function definition  */
/* copies an item into a node */
static void CopyToNode(Item item, Node *pnode)
{
    pnode->item = item; /* structure copy */
}

static void CopyToItem(Item item, Item *entries, int n)
{
    strcpy(entries[n].title, item.title);
    entries[n].rating = item.rating;
}