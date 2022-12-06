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
 * ��ʼ��ջ
 * @param s stack
 */
void initStack(stack *s) {
    s->base = (char *) malloc(20 * sizeof(char));
    if (!s->base) exit(0);
    s->top = s->base;
    s->stacksize = 20;
}

/**
 * ��ջ
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
 * ��ջ
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
 * ���ջ
 * @param s stack
 */
void clearstack(stack *s) {
    if (s->top == s->base) return;
    s->top = s->base;
}

/**
 * �ж��Ƿ�Ϊ��
 * @param s stack
 * @return bool
 */
bool isEmpty(stack *s) {
    return s->top == s->base;
}

class sNode {
public:
    // ֵ��
    elemType data;
    // ����ָ��
    struct sNode *next;
};

class myqueue {
public:
    // ����ָ��
    struct sNode *front;
    //��βָ��
    struct sNode *rear;        /*  */
};

/**
 * ��ʼ������
 * @param mq myqueue
 */
void initQueue(myqueue *mq) {
    mq->front = (sNode *) malloc(20 * sizeof(struct sNode));
    if (!mq->front) exit(0);
    mq->front = mq->rear = nullptr;
}

/**
 * �������в���һ��Ԫ��x
 * @param mq myqueue
 * @param x elemType
*/
void enQueue(myqueue *mq, elemType x) {
    // �õ�һ����newPָ����ָ����½��
    sNode *newP;
    newP = (sNode *) malloc(sizeof(struct sNode));
    if (newP == nullptr) {
        cout << "�ڴ�ռ����ʧ�ܣ�  ";
        exit(1);
    }
    // ��x��ֵ�����½���ֵ�򣬰��½���ָ�����ÿ�
    newP->data = x;
    newP->next = nullptr;
    // ������Ϊ�գ����½�㼴�Ƕ��׽�����Ƕ�β���
    if (mq->rear == nullptr) {
        mq->front = mq->rear = newP;
    } else {  // �����ӷǿգ��������޸Ķ�β����ָ����Ͷ�βָ�룬ʹָ֮���µĶ�β��� */
        mq->rear->next = newP;
        // ע�⸳ֵ˳��Ŷ
        mq->rear = newP;
    }
}

/**
 * �Ӷ�����ɾ��һ��Ԫ��
 * @param mq  myqueue
 * @return Ԫ��
 */
int deQueue(myqueue *mq) {
    sNode *p;
    int temp;
    // ������Ϊ����ֹͣ����
    if (mq->front == nullptr) {
        cout << "����Ϊ�գ��޷�ɾ���� ";
        exit(1);
    }
    // �ݴ��βԪ���Ա㷵��
    temp = mq->front->data;
    // �ݴ��βָ���Ա���ն�β���
    p = mq->front;
    // ʹ����ָ��ָ����һ�����
    mq->front = p->next;
    // ��ɾ��������Ϊ�գ�����ͬʱʹ��βָ��Ϊ��
    if (mq->front == nullptr) {
        mq->rear = nullptr;
    }
    // ����ԭ���׽��
    free(p);
    // ���ر�ɾ���Ķ���Ԫ��ֵ
    return temp;
}

/**
 * ��������Ƿ�Ϊ��
 * @param mq myqueue
 * @return bool
 */
bool emptyQueue(myqueue *mq) {
    // �ж϶��׻��β��һ��ָ���Ƿ�Ϊ�ռ���
    return mq->front == nullptr;
}

/************************************************************************/

void useStack(stack s, char *a) {
    cout << "����һ���ַ���@��β" << endl;
    cin >> a;
    for (int i = 0; i < strlen(a) - 1; i++) {
        if (a[i] != '\\@') {
            push(&s, a[i]);
        }
    }
    int i = 0;
    while (!isEmpty(&s)) {
        if (pop(&s) != a[i]) {
            cout << "���ǻ�����" << endl;
            break;
        }
        i++;
    }
    if (isEmpty(&s)) {
        cout << "�ǻ�����" << endl;
    }
}

void useStackAnDQueue(myqueue mq, struct stack s, char *a) {
    cout << "����һ���ַ���@��β" << endl;
    cin >> a;
    for (int i = 0; i < strlen(a) - 1; i++) {
        if (a[i] != '\\@') {
            push(&s, a[i]);
            enQueue(&mq, a[i]);
        }
    }
    while (!isEmpty(&s) && !emptyQueue(&mq)) {
        if (pop(&s) != deQueue(&mq)) {
            cout << "���ǻ�����" << endl;
            break;
        }
    }
    if (isEmpty(&s) && emptyQueue(&mq)) {
        cout << "�ǻ�����" << endl;
    }
}

#endif //C__DATASTRUCTURES_MYQUEUE_H
