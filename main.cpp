//#include <stdio.h>
//
//#define MaxSize 50
//typedef int ElemType;
//typedef struct {
//    int data[MaxSize];
//    int length;
//} SqList;
//
//// ��������
//void InsertSort(SqList *L) {
//    int i, j;
//    for (i = 2; i <= L->length; i++) {
//        // ���뵽�����ӱ�
//        if (L->data[i] < L->data[i - 1]) {
//            // ������ļ�¼�ݴ浽��������
//            L->data[0] = L->data[i];
//            // data[i-1] ����
//            L->data[i] = L->data[i - 1];
//            // �Ӻ���ǰѰ�Ҳ���λ��
//            for (j = i - 2; L->data[0] < L->data[j]; j--) {
//                // ��¼������ƣ�ֱ���ҵ�����λ��
//                L->data[j + 1] = L->data[j];
//            }
//            // ��data[0]��ԭdata[i]�����뵽��ȷλ��
//            L->data[j + 1] = L->data[0];
//        }
//    }
//}
//
//// ð������
//void BubbleSort(SqList *L) {
//    int i, j;
//    for (i = 1; i <= L->length; i++) {
//        for (j = 1; j <= L->length - i; j++) {
//            if (L->data[j] > L->data[j + 1]) {
//                int temp = L->data[j];
//                L->data[j] = L->data[j + 1];
//                L->data[j + 1] = temp;
//            }
//        }
//    }
//}
//
//int Partition(SqList *L, int low, int high) {
//    // ���ӱ�ĵ�һ����¼�������¼
//    L->data[0] = L->data[low];
//    // �����¼�ؼ��ֱ�����pivotkey��
//    int pivotkey = L->data[low];
//    // �ӱ�����˽������м�ɨ��
//    while (low < high) {
//        while (low < high && L->data[high] >= pivotkey) {
//            --high;
//        }
//        // ���������¼С�ļ�¼�Ƶ��Ͷ�
//        L->data[low] = L->data[high];
//        while (low < high && L->data[low] <= pivotkey) {
//            ++low;
//        }
//        // ���������¼��ļ�¼�Ƶ��߶�
//        L->data[high] = L->data[low];
//    }
//    L->data[low] = L->data[0];
//    return low;
//}
//
//void QuickSort(SqList *L, int low, int high) {
//    if (low < high) {
//        // ��L.data[low,high] һ��Ϊ��  pivotloc������λ��
//        int pivotloc = Partition(L, low, high);
//        // �����ӱ�ݹ�����
//        QuickSort(L, low, pivotloc - 1);
//        // �����ӱ�ݹ�����
//        QuickSort(L, pivotloc + 1, high);
//    }
//}
//
//// ��������
//void QuickSort(SqList *L) {
//    QuickSort(L, 1, L->length);
//}
//
//
//int main() {
//
//    int a[] = {52, 49, 80, 36, 14, 58, 61, 23, 97, 75};
//    int i, k;
//    SqList s;
//    printf("\n����������Ϊ:\n");
//    for (i = 1; i < 10; i++) {
//        s.data[i] = a[i - 1];
//        printf("%d  ", a[i - 1]);
//    }
//    s.length = i - 1;
//    printf("\n1,��������\n2,ð������\n3,��������\n");
//    printf("���������\n");
//    scanf("%d", &k);
//    switch (k) {
//        case 1:
//            //�ڴ˴����ò��뺯��
//            InsertSort(&s);
//            break;
//        case 2:
//            //�ڴ˴�����ð�ݺ���
//            BubbleSort(&s);
//            break;
//        case 3:
//            //�ڴ˴����ÿ��ٺ���
//            QuickSort(&s);
//            break;
//        default:
//            printf("No function which you select.\n");
//    }
//    printf("\n�����ļ�¼Ϊ\n");
//    for (i = 1; i < 9; i++)
//        printf("%d  ", s.data[i]);
//
//    printf("\n");
//
//}
