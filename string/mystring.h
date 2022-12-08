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
    //���������MaxSize���ַ��Ŀռ�
    char data[MaxSize];
};
/**
 * ��ʼ���ַ���
 * @param str  mystring
 * @param cstr char
 */
//strΪ�����Ͳ���
void strAssign(mystring &str, char cstr[]) {
    int i;
    for (i = 0; cstr[i] != '\0'; i++) {
        str.data[i + 1] = cstr[i];
    }
    str.data[0] = i;
}

/**
 * ��ӡ�ַ���
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
 * BF�㷨
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
            //�������ݵ��ϴλ���λ�õ���һ��λ��
            i = i - j + 2;
            //ģʽ�����ݵ���һ��λ��
            j = 1;
        }
    }
    if (t.data[j] == '\0') {
        //����T��S�е�һ�γ��ֵ�λ��
        return i - j + 1;
    } else {
        return 0;
    }
}
//int Index_kmp(SqString s, SqString t)
//KMP�㷨
//{


//}


#endif //C__DATASTRUCTURES_MYSTRING_H
