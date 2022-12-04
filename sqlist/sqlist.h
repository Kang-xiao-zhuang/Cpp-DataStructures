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
