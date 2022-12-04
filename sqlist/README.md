# 顺序表

**sqlist.h**

```cpp
//
// Created by KangXiaoZhuang on 2022/12/4.
//

#ifndef C__DATASTRUCTURES_SQLIST_H
#define C__DATASTRUCTURES_SQLIST_H

#include <malloc.h>
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

#define MaxSize 50
typedef int ElemType;

class sqlist {

public:
    ElemType data[MaxSize];
    int length;
};

/**
 * 初始化顺序表
 * @param l sqlist
 */
void initList(sqlist *&l) {
    l = static_cast<sqlist *>(malloc(sizeof(sqlist)));
    l->length = 0;
}

/**
 * 销毁顺序表
 * @param l sqlist
 */
void desoryList(sqlist *l) {
    free(l);
}

/**
 * 判断是否为空
 * @param l sqlist
 * @return bool
 */
bool isEmpty(sqlist *l) {
    return l->length == 0;
}

/**
 * 顺序表长度
 * @param l  sqlist
 * @return 长度
 */
int listLen(sqlist *l) {
    return l->length;
}

/**
 * 打印链表
 * @param l sqlist
 */
void dispList(sqlist *l) {
    if (isEmpty(l)) {
        return;
    }
    for (int i = 0; i < l->length; ++i) {
        cout << l->data[i] << " ";
    }
    cout << endl;
}

/**
 * 获取顺序表里的元素
 * @param l sqlist
 * @param i 索引
 * @param e 元素
 * @return 是否获取到
 */
bool getElem(sqlist *l, int i, ElemType &e) {
    if (i < 1 || i > l->length) {
        return false;
    }
    e = l->data[i - 1];
    return true;
}

/**
 * 定位元素位置
 * @param l  sqlist
 * @param e 元素
 * @return 是否找到
 */
int locateElem(sqlist *l, ElemType e) {
    int i = 0;
    while (i < l->length && l->data[i] != e) {
        i++;
    }
    if (i >= l->length) {
        return 0;
    } else {
        return i + 1;
    }
}

/**
 * 元素插入
 * @param l sqlist
 * @param i 索引
 * @param e 元素
 * @return 是否插入成功
 */
bool listInsert(sqlist *l, int i, ElemType e) {
    int j;
    if (i < 1 || i > l->length + 1) {
        return false;
    }
    //将顺序表位序转化为elem下标
    i--;
    //将data[i]及后面元素后移一个位置
    for (j = l->length; j > i; j--) {
        l->data[j] = l->data[j - 1];
    }
    l->data[i] = e;
    //顺序表长度增1
    l->length++;
    return true;
}

/**
 * 顺序表删除元素
 * @param l sqlist
 * @param i 索引
 * @param e 元素
 * @return 是否删除成功
 */
bool listDelete(sqlist *l, int i, ElemType &e) {
    int j;
    if (i < 1 || i > l->length) {
        return false;
    }
    //将顺序表位序转化为elem下标
    i--;
    e = l->data[i];
    for (j = i; j < l->length - 1; j++) {
        l->data[j] = l->data[j + 1];
    }
    l->length--;
    return true;
}

#endif //C__DATASTRUCTURES_SQLIST_H
```

**sqlist.cpp**

```cpp
#include "sqlist.h"
#include <stdio.h>

using namespace std;
int main() {
    sqlist *A;
    sqlist *B;
    sqlist *C;

    initList(A);
    initList(B);
    initList(C);

    listInsert(A, 1, 3);
    listInsert(A, 2, 5);
    listInsert(A, 3, 8);
    listInsert(A, 4, 11);

    listInsert(B, 1, 2);
    listInsert(B, 2, 6);
    listInsert(B, 3, 7);
    listInsert(B, 4, 9);
    listInsert(B, 5, 13);
    listInsert(B, 6, 15);
    listInsert(B, 7, 20);

    cout << "-----有序表的合并-----" << endl;
    cout << "-----顺序表A-----" << endl;
    dispList(A);
    cout << endl;
    cout << "-----顺序表B-----" << endl;
    dispList(B);
    cout << endl;

    int e, f, m, n, i = 1, j = 1, k = 1;

    m = listLen(A);
    n = listLen(B);

    while (i <= m && j <= n) {
        getElem(A, i, e);
        getElem(B, j, f);
        if (e <= f) {
            listInsert(C, k++, e);
            i++;
        } else {
            listInsert(C, k++, f);
            j++;
        }
    }

    while (i <= m) {
        getElem(A, i, e);
        listInsert(C, k++, e);
        i++;
    }

    while (j <= n) {
        getElem(B, j, f);
        listInsert(C, k++, f);
        j++;
    }
    cout << "-----顺序表C-----" << endl;
    dispList(C);
    cout<<endl;
    cout << "-----删除元素索引为6-----" << endl;
    listDelete(C, 6, e);
    cout << "-----顺序表C-----" << endl;
    dispList(C);
    cout << "----------------------顺序表测试-------------------------" << endl;

    sqlist *L;
    ElemType elemType;
    cout << "(1) 初始化顺序表" << endl;
    initList(L);

    cout << "(2) 依次插入a,b,c,d,e元素" << endl;
    listInsert(L, 1, 'a');
    listInsert(L, 2, 'b');
    listInsert(L, 3, 'c');
    listInsert(L, 4, 'd');
    listInsert(L, 5, 'e');

    cout << "(3)L长度=" << listLen(L) << endl;
    cout << "(4)顺序表位:" << (isEmpty(L) ? "空" : "非空") << endl;

    getElem(L, 3, elemType);
    cout << "(5)顺序表L的第3个元素=" << elemType << endl;

    cout << "(6)元素b的位置=" << locateElem(L, 'b') << endl;

    cout << "(7)在第4个元素上插入f元素" << endl;
    listInsert(L, 4, 'f');
    cout << "输出顺序表L:" << endl;
    dispList(L);

    cout << "(8)删除L的第3个元素" << endl;
    listDelete(L, 3, elemType);

    cout << "(9)输出顺序表L:" << endl;
    dispList(L);

    cout << "(10) 释放顺序表" << endl;
    desoryList(L);
}
```

**运行截图**
![在这里插入图片描述](https://img-blog.csdnimg.cn/0f964ea4b77a4ac0a4fb2121fb560965.png)