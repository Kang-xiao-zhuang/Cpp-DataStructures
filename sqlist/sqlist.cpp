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
