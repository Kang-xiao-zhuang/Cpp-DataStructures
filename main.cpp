//#include <stdio.h>
//#include <malloc.h>
//
//#define MaxSize 100
////定义关键字类型
//typedef int KeyType;
//typedef char InfoType;
////记录类型
//typedef struct node {
//    //关键字项
//    KeyType key;
//    //其他数据域
//    InfoType data;
//    //左右孩子指针
//    struct node *lchild;
//    struct node *rchild;
//} BSTNode;
////全局变量,用于存放路径
//int path[MaxSize];
//
////函数说明
//void DispBST(BSTNode *b);
//
////在以*p为根结点的BST中插入一个关键字为k的结点
//int InsertBST(BSTNode *&p, KeyType k) {
//    //原树为空, 新插入的记录为根结点
//    if (p == nullptr) {
//        p = (BSTNode *) malloc(sizeof(BSTNode));
//        p->key = k;
//        p->lchild = p->rchild = nullptr;
//        return 1;
//    } else if (k == p->key) {
//        return 0;
//    } else if (k < p->key) {
//        //递归调用，插入到*p的左子树中
//        return InsertBST(p->lchild, k);
//    } else {
//        //递归调用，插入到*p的右子树中
//        return InsertBST(p->rchild, k);
//    }
//}
//
////由数组A中的关键字建立一棵二叉排序树
//BSTNode *CreatBST(KeyType A[], int n) {
//    //初始时bt为空树
//    BSTNode *bt = nullptr;
//    int i = 0;
//    while (i < n)
//        //将A[i]插入二叉排序树T中
//        if (InsertBST(bt, A[i]) == 1) {
//            printf("    第%d步,插入%d: ", i + 1, A[i]);
//            DispBST(bt);
//            printf("\n");
//            i++;
//        }
//    //返回建立的二叉排序树的根指针
//    return bt;
//}
//
////以括号表示法输出二叉排序树bt
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
////以递归方式输出从根结点到查找到的结点的路径
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
////当被删*p结点有左右子树时的删除过程
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
//        Delete1(p, p->lchild);    //递归找最右下结点
//    else                        //找到了最右下结点*r
//    {
//        p->key = r->key;            //将*r的关键字值赋给*p
//        q = r;
//        r = r->lchild;            //将*r的双亲结点的右孩子结点改为*r的左孩子结点
//        free(q);                //释放原*r的空间
//    }
//     */
//}
//
////从二叉排序树中删除*p结点
//void Delete(BSTNode *&p) {
//    BSTNode *q;
//    //*p结点没有右子树的情况
//    if (p->rchild == nullptr) {
//        q = p;
//        p = p->lchild;
//        free(q);
//    } else if (p->lchild == nullptr) { //*p结点没有左子树的情况
//        q = p;
//        p = p->rchild;
//        free(q);
//    } else { //*p结点既有左子树又有右子树的情况
//        Delete1(p, p->lchild);
//    }
//}
//
////在bt中删除关键字为k的结点
//int DeleteBST(BSTNode *&bt, KeyType k) {
//    //空树删除失败
//    if (bt == nullptr) {
//        return 0;
//    } else {
//        //小于说明在左边
//        if (k < bt->key) {
//            //递归在左子树中删除关键字为k的结点
//            return DeleteBST(bt->lchild, k);
//        } else if (k > bt->key) {
//            //递归在右子树中删除关键字为k的结点
//            return DeleteBST(bt->rchild, k);
//        } else { //k=bt->key的情况
//            //调用Delete(bt)函数删除*bt结点
//            Delete(bt);
//            return 1;
//        }
//    }
//}
//
////predt为全局变量,保存当前结点中序前趋的值,初值为-∞
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
//    printf(" 创建一棵BST树:");
//    printf("\n");
//    bt = CreatBST(a, n);
//
//    printf("\n\n BST: ");
//    DispBST(bt);
//    printf("\n\n");
//
//    printf(" 查找%d关键字: ", k);
//    SearchBST(bt, k);
//
//    printf("\n\n 删除操作:\n");
//    printf("   原BST: ");
//    DispBST(bt);
//    printf("\n");
//
//    printf("   删除结点4: ");
//    DeleteBST(bt, 4);
//    DispBST(bt);
//    printf("\n");
//
//    printf("   删除结点5: ");
//    DeleteBST(bt, 5);
//
//    DispBST(bt);
//    printf("\n\n");
//}
