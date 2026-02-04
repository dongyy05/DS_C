#include"../include/Dlist.h"


void InitDList(List* list){
    Node *s = (Node*)malloc(sizeof(Node));
    assert(s!=NULL);
    list->first = list->last = s;
    list->last->next = NULL;
    list->first->prio = NULL;
    list->size = 0;
}