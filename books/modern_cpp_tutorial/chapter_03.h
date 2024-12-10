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

// 3.3.1
void test_literal() {
    // "01234" 包括一个 \0 结束符，总共 6 个字符
    static_assert(std::is_same<decltype("01234"), const char(&)[6]>::value, "");

    const char(&left)[6] = "01234"; // 左值引用
    // const char (&&right)[6] = "01234"; // 右值引用错误
}

// 3.3.2
template <typename T> void reference(T &) { cout << "lvalue" << endl; }

template <typename T> void reference(T &&) { cout << "rvalue" << endl; }
void test_rvalue() {

    string lv1 = "string."; // lv1 是左值

    // string &&rv1 = lv1; // 右值引用不能引用左值
    string &&rv1 = std::move(lv1); // move 将左值转为右值
    cout << rv1 << endl;

    // string &lv2 = lv1 + lv1; // 非常量左值引用不能引用右值
    const string &lv2 = lv1 + lv1; // 常量左值引用延长临时变量生命周期
    cout << lv2 << endl;

    string &&rv2 = lv1 + lv2; // 右值引用延长临时对象生命周期
    rv2 += "Test";            // 非常量引用能够修改临时变量
    cout << rv2 << endl;

    // 输出左值，rv2 是一个引用（不管左值引用还是右值引用），所以还是左值
    reference(rv2);
}

// 3.3.3
struct A {
    int *pointer;
    A() : pointer(new int(1)) { cout << "构造：" << pointer << endl; }
    A(A &a) : pointer(new int(*a.pointer)) {
        cout << "拷贝：" << pointer << endl;
    }
    A(A &&a) : pointer(a.pointer) {
        // 把将亡值的指针设置为 0，否则析构时会释放掉内存
        a.pointer = nullptr;
        cout << "移动：" << pointer << endl;
    }

    ~A() {
        cout << "析构：" << pointer << endl;
        delete pointer;
    }
};

A return_rvalue(bool test) {
    A a, b;
    if (test)
        return a;
    return b; // 等价于 static_cast<A&&>(b)

    // return test ? a : b; // 测试用三元表达式是拷贝构造
}

void test_return_rvalue() {
    A obj = return_rvalue(false); // 用将亡值进行移动语义
    cout << "obj: " << endl;
    cout << obj.pointer << endl;
    cout << *obj.pointer << endl;
}

void test_vector() {
    string str = "hello";
    vector<string> vec;

    vec.push_back(str);  // 拷贝构造
    cout << str << endl; // hello

    vec.push_back(std::move(str)); // 移动构造
    cout << str << endl;           // 空
}

// 3.3.4
// 引用坍缩规则
/*   形参        实参    推导后形参类型
     T&        左引用     T& (相同, 正确)
     T&        右引用     T& (报错)
     T&&       左引用     T& (坍缩，正确)
     T&&       右引用     T&& (相同，正确)
 */
// 对于推导类型，如果形参是 T&&，实参是左引用，那么就会推导成 T&
// 不使用推导的情况下，右值引用不能引用左值
// void pass(int &&v) {
//     // v 是左值
//     reference(v);
// }

template <typename T> void pass(T &&v) {
    cout << "   普通传参：";
    reference(v); // v 是左值

    cout << "   move 传参：";
    reference(std::move(v)); // 左值转右值

    cout << "   forward 传参：";
    reference(std::forward<T>(v));

    cout << "   static_cast<T&&> 传参：";
    // forward 中调用了 static_cast<T&&>()
    reference(static_cast<T &&>(v));
}

void test_pass() {
    cout << "传右值：" << endl;
    pass(1); // 传右值，输出左值

    cout << "传左值：" << endl;
    int lval = 1;
    pass(lval); // 传左值，输出左值
}
