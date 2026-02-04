#include"../include/Dlist.h"


void InitDList(List* list){
    Node *s = (Node*)malloc(sizeof(Node));
    assert(s!=NULL);
    list->first = list->last = s;
    list->last->next = NULL;
    list->first->prio = NULL;
    list->size = 0;
}
Node* _buynode(ElementType x){
    Node *s = (Node*)malloc(sizeof(Node));
    assert(s!=NULL);
    s->data = x;
    s->next = s->prio = NULL;
    return s;
}
void push_back(List* list, ElementType x){
    Node *s = _buynode(x);
    s->prio = list->last;
    list->last->next = s;
    list->last = s;
    list->size++;
}
void push_front(List* list, ElementType x){
    Node *s = _buynode(x);
    if(list->first == list->last)
    {
        // s->prio = list->first;
        // list->first->next = s;
        list->last = s;
    }
    else{
        s->next = list->first->next;
        s->next->prio = s;
    }
    s->prio = list->first;
    list->first->next = s;

    list->size++;
}
void show_list(List* list){
    Node *p = list->first->next;
    while(p!=NULL){
        printf("%d-->", p->data);
        p = p->next;
    }
    printf("Nul.\n");

}
void pop_back(List* list){
    if(list->size==0)
        return;
    Node *p = list->first;
    while(p->next!=list->last) p = p->next;

    free(list->last);
    list->last = p;
    list->last->next = NULL;
    list->size--;
}
void pop_front(List* list){
    if(list->size == 0)
        return;
    Node *p = list->first->next;
    if(p->next==NULL){
        list->last = list->first;
        list->last->next = NULL;

    }else{
        p->next->prio = list->first;
        list->first->next = p->next;
    }
    free(p);
    list->size--;
}
void insert_val(List* list, ElementType x){
    Node *p = list->first;
    while(p->next!=NULL && p->next->data < x){
        p = p->next;
    }
    if(p->next == NULL){
        push_back(list, x);
    }
    else{
        Node *s = _buynode(x);
        s->next = p->next;
        s->next->prio = p;
        p->next = s;
        list->size++;
    }
}
PNode find_val(List* list, ElementType key);
int length(List* list){
    return list->size;
}
void delete_val(List* list, ElementType key);
void sort(List* list);
void reverse(List* list);
void clear(List* list);
void destroy(List* list);