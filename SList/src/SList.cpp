#include "../include/SList.h"

void InitList(List *list)
{
    list->first = list->last = (PNode)malloc(sizeof(Node));
    assert(list->first != NULL);
    list->size = 0;
}

// void push_back(List *mylist, ElementType x)
// {
//     // Node *s = (Node *)malloc(sizeof(Node));
//     // assert(s != NULL);
//     // s->data = x;
//     // s->next = NULL;

//     Node *s = _buynode(x);
//     mylist->last->next = s;
//     mylist->last = s;
//     mylist->size++;
// }

void push_back(List* list, ElementType x){
    insert(list, end(list), x);
}
// void push_front(List *list, ElementType x)
// {
//     // Node *s = (Node *)malloc(sizeof(Node));
//     // assert(s != NULL);
//     // s->data = x;
//     // s->next = NULL;

//     Node *s = _buynode(x);
//     s->next = list->first->next;
//     list->first->next = s;

//     if (list->size == 0) // 注意！！！
//         list->last = s;
//     list->size++;
// }

void push_front(List* list, ElementType x){
    insert(list, begin(list), x);
}

void show_list(List *list)
{
    Node *p = list->first->next;
    while (p != NULL)
    {
        printf("%d-->", p->data);
        p = p->next;
    }
    printf("NULL.\n");
}

void pop_back(List *list)
{
    if (list->size == 0)
        return;

    Node *p = list->first;
    while (p->next != list->last)
    {
        p = p->next;
    }
    free(list->last);
    list->last = p;
    list->last->next = NULL;
    list->size--;
}

void pop_front(List *list)
{
    if (list->size == 0)
        return;
    Node *p = list->first->next;
    list->first->next = p->next;
    free(p);
    if (list->size == 1) // 注意！！！
        list->last = list->first;
    list->size--;
}

void insert_val(List *list, ElementType x)
{
    Node *s = (Node *)malloc(sizeof(Node));
    assert(s != NULL);
    s->data = x;
    s->next = NULL;

    Node *p = list->first;
    while (p->next != NULL && p->next->data < x)
        p = p->next;

    if (p->next == NULL)
        list->last = s;

    s->next = p->next;
    p->next = s;
}

PNode find_val(List *list, ElementType key)
{
    Node *p = list->first->next;
    // while(p->data!=key && p != NULL) 在 C/C++ 中从左到右求值并短路
    while (p != NULL && p->data != key)
    {
        p = p->next;
    }
    return p;
}

int length(List *list)
{
    return list->size;
}

void delete_val(List *list, ElementType key)
{
    if (list->size == 0)
        return;
    Node *p = find_val(list, key);
    if (p == NULL)
    {
        printf("要删除的数据不存在.\n");
        return;
    }
    if (p == list->last)
    {
        pop_back(list);
    }
    else
    {
        Node *q = p->next;
        p->data = q->data;
        p->next = q->next;
        free(q);
        list->size--;
    }
}

void sort(List* list){
    if(list->size == 0 || list->size == 1)
        return;
    Node* s = list->first->next;
    Node* q = s->next;
    list->last = s; 
    list->last->next = NULL;

    while(q != NULL){
        s = q;
        q = q->next;

        Node *p = list->first;
        while (p->next != NULL && p->next->data < s->data)
            p = p->next;

        if (p->next == NULL)
            list->last = s;

        s->next = p->next;
        p->next = s;
    }
    
}

void reverse(List* list){
    if(list->size==0 || list->size == 1)
        return;
    Node* p = list->first->next;
    Node* q = p->next;

    list->last = p;
    list->last->next = NULL;

    while(q!=NULL){
        p = q;
        q = p->next;

        p->next = list->first->next;
        list->first->next = p;
    }
}

void clear(List* list){
    if(list->size == 0){
        list->last = list->first;
        list->first->next = NULL;
        return;
    }

    Node* p = list->first->next;
    Node* q = NULL;
    while(p != NULL){
        q = p->next;
        free(p);
        p = q;
    }
    list->first->next = NULL;
    list->last = list->first;
    list->size = 0;
}

void destroy(List* list){
    clear(list);
    free(list->first);
    list->first = list->last = NULL;
    // list->size = 0;
}
///////////////////////////////////////
Node* _buynode(ElementType x){
    Node* s = (Node*)malloc(sizeof(Node));
    assert(s!=NULL);
    s->data = x;
    s->next = NULL;
    return s;
}
 

It begin(List* list){
    return list->first->next;
}
It end(List* list){
    return list->last->next;
}

void insert(List* list, It pos, ElementType x){
    Node *p = list->first;
    while(p->next!=pos){
        p = p->next;
    }

    Node *s = _buynode(x);
    s->next = p->next;
    p->next = s;
    if(pos == NULL)
        list->last = s;
    list->size++;
}