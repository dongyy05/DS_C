// #include "../include/LNode.h"
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef char ElmeType;


typedef struct LNode{
    ElmeType data;
    struct LNode* next;
}LNode;

typedef LNode* LinkList;

void InitLNode(LinkList* head){
    *head = (LinkList)malloc(sizeof(LNode));
    assert(*head!=NULL);
    (*head)->next = NULL;

}
/*
改内容 → 传一级指针；
初始化、改指向 传二级指针。
*/

void CreateLNode(LinkList *head){
    LinkList p = *head;
    for(int i = 1; i <=10; i++){
        p = p->next = (LinkList)malloc(sizeof(LNode));
        assert(p!=NULL);
        p->data = i;
        p->next = NULL;
    }
}

// void CreateLNode(LinkList* head){
//     for(int i = 1; i<=10; ++i){
//         LinkList s = (LinkList)malloc(sizeof(LNode));
//         s->data = i;
//         s->next = (*head)->next;
//         (*head)->next = s;
//     }
// }

// void CreateLNode(LinkList* head){
//     *head = (LinkList)malloc(sizeof(LNode));
//     assert(*head!=NULL);
//     (*head)->data = 'a';
//     (*head)->next = NULL;
    
//     for(int i = 2; i <=10; ++i){
//         LinkList s = (LinkList)malloc(sizeof(LNode));
//         assert(s!=NULL);
//         s->data = 'a'+i;
//         s->next = *head;
//         *head = s;
//     }
// }

// void CreateLNode(LinkList* head)
// {
//     (*head)=(LinkList)malloc(sizeof(LNode));
//     assert(*head!=NULL);
//     (*head)->data = 1;
//     (*head)->next = NULL;

//     LinkList p = *head;
//     for(int i = 2; i<=10; ++i){
//         LinkList s = (LinkList)malloc(sizeof(LNode));
//         assert(s!=NULL);
//         s->data = i;
//         s->next = NULL;

//         p->next = s;
//         p = s;
//     }
// }
void ShowLNode(LinkList head){
    // LNode* p = head;
    LinkList p = head->next;
    while(p != NULL)
    {
        printf("%d-->", p->data);
        p = p->next;
    }
    printf("NULL");
}

int main(){
    LinkList L;
    InitLNode(&L);
    CreateLNode(&L);
    ShowLNode(L);
    return 0;
}
