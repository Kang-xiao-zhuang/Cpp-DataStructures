//
// Created by Administrator on 2022/12/4.
//
#ifndef C__DATASTRUCTURES_LINKLIST_H
#define C__DATASTRUCTURES_LINKLIST_H

#include <cstdio>
#include <cstdlib>

#define LEN sizeof(linklist)

#include <malloc.h>
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class linklist {
public:
    //ѧ��
    long num;
    //�ɼ�
    float score;
    //ָ����
    linklist *next;
};

// ����ĳ���
int n;

/**
 * ��ʼ������
 * @return  linklist
 */
linklist *create(void) {
    // ��������ָ��
    linklist *p1, *p2;
    linklist *l;
    n = 0;
    //ͷ�ڵ� ���뿪���ڴ�ռ�
    l = p1 = (linklist *) malloc(LEN);
    p2 = (linklist *) malloc(LEN);
    //����ѧ�š��ɼ�
    scanf("%ld,%f", &p2->num, &p2->score);
    //ѧ��Ϊ0ʱ��¼�����
    while (p2->num != 0) {
        // ���ȼ�1
        n++;
        // ͷ�ڵ�ָ���µ��½ڵ�
        p1->next = p2;
        p1 = p2;
        p2 = (linklist *) malloc(LEN);
        scanf("%ld,%f", &p2->num, &p2->score);
    }
    p1->next = nullptr;
    return l;
}

/**
 * ��ӡ����
 * @param l  linklist
 */
void sc(linklist *l) {
    linklist *p;
    cout << endl;
    cout << "�ɼ���" << endl;
    //  printf("\n�ɼ���:\n", n);
    p = l->next;
    while (p != nullptr) {
        printf("%ld��%5.1f\n", p->num, p->score);
        // ָ������ƶ�
        p = p->next;
    }
}

/**
 * ɾ������Ľڵ�
 * @param l linklist
 * @param num long
 * @return linklist
 */
linklist *del(linklist *l, long num) {
    // ����ͷ�ڵ�
    linklist *header = l;
    // ����ڵ�
    linklist *p = l->next;
    // ɾ���Ľڵ�
    linklist *delNode;
    while (p != nullptr && p->num != num) {
        p = p->next;
        header = header->next;
    }
    if (p == nullptr) {
        return nullptr;
    }
    header->next = p->next;
    delNode = p;
    delete delNode;
    n--;
    return l;
}

/**
 * ���������ڵ�(β�巨)
 * @param l linklist
 * @param stud linklist
 * @return linklist
 */
linklist *insert(linklist *l, linklist *stud) {
    linklist *head = l;
    linklist *p = stud;
    p->next = head->next;
    head->next = p;
    n++;
    return l;
}

/**
 * ��ȡ���ֵ����Сֵ��ƽ��ֵ
 * @param l linklist
 * @return int
 */
int max_min_ave(linklist *l) {
    linklist *p;
    p = l->next;
    if (p == nullptr) {
        printf("����Ϊ�գ�");
    }
    int max = INT_MIN;
    while (p != nullptr) {
        if (p->score > max) {
            max = p->score;
        }
        p = p->next;
    }
    printf("��߳ɼ�Ϊ%d��\n", max);
    p = l->next;
    int min = INT_MAX;
    while (p != nullptr) {
        if (p->score < min) {
            min = p->score;
        }
        p = p->next;
    }
    printf("��ͳɼ�Ϊ%d��\n", min);
    double sum = 0;
    p = l->next;
    while (p != nullptr) {
        sum += p->score;
        p = p->next;
    }
    printf("ƽ���ɼ�Ϊ��%.2f��\n", (sum / n));
    return 0;
}

/**
 * ��������
 * @param L linklist
 */
void reverList(linklist *l) {
    if (l->next == nullptr) {
        return;
    }
    linklist *pre = nullptr;
    linklist *cur = l->next;
    linklist *next;
    while (cur) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    l->next = pre;
}

#endif //C__DATASTRUCTURES_LINKLIST_H
