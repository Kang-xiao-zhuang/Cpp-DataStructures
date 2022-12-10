////
//// Created by Administrator on 2022/12/9.
////
//
//#include "binarytree.h"
//
//int main() {
//    binarytree *b;
//    ElemType path[MaxSize];
//    createBinaryTree(b, "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
//    cout << " 二叉树b: ";
//    dispBinaryTree(b);
//    cout << endl << endl;
//
//    //在此处调用相关函数，输出二叉树b的结点个数;
//    cout << "二叉树b的结点个数：" << nodes(b) << endl;
//    //在此处调用相关函数，输出二叉树b的叶子结点个数;
//    cout << "二叉树b的叶子结点个数：" << leafNodes(b) << endl;
//    //在此处调用相关函数，输出二叉树b的深度;
//    cout << "二叉树b的深度：" << binaryTreeDepth(b) << endl;
//
//    //参照运行结果图，在此处调用先序遍历函数;
//    cout << "先序遍历序列: ";
//    preOrder(b);
//    cout << endl;
//    //参照运行结果图，在此处调用中序遍历函数;
//    cout << "中序遍历序列: ";
//    inOrder(b);
//    cout << endl;
//    //参照运行结果图，在此处调用后序遍历函数;
//    cout << "后序遍历序列: ";
//    postOrder(b);
//    cout << endl;
//    cout << "层次遍历序列: ";
//    travLevel(b);
//    cout << endl;
//
//    cout << "叶子结点路径:" << endl;
//    allPath(b, path, 0);
//    cout << endl;
//}