### 1.顺序查找
运行结果如图所示：
![在这里插入图片描述](https://img-blog.csdnimg.cn/3d5a55d5d7324e78bf98c5645d079385.png)
**seqSearch.cpp**

```cpp
#include <stdio.h>
//定义表中最多记录个数
#define MAXL 100
typedef int KeyType;
typedef char InfoType[10];

typedef struct {
    //KeyType为关键字的数据类型
    KeyType key;
    //其他数据
    InfoType data;
} NodeType;
//顺序表类型
typedef NodeType SeqList[MAXL];

//顺序查找算法
int SeqSearch(SeqList R, int n, KeyType k) {
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (R[i].key == k) {
            index = i;
        }
        printf("%d ", R[i].key);
    }
    return index;
}

int main() {
    SeqList R;
    int n = 10;
    KeyType k = 5;

    int a[] = {3, 6, 2, 10, 1, 8, 5, 7, 4, 9};
    int i;
    //建立顺序表
    for (i = 0; i < n; i++) {
        R[i].key = a[i];
    }
    printf("\n");

    if ((i = SeqSearch(R, n, k)) != -1) {
        printf("\n元素%d的位置是%d\n", k, i);
    } else {
        printf("\n元素%d不在表中\n", k);
    }
    printf("\n");
}
```
**运行截图**
![在这里插入图片描述](https://img-blog.csdnimg.cn/c80f75fe2d1f49e19b37c7323f2efcf4.png)
### 2. 折半查找
运行结果如图所示：
![在这里插入图片描述](https://img-blog.csdnimg.cn/78c7699a388a4b128fec163c049e8fd8.png)
**binSearch.cpp**

```cpp
#include <stdio.h>
//定义表中最多记录个数
#define MAXL 100                    

typedef int KeyType;
typedef char InfoType[10];

typedef struct {
    //KeyType为关键字的数据类型
    KeyType key;
    //其他数据
    InfoType data;
} NodeType;

//顺序表类型
typedef NodeType SeqList[MAXL];

//二分查找算法
int BinSearch(SeqList R, int n, KeyType k) {
    int low = 1;
    int high = n;
    int count = 1;
    int res = 0;
    while (low <= high && count < 4) {
        int mid = (low + high) / 2;
        if (count < 3) {
            printf("第%d次查找:在[%d,%d]中查找到元素R[%d]:%d\n", count, low - 1, high - 1, mid - 1, R[mid - 1].key);
        }
        if (k == R[mid].key) {
            res = mid;
            high = n;
            low = R[mid].key;
            count++;
            printf("第%d次查找:在[%d,%d]中查找到元素R[%d]:%d\n", count, low - 1, high - 1, res, R[res].key);
        } else if (k < R[mid].key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        count++;
    }
    return res;
}

int main() {
    SeqList R;
    KeyType k = 9;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, i, n = 10;
    //建立顺序表
    for (i = 0; i < n; i++) {
        R[i].key = a[i];
    }
    printf("\n");

    if ((i = BinSearch(R, n, k)) != -1) {
        printf("元素%d的位置是%d\n", k, i);
    } else {
        printf("元素%d不在表中\n", k);
    }
    printf("\n");
}
```
**运行截图**
![在这里插入图片描述](https://img-blog.csdnimg.cn/8e811af020a94418acede4e7661fa45f.png)
### 3. 二叉排序树的基本运算
运行结果如图所示：
![在这里插入图片描述](https://img-blog.csdnimg.cn/b7eba08c286d48c2b6dd378d33c7086e.png)
**binarynode.h**

```cpp
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
```
**binarynode.cpp**

```cpp
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
```



**运行截图**
![在这里插入图片描述](https://img-blog.csdnimg.cn/c3c0354d580b4860a40e3ccdf7d8dc56.png)

### 4.自行设计一个算法，判别给定的一棵二叉树是否为二叉排序树
**根据第三题结构，添加如下算法代码**



**binarynode.h**

```cpp
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
```
**binarynode.cpp**

```cpp
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

    cout << " 是否是二叉排序树:" << endl;
    if (isBinaryTree(bt)) {
        cout << "是二叉排序树" << endl;
    } else {
        cout << "不是二叉排序树" << endl;
    }
}
```

**运行截图**
![在这里插入图片描述](https://img-blog.csdnimg.cn/8baf13c6127b44129959d3e08093da90.png)