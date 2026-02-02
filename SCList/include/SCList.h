#ifndef __SCLIST_H
#define __SCLIST_H

#define ElementType int
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct Node
{
    ElementType data;
    struct Node* next;
} Node, *PNode;

typedef struct List{
    PNode first;
    PNode last;
    int size;
};
Node* _buynode(ElementType x);
void InitSCList(List* list);
void push_back(List* mylist, ElementType x);
void push_front(List* list, ElementType x);
void show_list(List* list);
void pop_back(List* list);
void pop_front(List* list);
void insert_val(List* list, ElementType x);
PNode find_val(List* list, ElementType key);
int length(List* list);
void delete_val(List* list, ElementType key);
void sort(List* list);
void reverse(List* list);
void clear(List* list);
void destroy(List* list);

#endif // __SCLIST_H