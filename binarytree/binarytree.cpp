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
//    cout << " ������b: ";
//    dispBinaryTree(b);
//    cout << endl << endl;
//
//    //�ڴ˴�������غ��������������b�Ľ�����;
//    cout << "������b�Ľ�������" << nodes(b) << endl;
//    //�ڴ˴�������غ��������������b��Ҷ�ӽ�����;
//    cout << "������b��Ҷ�ӽ�������" << leafNodes(b) << endl;
//    //�ڴ˴�������غ��������������b�����;
//    cout << "������b����ȣ�" << binaryTreeDepth(b) << endl;
//
//    //�������н��ͼ���ڴ˴����������������;
//    cout << "�����������: ";
//    preOrder(b);
//    cout << endl;
//    //�������н��ͼ���ڴ˴����������������;
//    cout << "�����������: ";
//    inOrder(b);
//    cout << endl;
//    //�������н��ͼ���ڴ˴����ú����������;
//    cout << "�����������: ";
//    postOrder(b);
//    cout << endl;
//    cout << "��α�������: ";
//    travLevel(b);
//    cout << endl;
//
//    cout << "Ҷ�ӽ��·��:" << endl;
//    allPath(b, path, 0);
//    cout << endl;
//}