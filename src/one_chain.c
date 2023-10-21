#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
#define OK 1
#define ERROR -1
#define Status int
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
// 单链表初始化
Status InitList(LinkList L)
{
    // L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    return OK;
}
// 插入功能
Status ListInsert(LinkList L, int i, ElemType e)
{
    LinkList p = L;
    // printf("%p\n",p);
    // printf("%p\n",p->next);
    int j = 0;
    while (p && (j < i - 1))
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)
    {
        return ERROR;
    }
    LinkList s = (LinkList)malloc(sizeof(LNode));
    // printf("%p\n",s);
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}
// 单链表的删除
Status ListDelete(LinkList L, int i)
{ // 在带头结点的单链表工中，删除第1个元素
    LinkList p = L;
    int j = 0;
    while ((p->next) && (j < i - 1)) // 查找第主-1个结点，p指向该结点
    {
        p = p->next;
        ++j;
    }
    if (!(p->next) || (j > i - 1)) // 当i>n或i<1时，删除位置不合理
        return ERROR;
    LinkList q = p->next; // 临时保存被删结点的地址以备释放
    p->next = q->next;    // 改变删除结点前驱结点的指针域
    free(q);              // 释放删除结点的空间
    return OK;
}
// 查找
LNode *LocateElem(LinkList L, ElemType e)
{                             // 在带头结点的单链表工中查找值为e的元素
    LinkList p = L->next;     // 初始化，p指向首元结点
    // printf("%p",p);
    while (p && p->data != e) // 顺链域向后查找，直到p为空或p所指结点的数据域等于e
    {
        p = p->next; // p指向下一个结点
    }
    return p; // 查找成功返回值为e的结点地址p，查找失败p为NULL
}

int main()
{
    LNode list;
    InitList(&list);
    // printf("%d\n",list.data);
    // printf("%p\n",list.next);
    ListInsert(&list,1,45);
    ListInsert(&list,1,46);
    ListInsert(&list,1,47);
    ListInsert(&list,1,49);
    printf("%d\n",LocateElem(&list,49)->data);
    // LocateElem(&list,45);
    return 0;
}