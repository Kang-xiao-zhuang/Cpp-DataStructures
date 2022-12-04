# 单链表

定义一个包含学生成绩信息（学号，姓名，成绩）的链表，阅读代码，完成以下功能。
1、完善插入、删除函数，并完成在主函数中的调用。
2、求链表的长度。
3、完成求最高成绩、最低成绩、平均成绩的函数操作，并完成在主函数中的调用。
4、将链表进行逆置并输出。

运行结果如图所示：

![在这里插入图片描述](https://img-blog.csdnimg.cn/f3d98b654c514c75b119041c5095f064.png)

![在这里插入图片描述](https://img-blog.csdnimg.cn/d61b36075b98471ea88cfc005570c227.png)

**完整代码**

**linklist.h**

```cpp
//
// Created by Administrator on 2022/12/4.
//
#include <cstdio>
#include <cstdlib>

#ifndef C__DATASTRUCTURES_LINKLIST_H
#define C__DATASTRUCTURES_LINKLIST_H
#define LEN sizeof(linklist)

#include <malloc.h>
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class linklist {
public:
    //学号
    long num;
    //成绩
    float score;
    //指针域
    linklist *next;
};

// 链表的长度
int n;

/**
 * 初始化链表
 * @return  linklist
 */
linklist *create(void) {
    // 创建两个指针
    linklist *p1, *p2;
    linklist *l;
    n = 0;
    //头节点 申请开辟内存空间
    l = p1 = (linklist *) malloc(LEN);
    p2 = (linklist *) malloc(LEN);
    //输入学号、成绩
    scanf("%ld,%f", &p2->num, &p2->score);
    //学号为0时，录入结束
    while (p2->num != 0) {
        // 长度加1
        n++;
        // 头节点指向新的新节点
        p1->next = p2;
        p1 = p2;
        p2 = (linklist *) malloc(LEN);
        scanf("%ld,%f", &p2->num, &p2->score);
    }
    p1->next = nullptr;
    return l;
}

/**
 * 打印链表
 * @param l  linklist
 */
void sc(linklist *l) {
    linklist *p;
    cout << endl;
    cout << "成绩是" << endl;
    //  printf("\n成绩是:\n", n);
    p = l->next;
    while (p != nullptr) {
        printf("%ld，%5.1f\n", p->num, p->score);
        // 指针向后移动
        p = p->next;
    }
}

/**
 * 删除链表的节点
 * @param l linklist
 * @param num long
 * @return linklist
 */
linklist *del(linklist *l, long num) {
    // 定义头节点
    linklist *header = l;
    // 定义节点
    linklist *p = l->next;
    // 删除的节点
    linklist *delNode;
    while (p != nullptr && p->num != num) {
        p = p->next;
        header = header->next;
    }
    if (p == nullptr) {
        return nullptr;
    }
    header->next = p->next;
    delNode = p;
    delete delNode;
    n--;
    return l;
}

/**
 * 向链表插入节点(尾插法)
 * @param l linklist
 * @param stud linklist
 * @return linklist
 */
linklist *insert(linklist *l, linklist *stud) {
    linklist *head = l;
    linklist *p = stud;
    p->next = head->next;
    head->next = p;
    n++;
    return l;
}

/**
 * 获取最大值，最小值，平均值
 * @param l linklist
 * @return int
 */
int max_min_ave(linklist *l) {
    linklist *p;
    p = l->next;
    if (p == nullptr) {
        printf("链表为空！");
    }
    int max = INT_MIN;
    while (p != nullptr) {
        if (p->score > max) {
            max = p->score;
        }
        p = p->next;
    }
    printf("最高成绩为%d分\n", max);
    p = l->next;
    int min = INT_MAX;
    while (p != nullptr) {
        if (p->score < min) {
            min = p->score;
        }
        p = p->next;
    }
    printf("最低成绩为%d分\n", min);
    double sum = 0;
    p = l->next;
    while (p != nullptr) {
        sum += p->score;
        p = p->next;
    }
    printf("平均成绩为：%.2f分\n", (sum / n));
    return 0;
}

/**
 * 逆置链表
 * @param L linklist
 */
void reverList(linklist *l) {
    if (l->next == nullptr) {
        return;
    }
    linklist *pre = nullptr;
    linklist *cur = l->next;
    linklist *next;
    while (cur) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    l->next = pre;
}

#endif //C__DATASTRUCTURES_LINKLIST_H
```

**linklist.cpp**

```cpp
//
// Created by Administrator on 2022/12/4.
//
#include "linklist.h"

int main() {
    linklist *L, *stu;

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
    L = create();
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
        stu = (linklist *) malloc(LEN);
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
    reverList(L);
    sc(L);
}
```
**运行截图**
![在这里插入图片描述](https://img-blog.csdnimg.cn/1bb15e3ada5f4d91a07645c91adf9ab8.png)