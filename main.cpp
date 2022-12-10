//#include <stdio.h>
//#include <malloc.h>
//
//#define MaxSize 100
////����ؼ�������
//typedef int KeyType;
//typedef char InfoType;
////��¼����
//typedef struct node {
//    //�ؼ�����
//    KeyType key;
//    //����������
//    InfoType data;
//    //���Һ���ָ��
//    struct node *lchild;
//    struct node *rchild;
//} BSTNode;
////ȫ�ֱ���,���ڴ��·��
//int path[MaxSize];
//
////����˵��
//void DispBST(BSTNode *b);
//
////����*pΪ������BST�в���һ���ؼ���Ϊk�Ľ��
//int InsertBST(BSTNode *&p, KeyType k) {
//    //ԭ��Ϊ��, �²���ļ�¼Ϊ�����
//    if (p == nullptr) {
//        p = (BSTNode *) malloc(sizeof(BSTNode));
//        p->key = k;
//        p->lchild = p->rchild = nullptr;
//        return 1;
//    } else if (k == p->key) {
//        return 0;
//    } else if (k < p->key) {
//        //�ݹ���ã����뵽*p����������
//        return InsertBST(p->lchild, k);
//    } else {
//        //�ݹ���ã����뵽*p����������
//        return InsertBST(p->rchild, k);
//    }
//}
//
////������A�еĹؼ��ֽ���һ�ö���������
//BSTNode *CreatBST(KeyType A[], int n) {
//    //��ʼʱbtΪ����
//    BSTNode *bt = nullptr;
//    int i = 0;
//    while (i < n)
//        //��A[i]�������������T��
//        if (InsertBST(bt, A[i]) == 1) {
//            printf("    ��%d��,����%d: ", i + 1, A[i]);
//            DispBST(bt);
//            printf("\n");
//            i++;
//        }
//    //���ؽ����Ķ����������ĸ�ָ��
//    return bt;
//}
//
////�����ű�ʾ���������������bt
//void DispBST(BSTNode *bt) {
//    if (bt != nullptr) {
//        printf("%d", bt->key);
//        if (bt->lchild != nullptr || bt->rchild != nullptr) {
//            printf("(");
//            DispBST(bt->lchild);
//            if (bt->rchild != nullptr) {
//                printf(",");
//            }
//            DispBST(bt->rchild);
//            printf(")");
//        }
//    }
//}
//
////�Եݹ鷽ʽ����Ӹ���㵽���ҵ��Ľ���·��
//int SearchBST(BSTNode *bt, KeyType k) {
//    printf("%d ", bt->key);
//    if (k == bt->key) {
//        return bt->key;
//    } else if (k < bt->key) {
//        return SearchBST(bt->lchild, k);
//    } else if (k > bt->key) {
//        return SearchBST(bt->rchild, k);
//    }
//}
//
////����ɾ*p�������������ʱ��ɾ������
//void Delete1(BSTNode *p, BSTNode *&r) {
//    BSTNode *s;
//    BSTNode *q;
//    q = p;
//    s = p->lchild;
//    while (s->rchild) {
//        q = s;
//        s = s->rchild;
//    }
//    p->key = s->key;
//    if (q != p) {
//        q->rchild = s->lchild;
//    } else {
//        q->lchild = s->lchild;
//    }
//    delete s;
//    /*
//    if (r->rchild != nullptr)
//        Delete1(p, p->lchild);    //�ݹ��������½��
//    else                        //�ҵ��������½��*r
//    {
//        p->key = r->key;            //��*r�Ĺؼ���ֵ����*p
//        q = r;
//        r = r->lchild;            //��*r��˫�׽����Һ��ӽ���Ϊ*r�����ӽ��
//        free(q);                //�ͷ�ԭ*r�Ŀռ�
//    }
//     */
//}
//
////�Ӷ�����������ɾ��*p���
//void Delete(BSTNode *&p) {
//    BSTNode *q;
//    //*p���û�������������
//    if (p->rchild == nullptr) {
//        q = p;
//        p = p->lchild;
//        free(q);
//    } else if (p->lchild == nullptr) { //*p���û�������������
//        q = p;
//        p = p->rchild;
//        free(q);
//    } else { //*p���������������������������
//        Delete1(p, p->lchild);
//    }
//}
//
////��bt��ɾ���ؼ���Ϊk�Ľ��
//int DeleteBST(BSTNode *&bt, KeyType k) {
//    //����ɾ��ʧ��
//    if (bt == nullptr) {
//        return 0;
//    } else {
//        //С��˵�������
//        if (k < bt->key) {
//            //�ݹ�����������ɾ���ؼ���Ϊk�Ľ��
//            return DeleteBST(bt->lchild, k);
//        } else if (k > bt->key) {
//            //�ݹ�����������ɾ���ؼ���Ϊk�Ľ��
//            return DeleteBST(bt->rchild, k);
//        } else { //k=bt->key�����
//            //����Delete(bt)����ɾ��*bt���
//            Delete(bt);
//            return 1;
//        }
//    }
//}
//
////predtΪȫ�ֱ���,���浱ǰ�������ǰ����ֵ,��ֵΪ-��
//KeyType predt = -32767;
//
//int main() {
//    BSTNode *bt;
//    KeyType k = 6;
//    int a[] = {4, 9, 0, 1, 8, 6, 3, 5, 2, 7}, n = 10;
//    /*
//    4
//   / \
//  0   9
//   \ /
//   1 8
//   \  /
//   3 6
//  /  /\
//  2  5 7
//     */
//    printf(" ����һ��BST��:");
//    printf("\n");
//    bt = CreatBST(a, n);
//
//    printf("\n\n BST: ");
//    DispBST(bt);
//    printf("\n\n");
//
//    printf(" ����%d�ؼ���: ", k);
//    SearchBST(bt, k);
//
//    printf("\n\n ɾ������:\n");
//    printf("   ԭBST: ");
//    DispBST(bt);
//    printf("\n");
//
//    printf("   ɾ�����4: ");
//    DeleteBST(bt, 4);
//    DispBST(bt);
//    printf("\n");
//
//    printf("   ɾ�����5: ");
//    DeleteBST(bt, 5);
//
//    DispBST(bt);
//    printf("\n\n");
//}
