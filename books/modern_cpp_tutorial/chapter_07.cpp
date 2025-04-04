#include "chapter_07.h"
#include <bits/stdc++.h>
using namespace std;

// 并行与并发
int main(void) {

    Paragraph("7.1 std::thread");
    test_thread();

    Paragraph("7.2 互斥量和临界区");
    // lock_guard 和 unique_lock 都是 C++ 提供的 RAII 机制互斥锁

    // lock_guard 是不可移动的，只能通过构造函数初始化 和 析构函数销毁
    // unique_lock 是可移动的，可以拷贝，赋值，移动，支持超时，手动解锁的功能
    // 可以去看类定义。

    // unique_lock 提供更多的功能，所以有更多的开销
    // 也称 lock_guard 是轻锁，unique_lock 是重锁

    test_lock_guard();
    test_unique_lock();

    Paragraph("7.3 期物");
    // 用于在一个线程中获取另一个线程执行的结果
    test_future();

    Paragraph("7.4 条件变量");
    // 用于解决死锁问题，如果线程在等待某个条件为真，且是死循环等待，
    // 那么其它线程就无法访问临界区来使这个条件为真，导致死锁
    // 本质上就是一直拿着锁不让其它人访问
    test_condition();

    Paragraph("7.5 原子操作与内存模型");
    test_volatile();

    Paragraph("7.5.1 原子操作");
    // 互斥锁是操作系统提供的功能，编译为 CPU 指令时添加系统调用指令实现互斥
    // 对于一个变量使用如此复杂的手段有些小题大做了

    // 现代 CPU 提供了 CPU 指令级的原子操作，在多线程共享变量的问题上，
    // 引入 atomic 模板，将原子操作从一组指令最小化到单个 CPU 指令
    test_atomic();

    Paragraph("7.5.2 一致性模型");
    // 由于对于一个变量进行原子修改导致多个线程在该变量上是串行的，达不到并行的要求
    // 所以可以减弱原子操作在进程间的同步条件，引入一致性模型来进行分析

    // 一致性模型将多线程比作分布式系统中，各节点的通讯，通讯是需要时间的
    // 所以如果有一个线程修改了变量（修改需要时间），而另一个线程再读取时，看到的还是之前的值
    // 1. 线性一致性：
    //       又称强一致性或原子一致性，要求每一次读操作都能读到最近一次修改的结果
    //       且线程的操作顺序与全局时钟下的顺序是一致的
    //       如：T1 先修改为 1，T2 再修改为 2，T1 读取到的值必须是 1
    // 2. 顺序一致性：
    //       每一次读操作都能读到最近一次的修改，但线程的操作顺序不要求与全局时钟下顺序一致
    //       如：(T1 先修改为 1，T2 再修改为 2)，T1 再修改为 3，
    //           此时 T2 读到的值必须是 2, 前面括号里修改的顺序可以交换
    // 3. 因果一致性：
    //       只需要有因果的操作顺序得到保障即可
    //       如：T1 需要先给 a 赋值, T1 再给 b 赋值，T2 需要求 a + b 的值
    //           赋值顺序不要求，求和必须在最后
    // 4. 最终一致性：只要某个操作在未来某个时间节点上能被观察到即可
    //       如：T1 赋值为 3，T1 赋值为 4，T2 一直查询，只要能读到 4 就行

    Paragraph("7.5.4 内存顺序");
    // C++11 为原子操作 atomic 定义了 6 种不同的内存顺序选项 std::memory_order
    // 表达了 4 种多线程间的同步模型
    // 此部分涉及比较深，一般对原子操作用默认行为即可
    // 以后如果有此块知识的涉及，可以再深入研究一下

    return 0;
}
