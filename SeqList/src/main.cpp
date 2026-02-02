#include "../include/SeqList.h"

int main(){
    SeqList mylist, youlist, list;
    InitSeqList(&mylist);
    InitSeqList(&youlist);
    
    push_back(&mylist, 1);
    push_back(&mylist, 3);
    push_back(&mylist, 8);
    push_back(&mylist, 14);
    push_back(&mylist, 9);
    
    push_back(&youlist, 2);
    push_back(&youlist, 4);
    push_back(&youlist, 6);
    push_back(&youlist, 11);
    push_back(&youlist, 10);

    merge(&list, &mylist, &youlist);
    printf("merged list: ");
    sort(&list);
    show_list(&list);
    return 0;
}

// int main()
// {
//     SeqList myList;
//     InitSeqList(&myList);
//     ElemType items;
//     int pos;
//     int select;
//     while (true)
//     {
//         printf("********************************************\n");
//         printf("* [1]  push_back   [2] push_front          *\n");
//         printf("* [3]  show_list   [4] pop_back            *\n"); 
//         printf("* [5]  pop_front   [6] insert_at           *\n");
//         printf("* [7]  find        [8] length              *\n");
//         printf("* [9]  delete_pos  [10] delete_val         *\n");
//         printf("* [11] sort        [12] reverse            *\n");
//         printf("* [13] clear       [*14*] destroy          *\n");
//         printf("* [0]  quit_system                         *\n");
//         printf("********************************************\n");
//         printf("请输入操作编号：");
//         scanf("%d", &select);

//         if(select == 0) break;

//         switch (select)
//         {
//         case 1:
//             printf("请输入要插入的数据(-1结束):>");
//             while(scanf("%d", &items), items!=-1){
//             push_back(&myList, items);
//             }

//             break;
//         case 2:
//             printf("请输入要插入的数据(-1结束):>");
//             while(scanf("%d", &items), items!=-1){
//                 push_front(&myList, items);
//             }
//             break;
//         case 3:
//             show_list(&myList);
//             break;
//         case 4:
//             pop_back(&myList);
//             break;
//         case 5:
//             pop_front(&myList);
//             break;
//         case 6:
//             printf("请输入要插入的位置及数据:>");
//             scanf("%d %d", &pos, &items);
//             insert_at(&myList, pos, items);
//             break; 
//         case 7:
//             printf("请输入要查找的值:>");
//             scanf("%d", &items);
//             pos = find(&myList, items);
//             if(pos == -1) printf("未找到%d.\n", items);
//             else printf("%d位于顺序表的第 %d 个位置.\n", items, pos+1);
//             break;
//         case 8:
//             printf("顺序表的长度为: %d\n", length(&myList));
//             break;
//         case 9:
//             printf("请输入要删除的位置:>");
//             scanf("%d", &pos);
//             delete_pos(&myList, pos);
//             break;
//         case 10:
//             printf("请输入要删除的值:>");
//             scanf("%d", &items);
//             delete_val(&myList, items);
//             break;
//         case 11:
//             sort(&myList);
//             printf("顺序表已排序.\n");
//             break;
//         case 12:
//             reverse(&myList);
//            int main()
// {
//     SeqList myList;
//     InitSeqList(&myList);
//     ElemType items;
//     int pos;
//     int select;
//     while (true)
//     {
//         printf("********************************************\n");
//         printf("* [1]  push_back   [2] push_front          *\n");
//         printf("* [3]  show_list   [4] pop_back            *\n"); 
//         printf("* [5]  pop_front   [6] insert_at           *\n");
//         printf("* [7]  find        [8] length              *\n");
//         printf("* [9]  delete_pos  [10] delete_val         *\n");
//         printf("* [11] sort        [12] reverse            *\n");
//         printf("* [13] clear       [*14*] destroy          *\n");
//         printf("* [0]  quit_system                         *\n");
//         printf("********************************************\n");
//         printf("请输入操作编号：");
//         scanf("%d", &select);

//         if(select == 0) break;

//         switch (select)
//         {
//         case 1:
//             printf("请输入要插入的数据(-1结束):>");
//             while(scanf("%d", &items), items!=-1){
//             push_back(&myList, items);
//             }

//             break;
//         case 2:
//             printf("请输入要插入的数据(-1结束):>");
//             while(scanf("%d", &items), items!=-1){
//                 push_front(&myList, items);
//             }
//             break;
//         case 3:
//             show_list(&myList);
//             break;
//         case 4:
//             pop_back(&myList);
//             break;
//         case 5:
//             pop_front(&myList);
//             break;
//         case 6:
//             printf("请输入要插入的位置及数据:>");
//             scanf("%d %d", &pos, &items);
//             insert_at(&myList, pos, items);
//             break; 
//         case 7:
//             printf("请输入要查找的值:>");
//             scanf("%d", &items);
//             pos = find(&myList, items);
//             if(pos == -1) printf("未找到%d.\n", items);
//             else printf("%d位于顺序表的第 %d 个位置.\n", items, pos+1);
//             break;
//         case 8:
//             printf("顺序表的长度为: %d\n", length(&myList));
//             break;
//         case 9:
//             printf("请输入要删除的位置:>");
//             scanf("%d", &pos);
//             delete_pos(&myList, pos);
//             break;
//         case 10:
//             printf("请输入要删除的值:>");
//             scanf("%d", &items);
//             delete_val(&myList, items);
//             break;
//         case 11:
//             sort(&myList);
//             printf("顺序表已排序.\n");
//             break;
//         case 12:
//             reverse(&myList);
//             printf("顺序表已反转.\n");
//             break;
//         case 13:
//             clear(&myList);
//             printf("顺序表已清空.\n");
//             break;
//         // case 14:
//         //     // destroy(&myList);
//         //     printf("顺序表已销毁.\n");
//         //     break;
//         default:
//             printf("无效输入，请重新选择操作编号！\n");
//             break;
//         }   
//     }
//     printf("顺序表已销毁.\n已退出系统，感谢使用！\n");
//     destroy(&myList);

//     return 0;
// } printf("顺序表已反转.\n");
//             break;
//         case 13:
//             clear(&myList);
//             printf("顺序表已清空.\n");
//             break;
//         // case 14:
//         //     // destroy(&myList);
//         //     printf("顺序表已销毁.\n");
//         //     break;
//         default:
//             printf("无效输入，请重新选择操作编号！\n");
//             break;
//         }   
//     }
//     printf("顺序表已销毁.\n已退出系统，感谢使用！\n");
//     destroy(&myList);

//     return 0;
// }