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

    cout << "-----�����ĺϲ�-----" << endl;
    cout << "-----˳���A-----" << endl;
    dispList(A);
    cout << endl;
    cout << "-----˳���B-----" << endl;
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
    cout << "-----˳���C-----" << endl;
    dispList(C);
    cout<<endl;
    cout << "-----ɾ��Ԫ������Ϊ6-----" << endl;
    listDelete(C, 6, e);
    cout << "-----˳���C-----" << endl;
    dispList(C);
    cout << "----------------------˳������-------------------------" << endl;

    sqlist *L;
    ElemType elemType;
    cout << "(1) ��ʼ��˳���" << endl;
    initList(L);

    cout << "(2) ���β���a,b,c,d,eԪ��" << endl;
    listInsert(L, 1, 'a');
    listInsert(L, 2, 'b');
    listInsert(L, 3, 'c');
    listInsert(L, 4, 'd');
    listInsert(L, 5, 'e');

    cout << "(3)L����=" << listLen(L) << endl;
    cout << "(4)˳���λ:" << (isEmpty(L) ? "��" : "�ǿ�") << endl;

    getElem(L, 3, elemType);
    cout << "(5)˳���L�ĵ�3��Ԫ��=" << elemType << endl;

    cout << "(6)Ԫ��b��λ��=" << locateElem(L, 'b') << endl;

    cout << "(7)�ڵ�4��Ԫ���ϲ���fԪ��" << endl;
    listInsert(L, 4, 'f');
    cout << "���˳���L:" << endl;
    dispList(L);

    cout << "(8)ɾ��L�ĵ�3��Ԫ��" << endl;
    listDelete(L, 3, elemType);

    cout << "(9)���˳���L:" << endl;
    dispList(L);

    cout << "(10) �ͷ�˳���" << endl;
    desoryList(L);
}
