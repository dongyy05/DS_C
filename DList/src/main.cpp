#include"../include/Dlist.h"

int main(){
    List mylist;
    InitDList(&mylist);

    PNode p = NULL;
    int select = 1;
    ElementType val;
    while(select){
        printf("*******************************************\n");
        printf("* [1] push_back     [2] push_front        *\n");
        printf("* [3] show_list     [4] pop_back          *\n");
        printf("* [5] pop_front     [6] insert_val        *\n");
        printf("* [7] find_val      [8] length            *\n");
        printf("* [9] delete_val    [10] sort             *\n");
        printf("* [11] reverse      [12] clear            *\n");
        printf("* [13*] destroy     [0] exit              *\n");
        printf("*******************************************\n");
        printf("请选择:>");
        scanf("%d", &select);

        switch(select){
            case 1:
                printf("请输入要插入的数据(-1结束):>");
                while(scanf("%d", &val)&&val!=-1)
                    push_back(&mylist,val);
                break;
            case 2:
               printf("请输入要插入的数据(-1结束):>");
                while(scanf("%d", &val)&&val!=-1)
                    push_front(&mylist,val);
                break;
            case 3:
                show_list(&mylist);
                break;
            case 4:
                pop_back(&mylist);
                printf("已删除尾部结点.\n");
                break;
            case 5:
                pop_front(&mylist);
                printf("已删除头部结点.\n");
                break;
            case 6:
                printf("请输入要插入的数据:>");
                scanf("%d", &val);
                insert_val(&mylist, val);
                break;
            case 7:
                printf("请输入要查找的数据:>");
                scanf("%d", &val);
                // p = find_val(&mylist, val);

                if(p==NULL){
                    printf("要查找的数据在链表中不存在.\n");
                }
                break;
            case 8:
                printf("单链表的长度为:>%d \n", length(&mylist));
                break;
            case 9:
                printf("请输入要删除的值:>");
                scanf("%d", &val);
                // delete_val(&mylist, val);
                break;
            case 10:
                // sort(&mylist);
                printf("排序完成.\n");
                break;
            case 11:
                // reverse(&mylist);
                printf("反转完成.\n");
                break;
            case 12:
                // clear(&mylist);
                printf("已清除链表，但为释放内存.\n");
                break;
            case 13:
                // destroy(&mylist);
                break;
            case 0:
                printf("退出程序!\n");
                break;
            default:
                printf("选择错误，请重新选择!\n");
                break;
        }
    }
    // destroy(&mylist);
    // printf("内存已释放.\n");
}