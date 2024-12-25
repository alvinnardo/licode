#include "in.h"
#include <mutex>
#include <thread>

void test_thread() {
    std::thread t([](int t) { cout << "hello: " << t << endl; }, 10);
    t.join();
}

int val = 0;
void printVal(int new_val) {
    // 不要直接调用 lock() 和 unlock()
    // 使用 RAII 机制的 std::lock_guard
    std::mutex m_mutex;
    // c++ 保证所有栈对象在生命周期后会被销毁
    // 所以出现异常时，也会进行栈回溯，释放锁
    std::lock_guard<std::mutex> lock(m_mutex);

    // 执行竞争操作
    val = new_val;
    cout << val << endl;

    // 退出作用域，锁自动释放
}

void printVal2(int new_val) {
    std::mutex m_mutex;
    std::unique_lock<std::mutex> lock(m_mutex);

    val = new_val;
    cout << val << endl;

    // 手动释放锁
    lock.unlock();

    // 在此期间，val 变量没有上锁

    lock.lock();
    val += 1;
    cout << val << endl;
}

void test_lock_guard() {
    std::thread t1(printVal, 2), t2(printVal, 3);
    t1.join();
    t2.join();
}

void test_unique_lock() {
    std::thread t1(printVal, 2), t2(printVal, 3);
    t1.join();
    t2.join();
}

// 可以用于线程同步
void test_future() {
    // 使用 std::packaged_task 来封装一个任务
    std::packaged_task<string()> task([]() { return "hello world"; });
    // 获得 task 的期物
    std::future<string> result = task.get_future();
    std::thread(std::move(task)).detach(); // 在线程中执行 task
    cout << "waiting ..." << endl;
    result.wait();
    cout << "future is " << result.get() << endl;
}

void test_condition() {
    std::queue<int> products;
    // 使用 mutex 会让所有的线程串行执行
    // 如果想让消费者并行消费，则需要更小的粒度
    std::mutex m_mutex;
    std::condition_variable cv;
    bool end = false;

    // 生产者和消费者模型
    auto producer = [&]() {
        for (int i = 0; !end; i++) {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            std::unique_lock<std::mutex> lock(m_mutex);
            cout << "producing ... " << endl;
            products.emplace(i);
            if (i == 10) {
                end = true;
            }
            cv.notify_all();
        }
    };

    auto consumer = [&]() {
        while (true) {
            std::unique_lock<std::mutex> lock(m_mutex);
            while (products.empty()) {
                if (end) {
                    break;
                }
                cv.wait(lock);
            }

            if (products.empty() && end) {
                break;
            }
            cout << "consuming " << products.front() << endl;
            products.pop();
        }
    };

    std::thread p(producer), c[2];
    for (int i = 0; i < 2; i++) {
        c[i] = std::thread(consumer);
    }

    p.join();
    for (int i = 0; i < 2; i++) {
        c[i].join();
    }
}

void test_volatile() {
    // 书中给出，可能由于编译器优化导致指令重排，可能导致输出 b = 0
    // 进而引出对 a 的 CPU 指令级原子操作
    int a = 0;
    volatile int flag = 0;

    std::thread t1([&]() {
        while (!flag) {
        }

        int b = a;
        cout << "b = " << b << endl;
    });

    std::thread t2([&]() {
        a = 5;
        flag = 1;
    });

    t1.join();
    t2.join();
}

void test_atomic() {
    std::atomic<int> a = {0};

    // 原子操作取决于具体的 CPU 架构，使用 is_lock_free
    // 判断该原子类型是否支持原子操作
    cout << std::boolalpha << a.is_lock_free() << endl;
    std::thread t1([&]() {
        a.fetch_add(1); // 重载了 +
    });

    std::thread t2([&]() {
        a++;    // 等价 fetch_add
        a += 1; // 等价 fetch_add
    });

    t1.join();
    t2.join();
    cout << a << endl;
}
