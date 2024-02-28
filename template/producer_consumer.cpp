#include "circle_queue.h"
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

using intQueuePtr = std::shared_ptr<CircleQueue<int>>;
using stringQueuePtr = std::shared_ptr<CircleQueue<string>>;
class Producer {
  private:
    intQueuePtr &source_queue_ptr;
    int x = 0;

  public:
    // 数据全部生成完后，退出生产者
    Producer(intQueuePtr &ptr) : source_queue_ptr(ptr) {}
    void flow() {
        while (1) {
            x++;
            source_queue_ptr->push(x);

            if (x == 100) {
                break;
            }
        }
    }
};

class Parser {
  private:
    intQueuePtr &source_queue_ptr;
    stringQueuePtr &sink_queue_ptr;

  public:
    Parser(intQueuePtr &source_ptr, stringQueuePtr &sink_ptr)
        : source_queue_ptr(source_ptr), sink_queue_ptr(sink_ptr) {}
    void flow() {
        // 判断结束和判断为空有一个时序的关系，如果设置 finished 较晚，会卡在
        // pop() 中， 所以要也在 pop() 中判断是否 finished,
        // 退出后，让外面的逻辑结束
        while (
            !(source_queue_ptr->isFinished() && source_queue_ptr->isEmpty())) {
            auto tptr = source_queue_ptr->pop();
            if (!tptr) {
                continue;
            }

            // sleep(1); // 模拟解析慢
            auto tstr = std::to_string(*tptr) + "_x";
            sink_queue_ptr->push(tstr);
        }
    }
};

class Sinker {
  private:
    stringQueuePtr &sink_queue_ptr;

  public:
    Sinker(stringQueuePtr &ptr) : sink_queue_ptr(ptr) {}
    void flow() {
        while (!(sink_queue_ptr->isFinished() && sink_queue_ptr->isEmpty())) {
            auto tptr = sink_queue_ptr->pop();
            if (!tptr) {
                continue;
            }
            cout << "sink: " << *tptr << endl;
        }
    }
};

int main(void) {

    int thread_count = 3;
    // 创建两个队列
    intQueuePtr source_queue_ptr = make_shared<CircleQueue<int>>();
    stringQueuePtr sink_queue_ptr = make_shared<CircleQueue<string>>();

    // 创建三类对象
    auto producer = make_shared<Producer>(source_queue_ptr);
    std::vector<std::shared_ptr<Parser>> parser_vec;
    for (int i = 0; i < thread_count; i++) {
        parser_vec.push_back(
            make_shared<Parser>(source_queue_ptr, sink_queue_ptr));
    }
    auto sinker = make_shared<Sinker>(sink_queue_ptr);

    // 创建三类线程
    std::thread producer_thread([&]() { producer->flow(); });

    std::vector<std::thread> parser_thread_vec;
    for (int i = 0; i < thread_count; i++) {

        // 将函数和变量分开
        // 原地构造一个线程，接口是 std::thread{function_name, args}
        parser_thread_vec.emplace_back(
            [&](int idx) { parser_vec[idx]->flow(); }, i);

        // 以下方式也可以
        // parser_thread_vec.emplace_back(
        //     [i, parser_vec] { parser_vec[i]->flow(); });

        // 以下方式不可以
        // std::thread 只能移动不能拷贝，所以要避免使用拷贝构造函数
        // parser_thread_vec.push_back(std::thread{[&](int idx) { parser_vec[i]->flow(); }, i});

        // 另一种方式
        // std::thread th{[&](int idx) {parser_vec[idx]->flow();}, i};
        // 以下方式不可以，触发了拷贝构造函数
        // parser_thread_vec.push_back(th);

        // 以下方式可以，使用移动构造函数
        // parser_thread_vec.push_back(std::move(th));
    }
    std::thread sinker_thread([&]() { sinker->flow(); });

    // 等待线程依次执行完成
    producer_thread.join();
    source_queue_ptr->setFinished();

    for (int i = 0; i < thread_count; i++) {
        parser_thread_vec[i].join();
    }
    sink_queue_ptr->setFinished();

    sinker_thread.join();

    return 0;
}
