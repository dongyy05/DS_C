#include"../include/StaticList.h"

int main(){
    StaticList SL;
    InitList(SL);

    for(int i = 0; i<5; i++){
        Insert(SL, 'A'+i);
    }
    ShowSList(SL);
    Delete(SL);
    ShowSList(SL);
}
