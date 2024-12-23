#include "in.h"

// 5.2 shared_ptr

void test_shared_ptr1() {

    auto foo = [](auto &i) { // 引用指针对象，只有一个指向资源
        (*i)++;
        cout << i.use_count() << endl;
    };

    auto foo2 = [](auto i) { // 拷贝指针对象，有两个指针指向资源
        (*i)++;
        cout << i.use_count() << endl;
    };

    auto pointer = make_shared<int>(10);
    foo(pointer);
    foo2(pointer);
    cout << *pointer << endl;
}

void test_shared_ptr2() {
    auto p1 = make_shared<int>(10);
    auto p2 = p1;      // 引用计数 +1
    auto p3 = p2;      // 引用计数 +1
    int *p = p1.get(); // 获取原始指针，不增加计数
    cout << "p1: " << p1.use_count() << ", p2: " << p2.use_count()
         << ", p3: " << p3.use_count() << endl;

    p2.reset(); // 减少引用计数 且 p2 更新为 0
    cout << "p1: " << p1.use_count() << ", p2: " << p2.use_count()
         << ", p3: " << p3.use_count() << endl;
}

void test_unique_ptr1() {
    auto p1 = make_unique<int>(10);
    // auto p2 = p1; // invalid
    auto p2 = std::move(p1);
    if (p1) {
        cout << *p1 << endl;
    } else {
        cout << "p1 is null" << endl;
    }

    if (p2) {
        cout << *p2 << endl;
    } else {
        cout << "p2 is null" << endl;
    }
}

struct B;
struct A {
    shared_ptr<B> p;
    ~A() { cout << "A 销毁" << endl; }
};

struct B {
    shared_ptr<A> p;
    ~B() { cout << "B 销毁" << endl; }
};

struct D;
struct C {
    char c = 'C';
    weak_ptr<D> p;
    ~C() { cout << "C 销毁" << endl; }
};

struct D {
    char d = 'D';
    weak_ptr<C> p;
    ~D() { cout << "D 销毁" << endl; }
};

void test_weak_ptr1() {
    auto a = make_shared<A>();
    auto b = make_shared<B>();
    a->p = b;
    b->p = a;
    // 退出作用域后，a 和 b 对象指向的内存区域计数不为 0，造成了内存泄露
}

void test_weak_ptr2() {
    auto c = make_shared<C>();
    auto d = make_shared<D>();
    c->p = d;
    d->p = c;
    // 不会增加引用计数，当释放指针时，最后对象会释放
    cout << c->p.expired() << endl; // 返回指向的资源是否被释放

    // weak_ptr 没有 * 和 -> 运算符，不能对资源进行操作
    // 使用 lock 可以在资源没有释放前返回 shared_ptr 指针，进而访问原始资源
    std::shared_ptr<D> t = c->p.lock();
    cout << t->d << endl;

    cout << c->p.use_count() << endl;
}
