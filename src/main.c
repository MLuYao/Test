#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#define MAXSIZE 256
#define OVERFLOW -2
typedef struct
{
	int n;
} Element;
typedef struct
{
	Element *elem;
	int length;	 // 实际长度
	int maxsize; // 最大长度
} SqList;
// 初始化函数
int InitList(SqList *L)
{
	L->elem = (Element *)malloc(sizeof(Element) * MAXSIZE);
	if (!L->elem)
		exit(OVERFLOW);
	L->length = 0;
	L->maxsize = MAXSIZE;
	return 0;
}
// 插入函数
int ListInsert(SqList *L, int i, Element data)
{
	if (i < 0 || i > L->length)
	{
		exit(OVERFLOW);
	}
	int j;
	for (j = L->length - 1; j >= i; j--)
	{
		L->elem[j + 1] = L->elem[j];
	}
	L->elem[i] = data;
	++L->length;
	return 0;
}
// 删除函数
int ListDelete(SqList *L, int i)
{
	if (i < 0 || i >= L->length)
	{
		exit(OVERFLOW);
	}
	int j;
	for (j = i; j < L->length - 1; j++)
	{
		L->elem[j] = L->elem[j + 1];
	}
	L->length--;
}
// 查找函数
int GetElement(SqList *L, int i, Element *e)
{
	if (i < 0 || i >= L->length)
	{
		exit(OVERFLOW);
	}
	*e = L->elem[i];
	return 0;
}
int main()
{
	Element a = {5};
	SqList p;
	InitList(&p);
	ListInsert(&p, 0, a);
	GetElement(&p, 0, &a);
	ListDelete(&p, 0);
	printf("%d", a.n);
	return 0;
}