#include <bits/stdc++.h>
using namespace std;

// 整体架构：生产者线程，任务队列，消费者线程
// 生产者线程用于向任务队列中添加任务
// 消费者线程用于在任务队列中取任务

// 单生产者多消费者
template <typename T> class BlockingQueue {
  public:
    BlockingQueue(bool nonblock = false) : m_nonblock(nonblock) {}

    void Push(const T &value) {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_queue.push(value);
        m_not_empty.notify_one();
    }

    bool Pop(T &value) {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_not_empty.wait(lock,
                         [this] { return !m_queue.empty() || m_nonblock; });
        if (m_queue.empty()) {
            return false;
        }

        value = m_queue.front();
        m_queue.pop();
        return true;
    }

    void Cancel() {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_nonblock = true;
        m_not_empty.notify_all();
    }

  private:
    bool m_nonblock{};
    std::mutex m_mutex;
    std::condition_variable m_not_empty;
    std::queue<T> m_queue;
};

// 双缓冲区队列：生产者队列和消费者队列
// 避免消费者线程和生产者线程发生碰撞
// 当消费者队列中元素为空时，将两个队列进行交换
template <typename T> class BlockingQueuePro {
  public:
    BlockingQueuePro(bool nonblock = false) : m_nonblock(nonblock) {}

    void Push(const T &value) {
        std::lock_guard<std::mutex> lock(m_producer_mutex);
        m_producer_queue.push(value);
        m_not_empty.notify_one();
    }

    bool Pop(T &value) {
        std::unique_lock<std::mutex> lock(m_consumer_mutex);
        if (m_consumer_queue.empty() && SwapQueue() == 0) {
            return false;
        }

        value = m_consumer_queue.front();
        m_consumer_queue.pop();
        return true;
    }

    void Cancel() {
        std::lock_guard<std::mutex> lock(m_producer_mutex);
        m_nonblock = true;
        m_not_empty.notify_all();
    }

  private:
    int SwapQueue() {
        std::unique_lock<std::mutex> lock(m_producer_mutex);
        m_not_empty.wait(
            lock, [this] { return !m_producer_queue.empty() || m_nonblock; });

        std::swap(m_producer_queue, m_consumer_queue);
        return m_consumer_queue.size();
    }

    bool m_nonblock{};
    std::mutex m_producer_mutex;
    std::mutex m_consumer_mutex;
    std::condition_variable m_not_empty;
    std::queue<T> m_producer_queue;
    std::queue<T> m_consumer_queue;
};

class ThreadPool {
  public:
    explicit ThreadPool(int num_threads) {
        for (size_t i = 0; i < num_threads; ++i) {
            m_workers.emplace_back([this]() -> void { Worker(); });
        }
    }

    ~ThreadPool() {
        m_task_queue.Cancel();
        for (auto &worker : m_workers) {
            if (worker.joinable()) {
                worker.join();
            }
        }
    }

    template <typename F, typename... Args> void Post(F &&f, Args &&...args) {
        // std::bind 的结果统一为 std::function<void> 类型，
        // 可以放在同一类型的队列中
        auto task = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
        m_task_queue.Push(task);
    }

  private:
    void Worker() {
        while (true) {
            std::function<void()> task;
            if (!m_task_queue.Pop(task)) {
                break;
            }
            task();
        }
    }

    BlockingQueue<std::function<void()>> m_task_queue; // 任务队列
    // BlockingQueuePro<std::function<void()>> m_task_queue; // 任务队列
    std::vector<std::thread> m_workers;
};

int main(void) {
    auto func = [](int a, int b, int c) {
        cout << "a: " << a << ", b: " << b << ", c: " << c << endl;
    };

    ThreadPool pool(20);
    for (int i = 0; i < 10; ++i) {
        pool.Post(func, i, i + 1, i + 2);
    }

    return 0;
}
