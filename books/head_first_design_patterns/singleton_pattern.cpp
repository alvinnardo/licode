#include <cassert>
#include <iostream>
using namespace std;

/**
  单例模式需要考虑多线程的问题，有以下三种实现方法
  1. 将构造函数设置为同步方法，性能损耗很多
  2. 初始化类的时候将变量立即初始化一个实例，没有延迟构造
  3. 构造函数不动，将构造函数内部修改为 “双重检测”，
     先判断是否为空，如果不为空再同步构造一个对象，
     这样只有初始的时候会有同步，后面再访问就不会同步，
     直接返回对象即可
 */
// 以上是通用设计方法，但在 C++ 中，静态局部对象可以自动保证线程安全
// 在 JAVA 中的最佳实践是使用枚举

// 在 C++ 中使用单例模式，使用智能指针是不友好的，
// make_shared 的时候会调用构造函数，但是构造函数是私有的
// 所以直接使用以下的最佳实践，使用静态局部对象
class Test {
    Test() = default;
    ~Test() = default;

  public:
    // 在 C++11 之后，使用静态局部对象可以实现单例模式
    // 如果多线程同时初始化静态局部对象只会初始化一次，所以是线程安全的
    static Test &Instance() {
        static Test instance;
        return instance;
    }

    Test(const Test &) = delete;
    Test(Test &&) = delete;
    Test &operator=(const Test &) = delete;
    Test &operator=(Test &&) = delete;
};

int main(void) {

    auto &a = Test::Instance();
    auto &b = Test::Instance();

    return 0;
}
