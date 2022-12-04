#include <stdio.h>
#include <stdlib.h>

#define NULL 0
#define LEN sizeof(LinkList)


//链表的定义：
typedef struct LNode {
    long num;          //学号
    float score;      //成绩
    struct LNode *next;   //指针域
} LNode, LinkList;

// 链表的长度
int n;

/**
 *
 * @return  LinkList
 */
LinkList *creat(void) {
    // 创建两个指针
    LinkList *p1, *p2;
    LinkList *L;
    n = 0;
    //头节点 申请开辟内存空间
    L = p1 = (LinkList *) malloc(LEN);
    p2 = (LinkList *) malloc(LEN);
    //输入学号、成绩
    scanf("%ld,%f", &p2->num, &p2->score);
    //学号为0时，录入结束
    while (p2->num != 0) {
        // 长度加1
        n++;
        // 头节点指向新的新节点
        p1->next = p2;
        p1 = p2;
        p2 = (LinkList *) malloc(LEN);
        scanf("%ld,%f", &p2->num, &p2->score);
    }
    p1->next = NULL;
    return (L);
}

/**
 * 输出所有学生的学号和成绩
 * @param L  LinkList
 */
void sc(LinkList *L) {
    LinkList *p;
    printf("\n成绩是:\n", n);
    p = L->next;
    while (p != NULL) {
        printf("%ld，%5.1f\n", p->num, p->score);
        // 指针向后移动
        p = p->next;
    }
}

/**
 * 删除指定学号的结点
 * @param L  LinkList
 * @param num  学号
 * @return  LinkList
 */
LinkList *del(LinkList *L, long num) {
//在此处完成删除函数操作
    // 定义头节点
    LNode *header = L;
    // 定义节点
    LNode *p = L->next;
    // 删除的节点
    LNode *delNode;
    while (p != NULL && p->num != num) {
        p = p->next;
        header = header->next;
    }
    if (p == NULL) {
        return NULL;
    }
    header->next = p->next;
    delNode = p;
    delete delNode;
    n--;
    return L;
}

/**
 * 插入stud结点，可采用前插法
 * @param L  LinkList
 * @param stud  LinkList
 * @return  LinkList
 */
LinkList *insert(LinkList *L, LinkList *stud) {
//在此处完成插入函数操作
    LNode *head = L;
    LNode *p = stud;
    p->next = head->next;
    head->next = p;
    n++;
    return L;
}

/**
 * 在此处完成求最高成绩、最低成绩、平均成绩的函数操作
 * @param L  LinkList
 * @return  int
 */
int max_min_ave(LinkList *L) {
    LinkList *p;
    p = L->next;
    if (p == NULL) {
        printf("链表为空！");
    }
    int max = INT_MIN;
    while (p != NULL) {
        if (p->score > max) {
            max = p->score;
        }
        p = p->next;
    }
    printf("最高成绩为%d分\n", max);
    p = L->next;
    int min = INT_MAX;
    while (p != NULL) {
        if (p->score < min) {
            min = p->score;
        }
        p = p->next;
    }
    printf("最低成绩为%d分\n", min);
    double sum = 0;
    p = L->next;
    while (p != NULL) {
        sum += p->score;
        p = p->next;
    }
    printf("平均成绩为：%.2f分\n", (sum / n));
    return 0;
}

/**
 * 逆置函数
 * @param L  LinkList
 */
void NiZhiList_L(LinkList *L) {
    if (L->next == nullptr) {
        return;
    }
    LinkList *pre = NULL;
    LinkList *cur = L->next;
    LinkList *next;
    while (cur) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    L->next = pre;
}

int main() {
    LinkList *L, *stu;

    long del_num;
    /* 200,100
        20,30
        */
    /**
     *  1,90
        2,60
        3,80
        4,85
        0,0
     */
    printf("输入数据:\n");
    L = creat();
    sc(L);
    while (true) {
        printf("\n输入需要删除的学号:");
        scanf("%ld", &del_num);
        if (del_num == 0) {
            break;
        }
        del(L, del_num);
        //1.在此处调用删除函数，完成连续删除操作，并调用sc(head)输出链表
        sc(L);
    }


    //2.在此处调用插入函数，完成连续插入操作，并调用sc(head)输出链表
    while (true) {
        printf("\n输入需要插入的学号和成绩");
        stu = (LinkList *) malloc(LEN);
        scanf("%ld,%f", &stu->num, &stu->score);
        if (stu->num == 0 && stu->score == 0) {
            break;
        }
        insert(L, stu);
        sc(L);
    }
    //3.在此处调用求最高成绩、最低成绩、平均成绩的函数
    printf("链表长度为：%d\n", n);
    max_min_ave(L);
    //4.在此处调用逆置函数，并输出逆序后的链表
    printf("逆转输出结果：\n");
    NiZhiList_L(L);
    sc(L);
}