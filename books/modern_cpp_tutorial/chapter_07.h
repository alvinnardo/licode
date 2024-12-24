#include "in.h"
#include <mutex>
#include <thread>

void test_thread() {
    std::thread t([](int t) { cout << "hello: " << t << endl; }, 10);
    t.join();
}

void test_thread2() {
    // 不要直接调用 lock() 和 unlock()
    // 使用 RAII 机制的 std::lock_guard
    std::mutex m_mutex;
    std::lock_guard<std::mutex> lock(m_mutex);

    // 执行竞争操作

    // 退出作用域，锁自动释放
}
