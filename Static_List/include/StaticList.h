#ifndef __STATICLIST_H_
#define __STATICLIST_H_

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20
#define ElemType char

typedef struct LNode
{
    ElemType data;
    int cur;
}ListNode;


typedef ListNode StaticList[MAXSIZE];

int Malloc_SL(StaticList &space);
void InitList(StaticList &L); // 引用就是别名，不需要开辟新空间
void Insert(StaticList &space, ElemType x);
void ShowSList(StaticList &space);
void Delete(StaticList &space);
#endif // !__STATICLIST_H_
