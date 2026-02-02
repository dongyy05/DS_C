#include"../include/SCList.h"

void InitSCList(List* list){
    Node *s = (Node*)malloc(sizeof(Node));
    assert(s!=NULL);
    list->first = list->last = s;
    list->last->next = list->first;
    list->size = 0;

}

Node* _buynode(ElementType x){
    Node *s = (Node*)malloc(sizeof(Node));
    assert(s!=NULL);
    s->data = x;
    s->next = NULL;
    return s;
}
void push_back(List* list, ElementType x){
    Node *s = _buynode(x);
    list->last->next = s;
    list->last = s;
    list->last->next = list->first; 
    list->size++;
}

void push_front(List* list, ElementType x){
    Node *s = _buynode(x);
    s->next = list->first->next;
    list->first->next = s;
    if(list->first==list->last)
        list->last = s;
    list->last->next = list->first;
    list->size++;  
}

void show_list(List *list){
    Node *p = list->first->next;
    while(p!=list->first){
        printf("%d-->", p->data);
        p = p->next;
    }
    printf("NUl.\n");
}

void pop_back(List* list){
    if(list->size == 0)
        return;
    Node *p = list->first;
    while(p->next!=list->last){
        p = p->next;
    }
    free(list->last); //必须释放掉不然成为野指针，造成内存泄漏
    list->last = p;
    list->last->next = list->first;
    list->size--;
}
void pop_front(List* list){
    if(list->size == 0)
        return;
    Node *p = list->first->next;
    list->first->next = p->next;
    if(list->size == 1){
        list->last = list->first;
    }
    free(p);
    list->last->next = list->first;
    list->size--;

}
void insert_val(List* list, ElementType x){
    Node *p = list->first;
    while(p->next != list->last && p->next->data < x){
        p = p->next;
    }

    if(p->next == list->last && list->last->data<x){
        push_back(list, x);
    }
    else{
        Node *s = _buynode(x);
        assert(s!=NULL);
        s->next = p->next;
        p->next = s;
        list->size++;
    }
}
PNode find_val(List* list, ElementType key)
{
    if(list->size == 0)
        return NULL;
    Node *p = list->first->next;

    while(p != list->first && p->data!=key)
        p = p->next;
    if(p == list->first)
        return NULL;
    return p;
}
int length(List* list){
    return list->size;
}
void delete_val(List* list, ElementType key){
    if(list->size == 0)
        return;
    Node *p = find_val(list, key);
    if(p == NULL)
    {
        printf("要删除的元素不存在.\n");
        return;
    }
    if(p == list->last){
        pop_back(list);
    }
    else{
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
    Node *s = list->first->next;
    Node *q = s->next;

    list->last->next = NULL;
    list->last = s;
    list->last->next = list->first;

    while(q!=NULL){
        s = q;
        q = q->next;
        
        Node *p = list->first;
        while(p->next != list->last && p->next->data < s->data){
            p = p->next;
        }

        if(p->next == list->last && list->last->data < s->data){
            s->next = list->last->next;
            list->last->next = s;
            list->last = s;
        }
        else{
            s->next = p->next;
            p->next = s;
            list->size++;
        }
    }
    
}
void reverse(List* list){
    if(list->size==0 || list->size == 1) return;
    Node *p = list->first->next;
    Node *q = p->next;

    list->last->next = NULL;
    list->last = p;
    list->last->next = list->first; // p->next = list->first

    while(q!=NULL){
        p = q;
        q = q->next;

        p->next = list->first->next;
        list->first->next = p;
    }

}
void clear(List* list){
    Node *p = list->first->next;
    while(p !=list->first){
        list->first->next = p->next;
        free(p);
        p = list->first->next;
    }
    list->last = list->first;
    list->last->next = list->first;
    list->size = 0;

}
void destroy(List* list){
    clear(list);
    free(list->first);
    list->first = list->last = NULL;
    
}