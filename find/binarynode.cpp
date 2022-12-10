//
// Created by Administrator on 2022/12/10.
//

#include "binarynode.h"

int main() {
    binarynode *bt;
    KeyType k = 6;
    int a[] = {4, 9, 0, 1, 8, 6, 3, 5, 2, 7}, n = 10;
    /*
    4
   / \
  0   9
   \ /
   1 8
   \  /
   3 6
  /  /\
  2  5 7
     */
    cout << "����һ��BST��:" << endl;
    bt = creatBST(a, n);
    cout << endl;
    cout << endl;
    cout << "BST: ";
    dispBST(bt);
    cout << endl << endl;

    cout << "����" << k << "�ؼ���: ";
    SearchBST(bt, k);

    cout << endl << endl << " ɾ��������" << endl;
    cout << "   ԭBST: ";
    dispBST(bt);
    cout << endl;

    cout << "   ɾ�����4: ";
    DeleteBST(bt, 4);
    dispBST(bt);
    cout << endl;

    cout << "   ɾ�����5: ";
    DeleteBST(bt, 5);

    dispBST(bt);
    cout << endl << endl;

    cout << " �Ƿ��Ƕ���������:" << endl;
    if (isBinaryTree(bt)) {
        cout << "�Ƕ���������" << endl;
    } else {
        cout << "���Ƕ���������" << endl;
    }
}