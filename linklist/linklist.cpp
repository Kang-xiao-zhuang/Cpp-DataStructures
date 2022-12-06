////
//// Created by Administrator on 2022/12/4.
////
//#include "linklist.h"
//
//int main() {
//    linklist *L, *stu;
//
//    long del_num;
//    /* 200,100
//        20,30
//        */
//    /**
//     *  1,90
//        2,60
//        3,80
//        4,85
//        0,0
//     */
//    printf("输入数据:\n");
//    L = create();
//    sc(L);
//    while (true) {
//        printf("\n输入需要删除的学号:");
//        scanf("%ld", &del_num);
//        if (del_num == 0) {
//            break;
//        }
//        del(L, del_num);
//        //1.在此处调用删除函数，完成连续删除操作，并调用sc(head)输出链表
//        sc(L);
//    }
//
//    //2.在此处调用插入函数，完成连续插入操作，并调用sc(head)输出链表
//    while (true) {
//        printf("\n输入需要插入的学号和成绩");
//        stu = (linklist *) malloc(LEN);
//        scanf("%ld,%f", &stu->num, &stu->score);
//        if (stu->num == 0 && stu->score == 0) {
//            break;
//        }
//        insert(L, stu);
//        sc(L);
//    }
//    //3.在此处调用求最高成绩、最低成绩、平均成绩的函数
//    printf("链表长度为：%d\n", n);
//    max_min_ave(L);
//    //4.在此处调用逆置函数，并输出逆序后的链表
//    printf("逆转输出结果：\n");
//    reverList(L);
//    sc(L);
//}
