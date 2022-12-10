//
// Created by Administrator on 2022/12/10.
//

#ifndef C__DATASTRUCTURES_BINARYNODE_H
#define C__DATASTRUCTURES_BINARYNODE_H

#include <iostream>

#define MaxSize 100
using namespace std;

#include <malloc.h>

//����ؼ�������
typedef int KeyType;
typedef char InfoType;

class binarynode {
public:
    //�ؼ�����
    KeyType key;
    //����������
    InfoType data;
    //���Һ���ָ��
    binarynode *lchild;
    binarynode *rchild;
};

//ȫ�ֱ���,���ڴ��·��
int path[MaxSize];

/**
 * ����*pΪ������BST�в���һ���ؼ���Ϊk�Ľ��
 * @param p binarynode
 * @param k KeyType
 * @return int
 */
bool insertBST(binarynode *&p, KeyType k) {
    //ԭ��Ϊ��, �²���ļ�¼Ϊ�����
    if (p == nullptr) {
        p = (binarynode *) malloc(sizeof(binarynode));
        p->key = k;
        p->lchild = p->rchild = nullptr;
        return true;
    } else if (k == p->key) {
        return false;
    } else if (k < p->key) {
        //�ݹ���ã����뵽*p����������
        return insertBST(p->lchild, k);
    } else {
        //�ݹ���ã����뵽*p����������
        return insertBST(p->rchild, k);
    }
}

//����˵��
void dispBST(binarynode *b);

/**
 * ������A�еĹؼ��ֽ���һ�ö���������
 * @param A KeyType
 * @param n int
 * @return binarynode
 */
binarynode *creatBST(KeyType A[], int n) {
    //��ʼʱbtΪ����
    binarynode *bt = nullptr;
    int i = 0;
    while (i < n)
        //��A[i]�������������T��
        if (insertBST(bt, A[i]) == 1) {
            printf("    ��%d��,����%d: ", i + 1, A[i]);
            dispBST(bt);
            cout << endl;
            i++;
        }
    //���ؽ����Ķ����������ĸ�ָ��
    return bt;
}

/**
 * �����ű�ʾ���������������bt
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
 * �Եݹ鷽ʽ����Ӹ���㵽���ҵ��Ľ���·��
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
 * ����ɾ*p�������������ʱ��ɾ������
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
        Delete1(p, p->lchild);    //�ݹ��������½��
    else                        //�ҵ��������½��*r
    {
        p->key = r->key;            //��*r�Ĺؼ���ֵ����*p
        q = r;
        r = r->lchild;            //��*r��˫�׽����Һ��ӽ���Ϊ*r�����ӽ��
        free(q);                //�ͷ�ԭ*r�Ŀռ�
    }
     */
}

//�Ӷ�����������ɾ��*p���
void Delete(binarynode *&p) {
    binarynode *q;
    //*p���û�������������
    if (p->rchild == nullptr) {
        q = p;
        p = p->lchild;
        free(q);
    } else if (p->lchild == nullptr) {
        //*p���û�������������
        q = p;
        p = p->rchild;
        free(q);
    } else {
        //*p���������������������������
        Delete1(p, p->lchild);
    }
}

/**
 * ��bt��ɾ���ؼ���Ϊk�Ľ��
 * @param bt binarynode
 * @param k KeyType
 * @return bool
 */
bool DeleteBST(binarynode *&bt, KeyType k) {
    //����ɾ��ʧ��
    if (bt == nullptr) {
        return false;
    } else {
        //С��˵�������
        if (k < bt->key) {
            //�ݹ�����������ɾ���ؼ���Ϊk�Ľ��
            return DeleteBST(bt->lchild, k);
        } else if (k > bt->key) {
            //�ݹ�����������ɾ���ؼ���Ϊk�Ľ��
            return DeleteBST(bt->rchild, k);
        } else { //k=bt->key�����
            //����Delete(bt)����ɾ��*bt���
            Delete(bt);
            return true;
        }
    }
}


int flag = true;
int pre = -256;

/**
 * �б������һ�ö������Ƿ�Ϊ����������
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
