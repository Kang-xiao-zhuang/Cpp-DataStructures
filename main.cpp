//#include <stdio.h>
//
//#define MaxSize 50
//typedef int ElemType;
//typedef struct {
//    int data[MaxSize];
//    int length;
//} SqList;
//
//// 插入排序
//void InsertSort(SqList *L) {
//    int i, j;
//    for (i = 2; i <= L->length; i++) {
//        // 插入到有序子表
//        if (L->data[i] < L->data[i - 1]) {
//            // 待插入的记录暂存到监视哨中
//            L->data[0] = L->data[i];
//            // data[i-1] 后移
//            L->data[i] = L->data[i - 1];
//            // 从后向前寻找插入位置
//            for (j = i - 2; L->data[0] < L->data[j]; j--) {
//                // 记录逐个后移，直到找到插入位置
//                L->data[j + 1] = L->data[j];
//            }
//            // 将data[0]即原data[i]，插入到正确位置
//            L->data[j + 1] = L->data[0];
//        }
//    }
//}
//
//// 冒泡排序
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
//    // 用子表的第一个记录做枢轴记录
//    L->data[0] = L->data[low];
//    // 枢轴记录关键字保存在pivotkey中
//    int pivotkey = L->data[low];
//    // 从表的两端交替向中间扫描
//    while (low < high) {
//        while (low < high && L->data[high] >= pivotkey) {
//            --high;
//        }
//        // 将比枢轴记录小的记录移到低端
//        L->data[low] = L->data[high];
//        while (low < high && L->data[low] <= pivotkey) {
//            ++low;
//        }
//        // 将比枢轴记录大的记录移到高端
//        L->data[high] = L->data[low];
//    }
//    L->data[low] = L->data[0];
//    return low;
//}
//
//void QuickSort(SqList *L, int low, int high) {
//    if (low < high) {
//        // 将L.data[low,high] 一分为二  pivotloc是枢轴位置
//        int pivotloc = Partition(L, low, high);
//        // 对左子表递归排序
//        QuickSort(L, low, pivotloc - 1);
//        // 对右子表递归排序
//        QuickSort(L, pivotloc + 1, high);
//    }
//}
//
//// 快速排序
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
//    printf("\n待排序数据为:\n");
//    for (i = 1; i < 10; i++) {
//        s.data[i] = a[i - 1];
//        printf("%d  ", a[i - 1]);
//    }
//    s.length = i - 1;
//    printf("\n1,插入排序\n2,冒泡排序\n3,快速排序\n");
//    printf("请输入序号\n");
//    scanf("%d", &k);
//    switch (k) {
//        case 1:
//            //在此处调用插入函数
//            InsertSort(&s);
//            break;
//        case 2:
//            //在此处调用冒泡函数
//            BubbleSort(&s);
//            break;
//        case 3:
//            //在此处调用快速函数
//            QuickSort(&s);
//            break;
//        default:
//            printf("No function which you select.\n");
//    }
//    printf("\n排序后的记录为\n");
//    for (i = 1; i < 9; i++)
//        printf("%d  ", s.data[i]);
//
//    printf("\n");
//
//}
