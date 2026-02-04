#ifndef __DLIST_H__
#define __DLIST_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define ElementType int

typedef struct Node{
    ElementType data;
    struct Node* prio;
    struct Node* next;
}DNode, *PNode;

typedef struct DList{
    PNode first;
    PNode last;
    int size;
}List;

#endif