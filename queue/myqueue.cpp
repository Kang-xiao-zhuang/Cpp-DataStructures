//
// Created by Administrator on 2022/12/6.
//
#include "myqueue.h"

int main() {
    myqueue q{};
    stack s{};
    char a[10];
    initQueue(&q);
    initStack(&s);

    useStack(s, a);
    //useStackAnDQueue(q, s, a);

    //利用栈和队列的操作特点写一段代码

    //判别读入的一个以’@’为结束符的字符序列是否是“回文”。
}
