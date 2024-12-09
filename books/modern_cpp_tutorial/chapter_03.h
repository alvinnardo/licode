#include "in.h"

// 3.1.1
void lambda_expression_capture() {
    auto ptr = 1;

    auto add = [v1 = 1, v2 = 2](int a, int b) -> int { return v1 + v2; };

    cout << add(1, 2) << endl;
}

// 3.2
using foo = void(int);

// 函数指针传递
void test_func(foo f) { f(1); }

void outer_func(int val) { cout << val << endl; }

void lambda_test_func() {
    auto fun = [](int val) { cout << val << endl; };
    std::function<void(int)> fun2 = [](int val) { cout << val << endl; };
    std::function<void(int)> fun3 = outer_func;

    test_func(fun); // fun 编译为函数指针
    fun2(3);        // fun2 和 fun3 显示类型，不能使用 test_func
    fun3(3);
}

void bind_example() {
    auto fun = [](int a, int b, int c, int d) {
        cout << "a: " << a << ", b = " << b << ", c = " << c << ", d = " << d
             << endl;
    };

    auto fun2 = bind(fun, 1, std::placeholders::_1, 2, std::placeholders::_2);

    fun2(1, 2);
    fun2(10, 20);
}

void test_literal() {
    // "01234" 包括一个 \0 结束符，总共 6 个字符
    static_assert(std::is_same<decltype("01234"), const char(&)[6]>::value, "");

    const char(&left)[6] = "01234"; // 左值引用
    // const char (&&right)[6] = "01234"; // 右值引用错误

    // TODO
}
