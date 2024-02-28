#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;


int main(void)
{
    // std::thead 只支持移动构造函数，不支持拷贝构造函数
    auto get = []() { cout << 1 << endl; };

    std::thread t1{get}; // 在这里创建之后，就开始执行了
    sleep(10);

    // std::thread t2 = t1; // 拷贝构造，报错
    std::thread t2(std::move(t1)); // 移动构造，将控制权交给 t2
    t2.join();

    return 0;
}
