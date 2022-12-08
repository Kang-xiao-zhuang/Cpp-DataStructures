### 1.设计BF算法（参考课本92页算法4.1），完成如下功能：
1）建立目标串s=“abcabcabdabba”和模式串t=“abcabd”。
2）采用BF算法求t在s中的位置。
运行结果如图所示：
![在这里插入图片描述](https://img-blog.csdnimg.cn/4fcd865505484511b37ae9f6208c6391.png)



**mystring.h**

```cpp
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
```
**mystring.cpp**

```cpp
//
// Created by Administrator on 2022/12/8.
//
#include "mystring.h"
#include <iostream>

using namespace std;

int main() {
    mystring s{}, t{};
    strAssign(s, "abcabcabdabba");
    strAssign(t, "abcabd");

    cout << "串s:";
    dispStr(s);
    cout << "串t:";
    dispStr(t);

    cout << "简单匹配P算法:" << endl;
    cout << "t在s中的位置=" << index(s, t) << endl;

    //cout<<"KMP匹配P算法:"<<endl;
    //cout<<"t在s中的位置="<<Index_kmp(s,t)<<endl;
}
```

**运行截图**
![在这里插入图片描述](https://img-blog.csdnimg.cn/ed62ad89003b4cd4b65fbb06945df980.png)
