//
// Created by Administrator on 2022/12/10.
//

#ifndef C__DATASTRUCTURES_BINARYNODE_H
#define C__DATASTRUCTURES_BINARYNODE_H

#include <iostream>

#define MaxSize 100
using namespace std;

#include <malloc.h>

//定义关键字类型
typedef int KeyType;
typedef char InfoType;

class binarynode {
public:
    //关键字项
    KeyType key;
    //其他数据域
    InfoType data;
    //左右孩子指针
    binarynode *lchild;
    binarynode *rchild;
};

//全局变量,用于存放路径
int path[MaxSize];

/**
 * 在以*p为根结点的BST中插入一个关键字为k的结点
 * @param p binarynode
 * @param k KeyType
 * @return int
 */
bool insertBST(binarynode *&p, KeyType k) {
    //原树为空, 新插入的记录为根结点
    if (p == nullptr) {
        p = (binarynode *) malloc(sizeof(binarynode));
        p->key = k;
        p->lchild = p->rchild = nullptr;
        return true;
    } else if (k == p->key) {
        return false;
    } else if (k < p->key) {
        //递归调用，插入到*p的左子树中
        return insertBST(p->lchild, k);
    } else {
        //递归调用，插入到*p的右子树中
        return insertBST(p->rchild, k);
    }
}

//函数说明
void dispBST(binarynode *b);

/**
 * 由数组A中的关键字建立一棵二叉排序树
 * @param A KeyType
 * @param n int
 * @return binarynode
 */
binarynode *creatBST(KeyType A[], int n) {
    //初始时bt为空树
    binarynode *bt = nullptr;
    int i = 0;
    while (i < n)
        //将A[i]插入二叉排序树T中
        if (insertBST(bt, A[i]) == 1) {
            printf("    第%d步,插入%d: ", i + 1, A[i]);
            dispBST(bt);
            cout << endl;
            i++;
        }
    //返回建立的二叉排序树的根指针
    return bt;
}

/**
 * 以括号表示法输出二叉排序树bt
 * @param bt
 */
void dispBST(binarynode *bt) {
    if (bt != nullptr) {
        cout << bt->key;
        //printf("%d", bt->key);
        if (bt->lchild != nullptr || bt->rchild != nullptr) {
            cout << "(";
            dispBST(bt->lchild);
            if (bt->rchild != nullptr) {
                cout << ",";
            }
            dispBST(bt->rchild);
            cout << ")";
        }
    }
}

/**
 * 以递归方式输出从根结点到查找到的结点的路径
 * @param bt binarynode
 * @param k KeyType
 * @return int
 */
int SearchBST(binarynode *bt, KeyType k) {
    cout << bt->key << " ";
    //printf("%d ", bt->key);
    if (k == bt->key) {
        return bt->key;
    } else if (k < bt->key) {
        return SearchBST(bt->lchild, k);
    } else if (k > bt->key) {
        return SearchBST(bt->rchild, k);
    }
}

/**
 * 当被删*p结点有左右子树时的删除过程
 * @param p binarynode
 * @param r binarynode
 */
void Delete1(binarynode *p, binarynode *&r) {
    binarynode *s;
    binarynode *q;
    q = p;
    s = p->lchild;
    while (s->rchild) {
        q = s;
        s = s->rchild;
    }
    p->key = s->key;
    if (q != p) {
        q->rchild = s->lchild;
    } else {
        q->lchild = s->lchild;
    }
    delete s;
    /*
    if (r->rchild != nullptr)
        Delete1(p, p->lchild);    //递归找最右下结点
    else                        //找到了最右下结点*r
    {
        p->key = r->key;            //将*r的关键字值赋给*p
        q = r;
        r = r->lchild;            //将*r的双亲结点的右孩子结点改为*r的左孩子结点
        free(q);                //释放原*r的空间
    }
     */
}

//从二叉排序树中删除*p结点
void Delete(binarynode *&p) {
    binarynode *q;
    //*p结点没有右子树的情况
    if (p->rchild == nullptr) {
        q = p;
        p = p->lchild;
        free(q);
    } else if (p->lchild == nullptr) {
        //*p结点没有左子树的情况
        q = p;
        p = p->rchild;
        free(q);
    } else {
        //*p结点既有左子树又有右子树的情况
        Delete1(p, p->lchild);
    }
}

/**
 * 在bt中删除关键字为k的结点
 * @param bt binarynode
 * @param k KeyType
 * @return bool
 */
bool DeleteBST(binarynode *&bt, KeyType k) {
    //空树删除失败
    if (bt == nullptr) {
        return false;
    } else {
        //小于说明在左边
        if (k < bt->key) {
            //递归在左子树中删除关键字为k的结点
            return DeleteBST(bt->lchild, k);
        } else if (k > bt->key) {
            //递归在右子树中删除关键字为k的结点
            return DeleteBST(bt->rchild, k);
        } else { //k=bt->key的情况
            //调用Delete(bt)函数删除*bt结点
            Delete(bt);
            return true;
        }
    }
}


int flag = true;
int pre = -256;

/**
 * 判别给定的一棵二叉树是否为二叉排序树
 * @param bt binarynode
 * @return bool
 */
bool isBinaryTree(binarynode *&bt) {
    if (bt->lchild != nullptr && flag) {
        isBinaryTree(bt->lchild);
    }
    if (bt->data < pre) {
        flag = false;
    }
    if (bt->rchild != nullptr && flag) {
        isBinaryTree(bt->rchild);
    }
    return flag;
}

#endif //C__DATASTRUCTURES_BINARYNODE_H
