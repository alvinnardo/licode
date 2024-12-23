#include "chapter_05.h"
#include <bits/stdc++.h>
using namespace std;

int main(void) {

    Paragraph("5.1 RAII 和 引用计数");
    // 对于动态分配的对象，进行引用计数
    // 当一个对象的引用计数减为零时，就自动删除指向的堆内存

    // RAII 资源获取即初始化，利用对象的生命周期机制
    // 离开作用域时释放资源

    Paragraph("5.2 shared_ptr");
    // 智能指针，记录多少个 shared_ptr 同时指向一个对象
    // 当引用计数变为 0 的时候将对象自动删除
    // 使用 make_shared 创建对象，其返回该对象类型的 shared_ptr 指针
    test_shared_ptr1();
    test_shared_ptr2();

    Paragraph("5.3 unique_ptr");
    // 独占的智能指针，禁止其他指针与其共享同一个对象，以保证代码安全
    test_unique_ptr1();

    Paragraph("5.4 weak_ptr");
    // 解决循环引用无法自动释放的问题
    // A 对象中有指向 B 的指针，B 对象中有指向 A 的指针
    // weak_ptr 不会增加引用计数
    test_weak_ptr1();
    test_weak_ptr2();


    return 0;
}
