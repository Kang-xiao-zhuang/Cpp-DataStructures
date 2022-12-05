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
