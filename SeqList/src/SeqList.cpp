#include "../include/SeqList.h"

bool Inc(SeqList* List){
    ElemType* newbase = (ElemType*)realloc(List->val, 
        sizeof(ElemType)*(List->capacity + INC_SIZE));
    if(newbase == NULL)
    {
        printf("增配空间失败，内存不足.\n");
        return false;
    }
    List->val = newbase;
    List->capacity += INC_SIZE;
    return true;

}

void InitSeqList(SeqList* L)
{
    L->val = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    assert(L->val!=NULL);
    L->capacity = MAXSIZE;
    L->size = 0;
}

void push_back(SeqList* List, ElemType x){
    if(List->size >= List->capacity &&  !Inc(List)){
        printf("顺序表空间已满，%d不能尾部插入数据.\n", x);
        return;
    }
    List->val[List->size] = x;
    List->size++;
}

void push_front(SeqList* List, ElemType x){
    if(List->size>=List->capacity){
        printf("顺序表空间已满，不能尾部插入数据.\n");
        return;
    }
    if(List->size!=0){ 
        for(int i=List->size;i>0;i--){
            List->val[i]=List->val[i-1];
        }
    }
    List->val[0]=x;
    List->size++;
}
void show_list(SeqList* List){
    if(List->size == 0){
        printf("顺序表为空.\n");
        return;
    }
    for(int i = 0; i < List->size; i++){
        printf("%d ", List->val[i]);
    }
    printf("\n");
}

void pop_back(SeqList* List){
    if(List->size==0){
        printf("顺序表为空,不能尾部删除数据\n");
        return;
    }
    List->size--;
}

void pop_front(SeqList* List){
    if(List->size==0){
        printf("顺序表为空,不能尾部删除数据\n");
        return;
    }
    int temp;
    for(int i = 0; i < List->size-1; i++){
        List->val[i]=List->val[i+1];
        // temp = List->val[i+1];
        // List->val[i]=temp;
    }
    List->size--;
}

void insert_at(SeqList* List, int pos, ElemType x){
    if(pos<0 || pos>List->size){ // 必须符合顺序表结构逻辑
        printf("插入位置不合法，不能插入数据.\n");
        return;
    }
    if(List->size >= List->capacity &&  !Inc(List)){
        printf("顺序表空间已满，%d不能尾部插入数据.\n", x);
        return;
    }
    // if(pos==0) 
    //     push_front(List, x);
    // else if(pos==List->size)
    //     push_back(List, x);
    // else{
    if(List->size>=List->capacity)
    {
        printf("顺序表已满不能再插入！\n");
        return;
    }
    for(int i = List->size; i >= pos; i--){
        List->val[i]=List->val[i-1];
    }
    List->val[pos] = x;
    List->size++;
    // }
}

int find(SeqList* List, ElemType x){
    for(int i = 0; i < List->size; i++){
        if(List->val[i] == x){
            return i;
        }
    }
    return -1;
}

int length(SeqList* List){
    return List->size;
}

void delete_pos(SeqList* List, int pos){
    if(pos<0 || pos>=List->size){
        printf("删除的位置不合法,不能删除数据\n");
        return;
    }
    for(int i = pos; i < (List->size)-1; ++i) 
        List->val[i] = List->val[i+1];

    List->size--;
    printf("已删除位置%d处的数据.\n", pos);
}

void delete_val(SeqList* List, ElemType x){
    int pos = find(List, x);
    if(pos == -1){
        printf("要删除的数据不存在.\n");
        return;
    }

    delete_pos(List, pos);
    printf("数据已删除.\n");
}

void sort(SeqList* List){
    for(int i = 0; i < List->size-1; i++){
        for(int j = 0; j < List->size-i-1; j++){
            if(List->val[j]>List->val[j+1]){
                ElemType temp = List->val[j];
                List->val[j] = List->val[j+1];
                List->val[j+1] = temp;
            }
        }
    }
}

void swap(ElemType* a, ElemType* b){
    ElemType temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(SeqList* List){
    if(List == NULL || List->val == NULL || List->size <=1)
        return;
    int low = 0, high = List->size-1;
    ElemType temp;
    while(low < high){
        // temp = List->val[low];
        // List->val[low] = List->val[high];
        // List->val[high] = temp;
        swap(&List->val[low++], &List->val[high--]);
        // low++;
        // high--;
    }

}

void clear(SeqList* List){
    List->size = 0;
    return;
}

void destroy(SeqList* List){
    free(List->val);
    List->val = nullptr;
    List->capacity = 0;
    List->size = 0;
    return;
}

void merge(SeqList* lt, SeqList* la, SeqList* lb){
    lt->capacity = la->size + lb->size;
    lt->val = (ElemType*)malloc(sizeof(ElemType)*lt->capacity);
    assert(lt->val != NULL);

    int ia = 0, ib = 0, ic = 0;
    while(ia<la->size && ib<lb->size){
        if(la->val[ia]>lb->val[ib]){
            lt->val[ic++] = lb->val[ib++];    
        }
        else{
            lt->val[ic++] = la->val[ia++];
        }
    }
    while(ib < lb->size){
        lt->val[ic++] = lb->val[ib++];
    }
    while(ia < la->size){
        lt->val[ic++] = la->val[ia++];
    }
    // lt->size = la->size + lb->size;
    lt->size = ic;
    return;
}