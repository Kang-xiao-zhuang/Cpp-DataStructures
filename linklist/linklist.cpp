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
//    printf("��������:\n");
//    L = create();
//    sc(L);
//    while (true) {
//        printf("\n������Ҫɾ����ѧ��:");
//        scanf("%ld", &del_num);
//        if (del_num == 0) {
//            break;
//        }
//        del(L, del_num);
//        //1.�ڴ˴�����ɾ���������������ɾ��������������sc(head)�������
//        sc(L);
//    }
//
//    //2.�ڴ˴����ò��뺯��������������������������sc(head)�������
//    while (true) {
//        printf("\n������Ҫ�����ѧ�źͳɼ�");
//        stu = (linklist *) malloc(LEN);
//        scanf("%ld,%f", &stu->num, &stu->score);
//        if (stu->num == 0 && stu->score == 0) {
//            break;
//        }
//        insert(L, stu);
//        sc(L);
//    }
//    //3.�ڴ˴���������߳ɼ�����ͳɼ���ƽ���ɼ��ĺ���
//    printf("������Ϊ��%d\n", n);
//    max_min_ave(L);
//    //4.�ڴ˴��������ú��������������������
//    printf("��ת��������\n");
//    reverList(L);
//    sc(L);
//}
