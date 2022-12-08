//
// Created by Administrator on 2022/12/8.
//

#ifndef C__DATASTRUCTURES_MYSTRING_H
#define C__DATASTRUCTURES_MYSTRING_H

#include <iostream>

#define MaxSize 100
using namespace std;

class mystring {
public:
    //定义可容纳MaxSize个字符的空间
    char data[MaxSize];
};
/**
 * 初始化字符串
 * @param str  mystring
 * @param cstr char
 */
//str为引用型参数
void strAssign(mystring &str, char cstr[]) {
    int i;
    for (i = 0; cstr[i] != '\0'; i++) {
        str.data[i + 1] = cstr[i];
    }
    str.data[0] = i;
}

/**
 * 打印字符串
 * @param str mystring
 */
void dispStr(mystring str) {
    int i;
    if (str.data[0] > 0) {
        for (i = 1; i <= str.data[0]; i++) {
            cout << str.data[i];
            // printf("%c", str.data[i]);
        }
        cout << endl;
    }
}

/**
 * BF算法
 * @param s mystring
 * @param t mystring
 * @return
 */
int index(mystring s, mystring t) {
    int i = 1, j = 1;
    //printf("%s", s.data);
    //printf("%s", t.data);
    //printf("\n");
    while (s.data[i] != '\0' && t.data[j]) {
        if (s.data[i] == t.data[j]) {
            i++;
            j++;
        } else {
            //主串回溯到上次回溯位置的下一个位置
            i = i - j + 2;
            //模式串回溯到第一个位置
            j = 1;
        }
    }
    if (t.data[j] == '\0') {
        //返回T在S中第一次出现的位置
        return i - j + 1;
    } else {
        return 0;
    }
}
//int Index_kmp(SqString s, SqString t)
//KMP算法
//{


//}


#endif //C__DATASTRUCTURES_MYSTRING_H
