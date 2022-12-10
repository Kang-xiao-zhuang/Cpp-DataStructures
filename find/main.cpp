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

    if ((i = BinSearch(R, n, k)) != -1) {
        printf("元素%d的位置是%d\n", k, i);
    } else {
        printf("元素%d不在表中\n", k);
    }

    printf("\n");
}
