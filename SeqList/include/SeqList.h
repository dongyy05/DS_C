#ifndef _SEQLIST_H_
#define _SEQLIST_H_
#define MAXSIZE 8
#define INC_SIZE 3
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int ElemType;

typedef struct SeqList{
    ElemType* val;
    int capacity;
    int size;
}SeqList;

void InitSeqList(SeqList* L);
void push_back(SeqList* List, ElemType x);
void show_list(SeqList* List);
void push_front(SeqList* List, ElemType x);
void pop_back(SeqList* List);
void pop_front(SeqList* List);
void insert_at(SeqList* List, int pos, ElemType x);
int find(SeqList* List, ElemType x);
int length(SeqList* List);
void delete_pos(SeqList* List, int pos);
void delete_val(SeqList* List, ElemType x);
void sort(SeqList* List);
void reverse(SeqList* List);
void clear(SeqList* List);
void destroy(SeqList* List);
void merge(SeqList* dest, SeqList* src1, SeqList* src2);
#endif