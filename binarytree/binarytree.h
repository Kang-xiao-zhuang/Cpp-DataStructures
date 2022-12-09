//
// Created by Administrator on 2022/12/9.
//
#include <iostream>

#ifndef C__DATASTRUCTURES_BINARYTREE_H
#define C__DATASTRUCTURES_BINARYTREE_H
#define MaxSize 100
typedef char ElemType;

#include <malloc.h>

using namespace std;

class binarytree {

public:
    //����Ԫ��
    ElemType data;
    //ָ������
    struct binarytree *lchild;
    //ָ���Һ���
    struct binarytree *rchild;
};

/**
 * ����������
 * @param b  binarytree
 * @param str  char
 */
void createBinaryTree(binarytree *&b, char *str) {
    binarytree *St[MaxSize], *p = nullptr;
    int top = -1, k, j = 0;
    char ch;
    //�����Ķ�������ʼʱΪ��
    b = nullptr;
    ch = str[j];
    //strδɨ����ʱѭ��
    while (ch != '\0') {
        switch (ch) {
            case '(':
                top++;
                St[top] = p;
                //Ϊ����
                k = 1;
                break;
            case ')':
                top--;
                break;
            case ',':
                //Ϊ�ҽ��
                k = 2;
                break;
            default:
                p = (binarytree *) malloc(sizeof(binarytree));
                p->data = ch;
                p->lchild = p->rchild = nullptr;
                if (b == nullptr) {
                    //pָ��������ĸ����
                    b = p;
                } else {
                    //�ѽ��������������
                    switch (k) {
                        case 1:
                            St[top]->lchild = p;
                            break;
                        case 2:
                            St[top]->rchild = p;
                            break;
                    }
                }
        }
        j++;
        ch = str[j];
    }
}

/**
 * �Թ�������������
 * @param b  binarytree
 */
void dispBinaryTree(binarytree *b) {
    if (b != nullptr) {
        cout << b->data;
        //   printf("%c", b->data);
        if (b->lchild != nullptr || b->rchild != nullptr) {
            //   printf("(");
            cout << "(";
            dispBinaryTree(b->lchild);
            if (b->rchild != nullptr) cout << ",";
            dispBinaryTree(b->rchild);
            cout << ")";
        }
    }
}

/**
 * �������b�Ľ�����
 * @param b  binarytree
 * @return int
 */
int nodes(binarytree *b) {
    int num1, num2;
    if (b == nullptr) {
        return 0;
        // bΪҶ�ӽڵ�
    } else if (b->lchild == nullptr && b->rchild == nullptr) {
        return 1;
    } else {
        num1 = nodes(b->lchild);
        num2 = nodes(b->rchild);
        return (num1 + num2 + 1);
    }
}

/**
 * �������b��Ҷ�ӽ�����
 * @param b  binarytree
 * @return int
 */
int leafNodes(binarytree *b) {
    int num1, num2;
    if (b == nullptr) {
        return 0;
        // bΪҶ�ӽڵ�
    } else if (b->lchild == nullptr && b->rchild == nullptr) {
        return 1;
    } else {
        num1 = leafNodes(b->lchild);
        num2 = leafNodes(b->rchild);
        return (num1 + num2);
    }
}

/**
 * �������b�����
 * @param b  binarytree
 * @return int
 */
int binaryTreeDepth(binarytree *b) {
    int lchilddep, rchilddep;
    if (b == nullptr) {
        return 0;
    } else {
        lchilddep = binaryTreeDepth(b->lchild);
        rchilddep = binaryTreeDepth(b->rchild);
        return lchilddep > rchilddep ? (lchilddep + 1) : (rchilddep + 1);
    }
}

/**
 * ��������ĵݹ��㷨
 * @param b binarytree
 */
void preOrder(binarytree *b) {
    if (b->data == NULL) {
        return;
    }
    // ��������
    // printf("%c ", b->data);
    cout << b->data<<" ";
    // ����������
    if (b->lchild != nullptr) {
        preOrder(b->lchild);
    }
    // ����������
    if (b->rchild != nullptr) {
        preOrder(b->rchild);
    }
}

/**
 * ��������ĵݹ��㷨
 * @param b binarytree
 */
void inOrder(binarytree *b) {
    if (b->data == NULL) {
        return;
    }
    // ����������
    if (b->lchild != nullptr) {
        inOrder(b->lchild);
    }
    // ��������
    //printf("%c ", b->data);
    cout << b->data<<" ";
    // ����������
    if (b->rchild != nullptr) {
        inOrder(b->rchild);
    }
}

/**
 * ��������ĵݹ��㷨
 * @param b binarytree
 */
void postOrder(binarytree *b) {
    if (b->data == NULL) {
        return;
    }
    // ����������
    if (b->lchild != nullptr) {
        postOrder(b->lchild);
    }
    // ����������
    if (b->rchild != nullptr) {
        postOrder(b->rchild);
    }
    // ��������
    //printf("%c ", b->data);
    cout << b->data<<" ";
}

/**
 * ��α����㷨
 * @param b binarytree
 */
void travLevel(binarytree *b) {
    //����ѭ������
    binarytree *Qu[MaxSize];
    //������׺Ͷ�βָ��
    int front, rear;
    //�ö���Ϊ�ն���
    front = rear = 0;
    if (b != nullptr)
        printf("%c ", b->data);
    //���ָ��������
    rear++;
    Qu[rear] = b;
    //���в�Ϊ��
    while (rear != front) {
        front = (front + 1) % MaxSize;
        //��ͷ������
        b = Qu[front];
        //�������,�������
        if (b->lchild != nullptr) {
            // printf("%c ", b->lchild->data);
            cout << b->lchild->data << " ";
            rear = (rear + 1) % MaxSize;
            Qu[rear] = b->lchild;
        }
        //����Һ���,�������
        if (b->rchild != nullptr) {
            //printf("%c ", b->rchild->data);
            cout << b->rchild->data << " ";
            rear = (rear + 1) % MaxSize;
            Qu[rear] = b->rchild;
        }
    }
    cout << endl;
}

/**
 * ·��ɨ��
 * @param b binarytree
 * @param path  ElemType
 * @param pathlen  int
 */
void allPath(binarytree *b, ElemType path[], int pathlen) {
    int i;
    if (b != nullptr) {
        //*bΪҶ�ӽ��
        if (b->lchild == nullptr && b->rchild == nullptr) {
            printf("%c�������·��: %c ", b->data, b->data);
            for (i = pathlen - 1; i >= 0; i--) {
                printf("%c ", path[i]);
            }
            printf("\n");
        } else {
            //����ǰ������·����
            path[pathlen] = b->data;
            //·��������1
            pathlen++;
            //�ݹ�ɨ��������
            allPath(b->lchild, path, pathlen);
            //�ݹ�ɨ��������
            allPath(b->rchild, path, pathlen);
            //�ָ�����
            pathlen--;
        }
    }
}

#endif //C__DATASTRUCTURES_BINARYTREE_H
