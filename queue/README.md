# 栈和队列应用

**判别读入的一个以’@’为结束符的字符序列是否是“回文”**

**myqueue.h**

```cpp
//
// Created by Administrator on 2022/12/6.
//
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#define null 0;
#define n 10;

#ifndef C__DATASTRUCTURES_MYQUEUE_H
#define C__DATASTRUCTURES_MYQUEUE_H
using std::cout;

using std::cin;
using std::endl;
using std::string;
using namespace std;
typedef int elemType;

class stack {
public:
    char *base;
    char *top;
    int stacksize;
};

/**
 * 初始化栈
 * @param s stack
 */
void initStack(stack *s) {
    s->base = (char *) malloc(20 * sizeof(char));
    if (!s->base) exit(0);
    s->top = s->base;
    s->stacksize = 20;
}

/**
 * 入栈
 * @param s stack
 * @param e char
 */
void push(stack *s, char e) {
    if (s->top - s->base >= s->stacksize) {
        s->base = (char *) realloc(s->base, (s->stacksize + 10) * sizeof(char));
        if (!s->base) exit(0);
        s->top = s->base + s->stacksize;
        s->stacksize += n;
    }
    *(s->top)++ = e;
}

/**
 * 弹栈
 * @param s stack
 * @return char
 */
char pop(stack *s) {
    char e;
    if (s->top == s->base) return null;
    e = *--s->top;
    return e;
}

/**
 * 清空栈
 * @param s stack
 */
void clearstack(stack *s) {
    if (s->top == s->base) return;
    s->top = s->base;
}

/**
 * 判断是否为空
 * @param s stack
 * @return bool
 */
bool isEmpty(stack *s) {
    return s->top == s->base;
}

class sNode {
public:
    // 值域
    elemType data;
    // 链接指针
    struct sNode *next;
};

class myqueue {
public:
    // 队首指针
    struct sNode *front;
    //队尾指针
    struct sNode *rear;        /*  */
};

/**
 * 初始化链队
 * @param mq myqueue
 */
void initQueue(myqueue *mq) {
    mq->front = (sNode *) malloc(20 * sizeof(struct sNode));
    if (!mq->front) exit(0);
    mq->front = mq->rear = nullptr;
}

/**
 * 向链队中插入一个元素x
 * @param mq myqueue
 * @param x elemType
*/
void enQueue(myqueue *mq, elemType x) {
    // 得到一个由newP指针所指向的新结点
    sNode *newP;
    newP = (sNode *) malloc(sizeof(struct sNode));
    if (newP == nullptr) {
        cout << "内存空间分配失败！  ";
        exit(1);
    }
    // 把x的值赋给新结点的值域，把新结点的指针域置空
    newP->data = x;
    newP->next = nullptr;
    // 若链队为空，则新结点即是队首结点又是队尾结点
    if (mq->rear == nullptr) {
        mq->front = mq->rear = newP;
    } else {  // 若链队非空，则依次修改队尾结点的指针域和队尾指针，使之指向新的队尾结点 */
        mq->rear->next = newP;
        // 注意赋值顺序哦
        mq->rear = newP;
    }
}

/**
 * 从队列中删除一个元素
 * @param mq  myqueue
 * @return 元素
 */
int deQueue(myqueue *mq) {
    sNode *p;
    int temp;
    // 若链队为空则停止运行
    if (mq->front == nullptr) {
        cout << "队列为空，无法删除！ ";
        exit(1);
    }
    // 暂存队尾元素以便返回
    temp = mq->front->data;
    // 暂存队尾指针以便回收队尾结点
    p = mq->front;
    // 使队首指针指向下一个结点
    mq->front = p->next;
    // 若删除后链队为空，则需同时使队尾指针为空
    if (mq->front == nullptr) {
        mq->rear = nullptr;
    }
    // 回收原队首结点
    free(p);
    // 返回被删除的队首元素值
    return temp;
}

/**
 * 检查链队是否为空
 * @param mq myqueue
 * @return bool
 */
bool emptyQueue(myqueue *mq) {
    // 判断队首或队尾任一个指针是否为空即可
    return mq->front == nullptr;
}

/************************************************************************/

void useStack(stack s, char *a) {
    cout << "输入一串字符以@结尾" << endl;
    cin >> a;
    for (int i = 0; i < strlen(a) - 1; i++) {
        if (a[i] != '\\@') {
            push(&s, a[i]);
        }
    }
    int i = 0;
    while (!isEmpty(&s)) {
        if (pop(&s) != a[i]) {
            cout << "不是回文数" << endl;
            break;
        }
        i++;
    }
    if (isEmpty(&s)) {
        cout << "是回文数" << endl;
    }
}

void useStackAnDQueue(myqueue mq, struct stack s, char *a) {
    cout << "输入一串字符以@结尾" << endl;
    cin >> a;
    for (int i = 0; i < strlen(a) - 1; i++) {
        if (a[i] != '\\@') {
            push(&s, a[i]);
            enQueue(&mq, a[i]);
        }
    }
    while (!isEmpty(&s) && !emptyQueue(&mq)) {
        if (pop(&s) != deQueue(&mq)) {
            cout << "不是回文数" << endl;
            break;
        }
    }
    if (isEmpty(&s) && emptyQueue(&mq)) {
        cout << "是回文数" << endl;
    }
}

#endif //C__DATASTRUCTURES_MYQUEUE_H
```

**myqueue.cpp**

```cpp
//
// Created by Administrator on 2022/12/6.
//
#include "myqueue.h"

int main() {
    myqueue q{};
    stack s{};
    char a[10];
    
    initQueue(&q);
    initStack(&s);

    useStack(s, a);
    //useStackAnDQueue(q, s, a);

    //利用栈和队列的操作特点写一段代码

    //判别读入的一个以’@’为结束符的字符序列是否是“回文”。
}
```

**运行截图**



![在这里插入图片描述](https://img-blog.csdnimg.cn/f736b337a76846889d95570456edfdb2.png)

****

![在这里插入图片描述](https://img-blog.csdnimg.cn/80a959d613a444459877d094eaede48f.png)