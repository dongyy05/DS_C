#include"../include/StaticList.h"

int Malloc_SL(StaticList &space){
    int i = space[1].cur;
    // if(i != 0) // 如果有可用空闲结点, 更新空闲链表头
    if(space[i].cur!=0)
        space[1].cur = space[i].cur;
    return i;
}
void InitList(StaticList &space){
    for(int i = 1; i<MAXSIZE-1; i++){
        space[i].cur = i+1;
    }
    space[MAXSIZE-1].cur = 0;
    space[0].cur = -1;
}

void Insert(StaticList &space, ElemType x){
    int i = Malloc_SL(space);
    if(i == 0){
        printf("申请结点空间失败.\n");
        return;
    }
    space[i].data = x;
    if(space[0].cur==-1){
        space[i].cur = -1;
        // space[0].cur = i;
    }
    else{
        space[i].cur = space[0].cur;
    }
    space[0].cur = i;
}

void ShowSList(StaticList &space){
    int i = space[0].cur;
    while(i != -1){
        printf("%c-->", space[i].data);
        i = space[i].cur;
    }
    printf("NULL.\n");
}
void Delete(StaticList &space){
     int i = space[0].cur;
     space[0].cur = space[i].cur;

     space[i].cur = space[1].cur;
     space[1].cur = i;
}