//#include <iostream>
//#include <string>
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//#define null 0;
//#define n 10;
//
//using std::cout;
//using std::cin;
//using std::endl;
//using std::string;
//using namespace std;
//
//
//
//struct stack {
//    char *base;
//    char *top;
//    int stacksize;
//};
//
//void initstack(struct stack *s) {
//    s->base = (char *) malloc(20 * sizeof(char));
//    if (!s->base) exit(0);
//    s->top = s->base;
//    s->stacksize = 20;
//    return;
//}
//
//void push(struct stack *s, char e) {
//    if (s->top - s->base >= s->stacksize) {
//        s->base = (char *) realloc(s->base, (s->stacksize + 10) * sizeof(char));
//        if (!s->base) exit(0);
//        s->top = s->base + s->stacksize;
//        s->stacksize += n;
//    }
//    *(s->top)++ = e;
//    return;
//}
//
//char pop(struct stack *s) {
//    char e;
//    if (s->top == s->base) return null;
//    e = *--s->top;
//    return e;
//}
//
//void clearstack(struct stack *s) {
//
//    if (s->top == s->base) return;
//    s->top = s->base;
//    return;
//}
//
//int StackEmpty(struct stack *s) {
//
//    if (s->top == s->base) return 1;
//    else return 0;
//
//}
//
//typedef int elemType;
//
///* �����ǹ��ڶ������Ӵ洢������6���㷨  */
//
//struct sNode {
//    elemType data;            /* ֵ�� */
//    struct sNode *next;        /* ����ָ�� */
//};
//
//struct queueLK {
//    struct sNode *front;    /* ����ָ�� */
//    struct sNode *rear;        /* ��βָ�� */
//};
//
//
///* 1.��ʼ������ */
//void initQueue(struct queueLK *hq) {
//    hq->front = (sNode *) malloc(20 * sizeof(struct sNode));
//    if (!hq->front) exit(0);
//    hq->front = hq->rear = NULL;        /* �Ѷ��׺Ͷ�βָ���ÿ� */
//    return;
//}
//
//
///* 2.�������в���һ��Ԫ��x */
//void enQueue(struct queueLK *hq, elemType x) {
//    /* �õ�һ����newPָ����ָ����½�� */
//    struct sNode *newP;
//    newP = (sNode *) malloc(sizeof(struct sNode));
//    if (newP == NULL) {
//        printf("�ڴ�ռ����ʧ�ܣ� ");
//        exit(1);
//    }
//    /* ��x��ֵ�����½���ֵ�򣬰��½���ָ�����ÿ� */
//    newP->data = x;
//    newP->next = NULL;
//    /* ������Ϊ�գ����½�㼴�Ƕ��׽�����Ƕ�β��� */
//    if (hq->rear == NULL) {
//        hq->front = hq->rear = newP;
//    } else {                      /* �����ӷǿգ��������޸Ķ�β����ָ����Ͷ�βָ�룬ʹָ֮���µĶ�β��� */
//        hq->rear->next = newP;
//        hq->rear = newP;/* ע�⸳ֵ˳��Ŷ */
//    }
//    return;
//}
//
//
///* 3.�Ӷ�����ɾ��һ��Ԫ�� */
//int outQueue(struct queueLK *hq) {
//    struct sNode *p;
//    int temp;
//    /* ������Ϊ����ֹͣ���� */
//    if (hq->front == NULL) {
//        printf("����Ϊ�գ��޷�ɾ���� ");
//        exit(1);
//    }
//    temp = hq->front->data;        /* �ݴ��βԪ���Ա㷵�� */
//    p = hq->front;                /* �ݴ��βָ���Ա���ն�β��� */
//    hq->front = p->next;        /* ʹ����ָ��ָ����һ����� */
//    /* ��ɾ��������Ϊ�գ�����ͬʱʹ��βָ��Ϊ�� */
//    if (hq->front == NULL) {
//        hq->rear = NULL;
//    }
//    free(p);        /* ����ԭ���׽�� */
//    return temp;    /* ���ر�ɾ���Ķ���Ԫ��ֵ */
//}
//
//
///* 4.��������Ƿ�Ϊ�գ���Ϊ���򷵻�1, ���򷵻�0 */
//int emptyQueue(struct queueLK *hq) {
//    /* �ж϶��׻��β��һ��ָ���Ƿ�Ϊ�ռ��� */
//    if (hq->front == NULL) {
//        return 1;
//    } else {
//        return 0;
//    }
//}
//
//
///************************************************************************/
//
//void useStack(struct stack s, char *a) {
//    cout << "����һ���ַ���@��β" << endl;
//    cin >> a;
//    for (int i = 0; i < strlen(a) - 1; i++) {
//        if (a[i] != '\@') {
//            push(&s, a[i]);
//        }
//    }
//    int i = 0;
//    while (!StackEmpty(&s)) {
//        if (pop(&s) != a[i]) {
//            cout << "���ǻ�����" << endl;
//            break;
//        }
//        i++;
//    }
//    if (StackEmpty(&s)) {
//        cout << "�ǻ�����" << endl;
//    }
//}
//
//void useStackAnDQueue(struct queueLK q, struct stack s, char *a) {
//    cout << "����һ���ַ���@��β" << endl;
//    cin >> a;
//    for (int i = 0; i < strlen(a) - 1; i++) {
//        if (a[i] != '\@') {
//            push(&s, a[i]);
//            enQueue(&q, a[i]);
//        }
//    }
//    while (!StackEmpty(&s) && !emptyQueue(&q)) {
//        if (pop(&s) != outQueue(&q)) {
//            cout << "���ǻ�����" << endl;
//            break;
//        }
//    }
//    if (StackEmpty(&s) && emptyQueue(&q)) {
//        cout << "�ǻ�����" << endl;
//    }
//}
//
//int main() {
//    struct queueLK q;
//    struct stack s;
//    char a[10];
//    initQueue(&q);
//    initstack(&s);
//
//    useStackAnDQueue(q, s, a);
//
//    //����ջ�Ͷ��еĲ����ص�дһ�δ���
//
//    //�б�����һ���ԡ�@��Ϊ���������ַ������Ƿ��ǡ����ġ���
//}
