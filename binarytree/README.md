### 1.以下图的二叉树为例，设计程序完成对二叉树的基本操作
![在这里插入图片描述](https://img-blog.csdnimg.cn/31a5a56611a945f69eae7eac2fbea7aa.png)
运行结果如图所示：
![在这里插入图片描述](https://img-blog.csdnimg.cn/067d6d11f6d0458583bedb0676205048.png)

### 2.自行设计一个算法，以二叉树为存储结构，统计二叉树的叶子结点个数，并将叶子节点依次输出

**binarytee.h**

```cpp
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
    //数据元素
    ElemType data;
    //指向左孩子
    struct binarytree *lchild;
    //指向右孩子
    struct binarytree *rchild;
};

/**
 * 创建二叉树
 * @param b  binarytree
 * @param str  char
 */
void createBinaryTree(binarytree *&b, char *str) {
    binarytree *St[MaxSize], *p = nullptr;
    int top = -1, k, j = 0;
    char ch;
    //建立的二叉树初始时为空
    b = nullptr;
    ch = str[j];
    //str未扫描完时循环
    while (ch != '\0') {
        switch (ch) {
            case '(':
                top++;
                St[top] = p;
                //为左结点
                k = 1;
                break;
            case ')':
                top--;
                break;
            case ',':
                //为右结点
                k = 2;
                break;
            default:
                p = (binarytree *) malloc(sizeof(binarytree));
                p->data = ch;
                p->lchild = p->rchild = nullptr;
                if (b == nullptr) {
                    //p指向二叉树的根结点
                    b = p;
                } else {
                    //已建立二叉树根结点
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
 * 以广义表法输出二叉树
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
 * 求二叉树b的结点个数
 * @param b  binarytree
 * @return int
 */
int nodes(binarytree *b) {
    int num1, num2;
    if (b == nullptr) {
        return 0;
        // b为叶子节点
    } else if (b->lchild == nullptr && b->rchild == nullptr) {
        return 1;
    } else {
        num1 = nodes(b->lchild);
        num2 = nodes(b->rchild);
        return (num1 + num2 + 1);
    }
}

/**
 * 求二叉树b的叶子结点个数
 * @param b  binarytree
 * @return int
 */
int leafNodes(binarytree *b) {
    int num1, num2;
    if (b == nullptr) {
        return 0;
        // b为叶子节点
    } else if (b->lchild == nullptr && b->rchild == nullptr) {
        return 1;
    } else {
        num1 = leafNodes(b->lchild);
        num2 = leafNodes(b->rchild);
        return (num1 + num2);
    }
}

/**
 * 求二叉树b的深度
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
 * 先序遍历的递归算法
 * @param b binarytree
 */
void preOrder(binarytree *b) {
    if (b->data == NULL) {
        return;
    }
    // 输出根结点
    // printf("%c ", b->data);
    cout << b->data<<" ";
    // 遍历左子树
    if (b->lchild != nullptr) {
        preOrder(b->lchild);
    }
    // 遍历右子树
    if (b->rchild != nullptr) {
        preOrder(b->rchild);
    }
}

/**
 * 中序遍历的递归算法
 * @param b binarytree
 */
void inOrder(binarytree *b) {
    if (b->data == NULL) {
        return;
    }
    // 遍历左子树
    if (b->lchild != nullptr) {
        inOrder(b->lchild);
    }
    // 输出根结点
    //printf("%c ", b->data);
    cout << b->data<<" ";
    // 遍历右子树
    if (b->rchild != nullptr) {
        inOrder(b->rchild);
    }
}

/**
 * 后序遍历的递归算法
 * @param b binarytree
 */
void postOrder(binarytree *b) {
    if (b->data == NULL) {
        return;
    }
    // 遍历左子树
    if (b->lchild != nullptr) {
        postOrder(b->lchild);
    }
    // 遍历右子树
    if (b->rchild != nullptr) {
        postOrder(b->rchild);
    }
    // 输出根结点
    //printf("%c ", b->data);
    cout << b->data<<" ";
}

/**
 * 层次遍历算法
 * @param b binarytree
 */
void travLevel(binarytree *b) {
    //定义循环队列
    binarytree *Qu[MaxSize];
    //定义队首和队尾指针
    int front, rear;
    //置队列为空队列
    front = rear = 0;
    if (b != nullptr)
        printf("%c ", b->data);
    //结点指针进入队列
    rear++;
    Qu[rear] = b;
    //队列不为空
    while (rear != front) {
        front = (front + 1) % MaxSize;
        //队头出队列
        b = Qu[front];
        //输出左孩子,并入队列
        if (b->lchild != nullptr) {
            // printf("%c ", b->lchild->data);
            cout << b->lchild->data << " ";
            rear = (rear + 1) % MaxSize;
            Qu[rear] = b->lchild;
        }
        //输出右孩子,并入队列
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
 * 路径扫描
 * @param b binarytree
 * @param path  ElemType
 * @param pathlen  int
 */
void allPath(binarytree *b, ElemType path[], int pathlen) {
    int i;
    if (b != nullptr) {
        //*b为叶子结点
        if (b->lchild == nullptr && b->rchild == nullptr) {
            printf("%c到根结点路径: %c ", b->data, b->data);
            for (i = pathlen - 1; i >= 0; i--) {
                printf("%c ", path[i]);
            }
            printf("\n");
        } else {
            //将当前结点放入路径中
            path[pathlen] = b->data;
            //路径长度增1
            pathlen++;
            //递归扫描左子树
            allPath(b->lchild, path, pathlen);
            //递归扫描右子树
            allPath(b->rchild, path, pathlen);
            //恢复环境
            pathlen--;
        }
    }
}

#endif //C__DATASTRUCTURES_BINARYTREE_H
```
**binarytree.cpp**

```cpp
//
// Created by Administrator on 2022/12/9.
//

#include "binarytree.h"

int main() {
    binarytree *b;
    ElemType path[MaxSize];
    createBinaryTree(b, "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    cout << " 二叉树b: ";
    dispBinaryTree(b);
    cout << endl << endl;

    //在此处调用相关函数，输出二叉树b的结点个数;
    cout << "二叉树b的结点个数：" << nodes(b) << endl;
    //在此处调用相关函数，输出二叉树b的叶子结点个数;
    cout << "二叉树b的叶子结点个数：" << leafNodes(b) << endl;
    //在此处调用相关函数，输出二叉树b的深度;
    cout << "二叉树b的深度：" << binaryTreeDepth(b) << endl;

    //参照运行结果图，在此处调用先序遍历函数;
    cout << "先序遍历序列: ";
    preOrder(b);
    cout << endl;
    //参照运行结果图，在此处调用中序遍历函数;
    cout << "中序遍历序列: ";
    inOrder(b);
    cout << endl;
    //参照运行结果图，在此处调用后序遍历函数;
    cout << "后序遍历序列: ";
    postOrder(b);
    cout << endl;
    cout << "层次遍历序列: ";
    travLevel(b);
    cout << endl;

    cout << "叶子结点路径:" << endl;
    allPath(b, path, 0);
    cout << endl;
}
```

**运行截图**
![在这里插入图片描述](https://img-blog.csdnimg.cn/1745af87fc274fd5804955b532bff8f3.png)