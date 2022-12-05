# 栈和递归

## 1. 利用栈的存储原理，补充完成数制转换程序

运行结果如图所示：
![在这里插入图片描述](https://img-blog.csdnimg.cn/b0f986ba431a418493d92fa019e887b1.png)
**完整代码**

```cpp
#define stackSize 10
const int MAX_SIZE = 100;

#include <malloc.h>
#include <iostream>
#include<cstdio>
#include<cstdlib>
#include <stack>

using namespace std;

class mystack {
public:
    int *base;
    int *top;
    int stacksize;
};

/**
 * 初始化栈
 * @param s  mystack
 */
void initStack(mystack *s) {
    s->base = (int *) malloc(20 * sizeof(int));

    s->top = s->base;

    s->stacksize = 20;
}

/**
 * 入栈
 * @param s mystack
 * @param e 元素
 */
void push(mystack *s, int e) {
    if (s->top - s->base >= s->stacksize) {
        s->base = (int *) realloc(s->base, ((s->stacksize + stackSize)) * sizeof(int));
        if (!s->base) exit(0);
        s->top = s->base + s->stacksize;
        s->stacksize += stackSize;
    }
    *(s->top)++ = e;
}

/**
 * 弹栈
 * @param s mystack
 */
void pop(mystack *s) {
    int e;
    if (s->top == s->base) return;
    e = *--s->top;
    cout << e;
}

/**
 * 栈是否为空
 * @param s mystack
 * @return bool
 */
bool isEmpty(mystack *s) {
    if (s->top == s->base) {
        return true;
    } else {
        return false;
    }
}

/**
 * 10进制转换成2进制
 * @param N 大小
 */
void conversion(int N) {
    mystack s{};
    initStack(&s);
    do {
        push(&s, N & 1);
    } while (N >>= 1);
    while (!isEmpty(&s)) {
        pop(&s);
    }
}

#include "mystack.h"

#include <iostream>

using namespace std;

int main() {

    int x;
    cout << endl;
    cout << "请输入一个十进制数据:";
    cin >> x;
    cout << endl;
    cout << "转换成二进制为:";
    conversion(x);
    cout << endl;

}
```
**运行截图**
![在这里插入图片描述](https://img-blog.csdnimg.cn/3918fa339af1494386e2a068b60bf91a.png)


## 2. 实现汉诺塔算法

运行结果如图所示：
![在这里插入图片描述](https://img-blog.csdnimg.cn/1f5889e6811d42b2a689f71814422be2.png)
**完整代码**

```cpp
#define _CRT_SECURE_NO_WARNINGS
/**
 * 移动方法
 * @param x char
 * @param n int
 * @param y char
 */
void move(char x, int n, char y) {
    cout << "第" << n << "个   " << x << "-->" << y << endl;
}

/**
 * 汉诺塔代码
 * @param n int
 * @param x char
 * @param y char
 * @param z char
 */
void hanoi(int n, char x, char y, char z) {
    if (n == 1) {
        move(x, 1, y);
    } else {
        hanoi(n - 1, x, z, y);
        move(x, n, z);
        hanoi(n - 1, y, x, z);
    }

}

#include "mystack.h"

#include <iostream>

using namespace std;

int main() {

    // 汉诺塔实验
    int m;
    printf("请输入方块数目:");
    scanf("%d", &m);
    hanoi(m, 'X', 'Y', 'Z');
    
}

```
**运行截图**
![在这里插入图片描述](https://img-blog.csdnimg.cn/235c0569021342a78f633fa2248184a6.png)


## 3. 写一个程序将读入的一个以“@”为结束符的字符序列逆序输出，如输入“asdf@”，则输出“fdsa”。要求使用栈结构完成。

运行结果如图所示：

![在这里插入图片描述](https://img-blog.csdnimg.cn/248b6c74bc2143b98b30210636850b1d.png)
**完整代码**

**自定义结构体**

```cpp
#include <stack>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

const int MAX_SIZE = 100;

// char类型的栈
struct Stack {
    char *base;
    char *top;
    int stacksize;

    Stack() { InitStack(MAX_SIZE); }

    Stack(int i) { InitStack(i); }

    void InitStack(int);

    bool Push(char const &elem);

    bool Pop();

    bool Empty() const;

    char &GetTop() const;

    ~Stack() { delete base; }
};

void Stack::InitStack(int i) {
    base = new char[i];
    top = base;
    stacksize = i;
}

bool Stack::Push(char const &elem) {
    if (top - base == stacksize)
        return false;
    *top++ = elem;
    return true;
}

bool Stack::Pop() {
    if (top == base)
        return false;
    --top;
    return true;
}

char &Stack::GetTop() const {
    if (top != base)
        return *(top - 1);
}

bool Stack::Empty() const {
    if (top == base) return true;
    else return false;
}

void reverse(string &s) {
    Stack stack;
    for (int i = 0; i < s.length() - 1; i++) {
        stack.Push(s[i]);
    }
    s = "";
    while (!stack.Empty()) {
        s += stack.GetTop();
        stack.Pop();
    }
}
#include "mystack.h"

#include <iostream>

using namespace std;

int main() {
    
    // 自己定义结构体实现字符串判断
    string s;
    cin >> s;
    if (s.back() == '\@')
        reverse(s);
    cout << s << endl;
    
}
```
**库函数栈**

```java
/**
 * 使用c++库函数实现字符串判断
 */
void strCheck(stack<char> charstack) {

    string s;
    cout << "输入一串字符以@结尾" << endl;
    cin >> s;
    if (s.back() == '\@') {
        for (int i = 0; i < s.length() - 1; i++) {
            charstack.push(s[i]);
        }
        s = "";
        //拼接
        while (!charstack.empty()) {
            s += charstack.top();
            charstack.pop();
        }
    }
    cout << "逆序字符串" << endl;
    cout << s << endl;
}
#include "mystack.h"

#include <iostream>

using namespace std;

int main() {
    
    // 库函数实现字符串判断
    stack<char> charstack;
    strCheck(charstack);
    
}
```

**运行截图**
![在这里插入图片描述](https://img-blog.csdnimg.cn/449f619d370c48598164291603595469.png)

**完整代码**

**mystack.h**

```cpp
//
// Created by Administrator on 2022/12/5.
//

#ifndef C__DATASTRUCTURES_MYSTACK_H
#define C__DATASTRUCTURES_MYSTACK_H
#define stackSize 10
const int MAX_SIZE = 100;

#include <malloc.h>
#include <iostream>
#include<cstdio>
#include<cstdlib>
#include <stack>

using namespace std;

class mystack {
public:
    int *base;
    int *top;
    int stacksize;
};

/**
 * 初始化栈
 * @param s  mystack
 */
void initStack(mystack *s) {
    s->base = (int *) malloc(20 * sizeof(int));

    s->top = s->base;

    s->stacksize = 20;
}

/**
 * 入栈
 * @param s mystack
 * @param e 元素
 */
void push(mystack *s, int e) {
    if (s->top - s->base >= s->stacksize) {
        s->base = (int *) realloc(s->base, ((s->stacksize + stackSize)) * sizeof(int));
        if (!s->base) exit(0);
        s->top = s->base + s->stacksize;
        s->stacksize += stackSize;
    }
    *(s->top)++ = e;
}

/**
 * 弹栈
 * @param s mystack
 */
void pop(mystack *s) {
    int e;
    if (s->top == s->base) return;
    e = *--s->top;
    cout << e;
}

/**
 * 栈是否为空
 * @param s mystack
 * @return bool
 */
bool isEmpty(mystack *s) {
    if (s->top == s->base) {
        return true;
    } else {
        return false;
    }
}

/**
 * 10进制转换成2进制
 * @param N 大小
 */
void conversion(int N) {
    mystack s{};
    initStack(&s);
    do {
        push(&s, N & 1);
    } while (N >>= 1);
    while (!isEmpty(&s)) {
        pop(&s);
    }
}

/**
 * 移动方法
 * @param x char
 * @param n int
 * @param y char
 */
void move(char x, int n, char y) {
    cout << "第" << n << "个   " << x << "-->" << y << endl;
}

/**
 * 汉诺塔代码
 * @param n int
 * @param x char
 * @param y char
 * @param z char
 */
void hanoi(int n, char x, char y, char z) {
    if (n == 1) {
        move(x, 1, y);
    } else {
        hanoi(n - 1, x, z, y);
        move(x, n, z);
        hanoi(n - 1, y, x, z);
    }

}

// char类型的栈
struct Stack {
    char *base;
    char *top;
    int stacksize;

    Stack() { InitStack(MAX_SIZE); }

    Stack(int i) { InitStack(i); }

    void InitStack(int);

    bool Push(char const &elem);

    bool Pop();

    bool Empty() const;

    char &GetTop() const;

    ~Stack() { delete base; }
};

void Stack::InitStack(int i) {
    base = new char[i];
    top = base;
    stacksize = i;
}

bool Stack::Push(char const &elem) {
    if (top - base == stacksize)
        return false;
    *top++ = elem;
    return true;
}

bool Stack::Pop() {
    if (top == base)
        return false;
    --top;
    return true;
}

char &Stack::GetTop() const {
    if (top != base)
        return *(top - 1);
}

bool Stack::Empty() const {
    if (top == base) return true;
    else return false;
}

void reverse(string &s) {
    Stack stack;
    for (int i = 0; i < s.length() - 1; i++) {
        stack.Push(s[i]);
    }
    s = "";
    while (!stack.Empty()) {
        s += stack.GetTop();
        stack.Pop();
    }
}

/**
 * 使用c++库函数实现字符串判断
 */
void strCheck(stack<char> charstack) {

    string s;
    cout << "输入一串字符以@结尾" << endl;
    cin >> s;
    if (s.back() == '\@') {
        for (int i = 0; i < s.length() - 1; i++) {
            charstack.push(s[i]);
        }
        s = "";
        //拼接
        while (!charstack.empty()) {
            s += charstack.top();
            charstack.pop();
        }
    }
    cout << "逆序字符串" << endl;
    cout << s << endl;
}

#endif //C__DATASTRUCTURES_MYSTACK_H
```

**mystack.cpp**

```java
//
// Created by Administrator on 2022/12/5.
//

#include "mystack.h"

#include <iostream>

using namespace std;

int main() {

    int x;
    cout << endl;
    cout << "请输入一个十进制数据:";
    cin >> x;
    cout << endl;
    cout << "转换成二进制为:";
    conversion(x);
    cout << endl;

    // 汉诺塔实验
    int m;
    printf("请输入方块数目:");
    scanf("%d", &m);
    hanoi(m, 'X', 'Y', 'Z');

    // 自己定义结构体实现字符串判断
    string s;
    cin >> s;
    if (s.back() == '\@')
        reverse(s);
    cout << s << endl;

    // 库函数实现字符串判断
    stack<char> charstack;
    strCheck(charstack);
}
```

