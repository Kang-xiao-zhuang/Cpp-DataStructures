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
    cout << "创建一棵BST树:" << endl;
    bt = creatBST(a, n);
    cout << endl;
    cout << endl;
    cout << "BST: ";
    dispBST(bt);
    cout << endl << endl;

    cout << "查找" << k << "关键字: ";
    SearchBST(bt, k);

    cout << endl << endl << " 删除操作：" << endl;
    cout << "   原BST: ";
    dispBST(bt);
    cout << endl;

    cout << "   删除结点4: ";
    DeleteBST(bt, 4);
    dispBST(bt);
    cout << endl;

    cout << "   删除结点5: ";
    DeleteBST(bt, 5);

    dispBST(bt);
    cout << endl << endl;

    cout << " 是否是二叉排序树:" << endl;
    if (isBinaryTree(bt)) {
        cout << "是二叉排序树" << endl;
    } else {
        cout << "不是二叉排序树" << endl;
    }
}