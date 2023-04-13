/* tree.c -- tree support functions */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/* local data type */
typedef struct pair
{
    Trnode *parent;
    Trnode *child;
} Pair;

/* protototypes for local functions */
static Trnode *MakeNode(const Item *pi);
static bool ToLeft(const Item *i1, const Item *i2);
static bool ToRight(const Item *i1, const Item *i2);
static void AddNode(Trnode *new_node, Trnode *root);
static void InOrder(const Trnode *root, void (*pfun)(Item item));
static Pair SeekItem(const Item *pi, const Tree *ptree);
static void DeleteNode(Trnode **ptr);
static void DeleteAllNodes(Trnode *ptr);
static bool TestSame(const Item *i1, const Item *i2);
static void ToBeTrueIndex(Item *item);

/* function definitions */
void InitializeTree(Tree *ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsEmpty(const Tree *ptree)
{
    if (ptree->root == NULL)
        return true;
    else
        return false;
}

bool TreeIsFull(const Tree *ptree)
{
    if (ptree->size == MAXITEMS)
        return true;
    else
        return false;
}

int TreeItemCount(const Tree *ptree)
{
    return ptree->size;
}

bool AddItem(const Item *pi, Tree *ptree)
{
    Trnode *new_node;
    Trnode *temp;

    if (TreeIsFull(ptree))
    {
        fprintf(stderr, "Tree is full\n");
        return false; /* early return           */
    }

    if ((temp = SeekItem(pi, ptree).child) != NULL) // 传回来的可能是名字相同 也可能是名字种类都相同
    {
        if (TestSame(pi, &temp->item) && (temp->item.index >= MAXLISTS)) // 如果种类也相同 就返回错误
        {
            fprintf(stderr, "Attempted to add duplicate item\n");
            return false; /* early return           */
        }
        else // 只是名字相同
        {
            ToBeTrueIndex(&temp->item);
            strcpy(temp->item.petkind[temp->item.index], pi->petkind[0]);

            //			printf("%s:%s\n", temp->item.petname, temp->item.petkind[0]);
            //			printf("%s:%s\n", temp->item.petname, temp->item.petkind[1]);

            return true;
        }
    }

    new_node = MakeNode(pi); /* points to new node     */
    if (new_node == NULL)
    {
        fprintf(stderr, "Couldn't create node\n");
        return false; /* early return           */
    }
    /* succeeded in creating a new node */
    ptree->size++;

    if (ptree->root == NULL)            /* case 1: tree is empty  */
        ptree->root = new_node;         /* new node is tree root  */
    else                                /* case 2: not empty      */
        AddNode(new_node, ptree->root); /* add node to tree  */

    return true; /* successful return      */
}

bool InTree(const Item *pi, const Tree *ptree)
{
    return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

bool DeleteItem(const Item *pi, Tree *ptree)
{
    Pair look;

    look = SeekItem(pi, ptree);
    if (look.child == NULL)
        return false;

    if (look.parent == NULL) /* delete root item       */
        DeleteNode(&ptree->root);
    else if (look.parent->left == look.child)
        DeleteNode(&look.parent->left);
    else
        DeleteNode(&look.parent->right);
    ptree->size--;

    return true;
}

void Traverse(const Tree *ptree, void (*pfun)(Item item))
{
    if (ptree != NULL)
        InOrder(ptree->root, pfun);
}

void DeleteAll(Tree *ptree)
{
    if (ptree != NULL)
        DeleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->size = 0;
}

// 有点纠结这算是接口还是内部函数 但感觉肯定不算内部函数
void SpecialPet(const Item *pi, const Tree *ptree)
{
    Trnode *temp;
    int i;

    temp = SeekItem(pi, ptree).child;

    printf("Pet: %-19s  Kind:", temp->item.petname);
    for (i = 0; i <= temp->item.index; i++)
        printf("  %s", temp->item.petkind[i]);
    printf("\n");
}

/* local functions */
static void InOrder(const Trnode *root, void (*pfun)(Item item))
{
    if (root != NULL)
    {
        InOrder(root->left, pfun);
        (*pfun)(root->item);
        InOrder(root->right, pfun);
    }
}

static void DeleteAllNodes(Trnode *root)
{
    Trnode *pright;

    if (root != NULL)
    {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}

static void AddNode(Trnode *new_node, Trnode *root)
{
    if (ToLeft(&new_node->item, &root->item))
    {
        if (root->left == NULL)    /* empty subtree       */
            root->left = new_node; /* so add node here    */
        else
            AddNode(new_node, root->left); /* else process subtree*/
    }
    else if (ToRight(&new_node->item, &root->item))
    {
        if (root->right == NULL)
            root->right = new_node;
        else
            AddNode(new_node, root->right);
    }
    else /* should be no duplicates */
    {
        fprintf(stderr, "location error in AddNode()\n");
        exit(1);
    }
}

static bool ToLeft(const Item *i1, const Item *i2)
{
    int comp1;

    if ((comp1 = strcmp(i1->petname, i2->petname)) < 0)
        return true;
    //    else if (comp1 == 0 &&							//不用比较种类
    //             strcmp(i1->petkind, i2->petkind) < 0 )
    //        return true;
    else
        return false;
}

static bool ToRight(const Item *i1, const Item *i2)
{
    int comp1;

    if ((comp1 = strcmp(i1->petname, i2->petname)) > 0)
        return true;
    //    else if (comp1 == 0 &&							//不用比较种类
    //             strcmp(i1->petkind, i2->petkind) > 0 )
    //        return true;
    else
        return false;
}

static Trnode *MakeNode(const Item *pi)
{
    Trnode *new_node;

    new_node = (Trnode *)malloc(sizeof(Trnode));
    if (new_node != NULL)
    {
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }

    new_node->item.index = 0; // 初始化节点的下标为0

    return new_node;
}

static Pair SeekItem(const Item *pi, const Tree *ptree)
{
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;

    if (look.child == NULL)
        return look; /* early return   */

    while (look.child != NULL)
    {
        if (ToLeft(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else       /* must be same if not to left or right    */
            break; /* look.child is address of node with item */
    }

    return look; /* successful return   */
}

static void DeleteNode(Trnode **ptr)
/* ptr is address of parent member pointing to target node  */
{
    Trnode *temp;

    if ((*ptr)->left == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }
    else if ((*ptr)->right == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
    else /* deleted node has two children */
    {
        /* find where to reattach right subtree */
        for (temp = (*ptr)->left; temp->right != NULL;
             temp = temp->right)
            continue;
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
}

static bool TestSame(const Item *i1, const Item *i2)
{
    int i;

    for (i = 0; i <= i2->index; i++)
        if (!strcmp(i1->petkind[0], i2->petkind[i])) // 有相同种类的返回True
            return true;

    return false;
}

static void ToBeTrueIndex(Item *item)
{
    ++(item->index); // 指向下一个 下标
}