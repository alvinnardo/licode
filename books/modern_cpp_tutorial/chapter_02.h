#include <bits/stdc++.h>
using namespace std;

// 2.5.4
// 1. 边长参数模板
template <typename... Args> class Magic1 {};

// 任意个数，包括 0 个
class Magic1<> darkMagic;
class Magic1<int, vector<int>, map<string, int>> darkMagic2;

// 2. 不想要 0 个的
template <typename Require, typename... Args> class Magic2 {};
// class Magic2<> darkMagic3; // 不支持 0 个

// 3. 函数参数也支持变长参数
template <typename... Args> void printf(const string &str, Args... args);

// 4. 对参数进行解包
// 4.1 获得个数
template <typename... Args> void coutNum(Args... args) {
    cout << sizeof...(args) << endl;
}

// 4.2 递归解包
template <typename T> void coutValue(T value) { cout << value << endl; }

// 递归模板遍历所有值
// 如果没有处理一个参数的模板，则尾递归到没有参数的模板，就会报错
// 必须定义一个终止递归的函数
template <typename T, typename... Args> void coutValue(T value, Args... args) {
    cout << value << endl;
    coutValue(args...); // 到最后一个值处理后，又递归调用 coutValue() 无参数
}

// 4.3 C++17 支持变参模板解包功能
template <typename T, typename... Args> void coutValue2(T value, Args... args) {
    cout << value << endl;
    // 主要解决 0 参数递归的问题
    // constexpr 表示在编译阶段判断
    if constexpr (sizeof...(args) > 0) {
        coutValue2(args...);
    };
}

// 4.4 使用初始化列表解包
template <typename T, typename... Args> void coutValue3(T value, Args... args) {
    cout << value << endl;
    // 这里包含一个匿名函数，auto fun = [&args] () { cout << args << endl; }
    // 然后执行这个匿名函数
    // TODO
    initializer_list<T>{([&args] { cout << args << endl; }(), value)...};
}

// ======
// 2.5.5
// C++17 表达式支持变长参数: t + ...
template <typename... T> auto sum(T... t) { return (t + ...); }

// ======
// 2.5.6
// 模板中可以使用 typename 表示类型模板，
// 也支持用非类型模板，并使用字面量传递模板中的参数
template <typename T, int num> auto nSum(T value) { return num * value; }
// 可以自动推导
template <auto num> auto doubleSum() { return num << 1; }

// ======
// 2.6.1 构造函数可以调用另一个构造函数
class Base {
  public:
    int val1 = 0;
    int val2 = 0;
    Base() { val1 = 1; }

    Base(int val) { val2 = val; }

    void printVal() { cout << val1 << ", " << val2 << endl; }
};
