#include <stdio.h>
#include <stdlib.h>

#define NULL 0
#define LEN sizeof(LinkList)


//����Ķ��壺
typedef struct LNode {
    long num;          //ѧ��
    float score;      //�ɼ�
    struct LNode *next;   //ָ����
} LNode, LinkList;

// ����ĳ���
int n;

/**
 *
 * @return  LinkList
 */
LinkList *creat(void) {
    // ��������ָ��
    LinkList *p1, *p2;
    LinkList *L;
    n = 0;
    //ͷ�ڵ� ���뿪���ڴ�ռ�
    L = p1 = (LinkList *) malloc(LEN);
    p2 = (LinkList *) malloc(LEN);
    //����ѧ�š��ɼ�
    scanf("%ld,%f", &p2->num, &p2->score);
    //ѧ��Ϊ0ʱ��¼�����
    while (p2->num != 0) {
        // ���ȼ�1
        n++;
        // ͷ�ڵ�ָ���µ��½ڵ�
        p1->next = p2;
        p1 = p2;
        p2 = (LinkList *) malloc(LEN);
        scanf("%ld,%f", &p2->num, &p2->score);
    }
    p1->next = NULL;
    return (L);
}

/**
 * �������ѧ����ѧ�źͳɼ�
 * @param L  LinkList
 */
void sc(LinkList *L) {
    LinkList *p;
    printf("\n�ɼ���:\n", n);
    p = L->next;
    while (p != NULL) {
        printf("%ld��%5.1f\n", p->num, p->score);
        // ָ������ƶ�
        p = p->next;
    }
}

/**
 * ɾ��ָ��ѧ�ŵĽ��
 * @param L  LinkList
 * @param num  ѧ��
 * @return  LinkList
 */
LinkList *del(LinkList *L, long num) {
//�ڴ˴����ɾ����������
    // ����ͷ�ڵ�
    LNode *header = L;
    // ����ڵ�
    LNode *p = L->next;
    // ɾ���Ľڵ�
    LNode *delNode;
    while (p != NULL && p->num != num) {
        p = p->next;
        header = header->next;
    }
    if (p == NULL) {
        return NULL;
    }
    header->next = p->next;
    delNode = p;
    delete delNode;
    n--;
    return L;
}

/**
 * ����stud��㣬�ɲ���ǰ�巨
 * @param L  LinkList
 * @param stud  LinkList
 * @return  LinkList
 */
LinkList *insert(LinkList *L, LinkList *stud) {
//�ڴ˴���ɲ��뺯������
    LNode *head = L;
    LNode *p = stud;
    p->next = head->next;
    head->next = p;
    n++;
    return L;
}

/**
 * �ڴ˴��������߳ɼ�����ͳɼ���ƽ���ɼ��ĺ�������
 * @param L  LinkList
 * @return  int
 */
int max_min_ave(LinkList *L) {
    LinkList *p;
    p = L->next;
    if (p == NULL) {
        printf("����Ϊ�գ�");
    }
    int max = INT_MIN;
    while (p != NULL) {
        if (p->score > max) {
            max = p->score;
        }
        p = p->next;
    }
    printf("��߳ɼ�Ϊ%d��\n", max);
    p = L->next;
    int min = INT_MAX;
    while (p != NULL) {
        if (p->score < min) {
            min = p->score;
        }
        p = p->next;
    }
    printf("��ͳɼ�Ϊ%d��\n", min);
    double sum = 0;
    p = L->next;
    while (p != NULL) {
        sum += p->score;
        p = p->next;
    }
    printf("ƽ���ɼ�Ϊ��%.2f��\n", (sum / n));
    return 0;
}

/**
 * ���ú���
 * @param L  LinkList
 */
void NiZhiList_L(LinkList *L) {
    if (L->next == nullptr) {
        return;
    }
    LinkList *pre = NULL;
    LinkList *cur = L->next;
    LinkList *next;
    while (cur) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    L->next = pre;
}

int main() {
    LinkList *L, *stu;

    long del_num;
    /* 200,100
        20,30
        */
    /**
     *  1,90
        2,60
        3,80
        4,85
        0,0
     */
    printf("��������:\n");
    L = creat();
    sc(L);
    while (true) {
        printf("\n������Ҫɾ����ѧ��:");
        scanf("%ld", &del_num);
        if (del_num == 0) {
            break;
        }
        del(L, del_num);
        //1.�ڴ˴�����ɾ���������������ɾ��������������sc(head)�������
        sc(L);
    }


    //2.�ڴ˴����ò��뺯��������������������������sc(head)�������
    while (true) {
        printf("\n������Ҫ�����ѧ�źͳɼ�");
        stu = (LinkList *) malloc(LEN);
        scanf("%ld,%f", &stu->num, &stu->score);
        if (stu->num == 0 && stu->score == 0) {
            break;
        }
        insert(L, stu);
        sc(L);
    }
    //3.�ڴ˴���������߳ɼ�����ͳɼ���ƽ���ɼ��ĺ���
    printf("������Ϊ��%d\n", n);
    max_min_ave(L);
    //4.�ڴ˴��������ú��������������������
    printf("��ת��������\n");
    NiZhiList_L(L);
    sc(L);
}