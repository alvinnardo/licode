#include "chapter_02.h"
#include <bits/stdc++.h>
using namespace std;

constexpr int fibonacci(const int n) {
    // C++14 引入 constexpr 可以使用函数内循环和局部变量
    // 如 if (n == 1 || n == 2) return 1;
    // 用 三元表达式即可在 C++11 下使用
    return n == 1 || n == 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}

void Paragraph(const std::string &line) {
    cout << "=== " << line << " ===" << endl;
}

// template <class T, class U>
// 编译读到 decltype 时 x 和 y 未定义
// decltype(x + y) add (T x, U y) { return x + y; }
template <class T, class U> auto add(T x, U y) { return x + y; }

// 2.4.1
template <typename T> auto print_type(const T &t) {
    if constexpr (std::is_integral<T>::value) {
        return 1;
    } else {
        return 2;
    }
};

int main(void) {

    Paragraph("2.1.1 nullptr");
    // C++ 不允许将 void * 转为其他类型，所以 CPP 中将 NULL 定义为 0，stddef.h
    // 中 char *ch = (void *)0; // CPP 中编译失败

    /*
       char *ch = NULL; // NULL 是 0，指针和数字都能为 0 的情况下就会有歧义
       但 void foo(char *) 和 void foo(int) 函数 foo(NULL) 重载发生错误，将 NULL
       转为了 0 引入 nullptr 用来区分 0 和 空指针 foo(0) 调用 void
       foo(int)；foo(nullptr) 调用 void foo(char *)
     */

    Paragraph("2.1.2 constexpr");
    // 1. 用字面量或常量组成的表达式，不能使用变量，在编译阶段生成结果
    const int len1 = 1;
    constexpr int len2 = 1 + 2 + 3;
    char str1[len1]; // 编译器优化使得合法
    char str2[len2]; // C++11 只支持初始化数组时使用 constexpr

    // 2 constexpr 修饰的函数可以使用递归
    cout << fibonacci(10) << endl;

    Paragraph("2.2.1 if/switch 变量强化");
    // C++17 可以在 if 和 switch 中创建临时变量，和 for 一样
    if (int i = 10; i == 10) {
        cout << "i = 10" << endl;
    }

    Paragraph("2.2.2 初始化列表");
    // 每种类型的变量和对象初始化都有各自的方法
    // C++11 提供 initializer_list 类型
    // 可使得数组，对象，或其它函数使用统一的列表初始化

    /* Foo foo({1, 2});
       Foo foo = {1, 2};
       C++11 提供统一的语法来初始化任意对象，如 Foo foo {1, 2};
     */
    InitList ilist({1, 2, 3, 4, 5});
    InitList ilist2 = {1, 2, 3, 4, 5};
    InitList ilist3{1, 2, 3, 4, 5};

    Paragraph("2.2.3 结构化绑定");
    // 2.2.2 是用于初始化，2.2.3 用于返回值
    // C++11 提供 tuple，但没有提供直接拿元素的方法
    // C++17 提供语法 auto [x, y, z] = f();
    // f() 的返回值是 make_tuple(1, 2, "456");

    Paragraph("2.3.1 类型推导: auto");
    // C++11 引入 auto 关键字，由编译器进行变量的类型推导
    // C++14 可以当作匿名函数传入参数的类型
    auto add = [](auto a, auto b) { return a + b; };
    // C++2a 可以当作普通函数传入参数的类型，但是编译时需要加条件
    // auto 不能推导数组类型，如 auto arr[10] = {} 不合法

    Paragraph("2.3.2 类型推导: decltype");
    // 类似 typeof
    // 1. 可以用来推断某个表达式的类型，弥补 auto 只能推导变量类型的缺陷
    // 如 auto a = 1, b = 2; decltype(a + b) z;

    /* 2. 如用 std::is_same<T, U> 判断类型是否相等
       if (std::is_same<decltype(x), int>::value) { cout << "yes " << endl;}
     */

    // 3. 推断函数返回值的类型，解决模板返回值不确定的问题
    /* 如 前面提到普通函数不能使用 auto,
       则使用模板进行定义，且返回值的类型需要自己定义
       template<typename R, typename A, typename B>
       R add(T x, U y) { return x + y; }

       使用 decltype 简化返回值类型指定，
       但编译不通过，C++14 提供尾返回值类型推导
       template<typename A, typename B>
       decltype(x + y) add(T x, U y) { return x + y; } // wrong
       auto add(T x, U y) { return x + y; } // right
     */

    Paragraph("2.4 控制流");
    Paragraph("2.4.1  if constexpr");
    // constexpr 编译为常量结果
    // if constexpr 在编译时完成分支判断

    Paragraph("2.4.2 区间 for 循环");
    // 形如只读 for (auto a : vec) { cout << a << endl; }
    // 形如可写 for (auto &a : vec) { a += 1; }

    Paragraph("2.5 模板");
    // 在编译阶段生成代码
    Paragraph("2.5.1 外部模板");
    /* 两个文件同时 include 另一个文件中的模板，
       编译时两个文件都要编译该 include 文件，最后链接时删除一个，
       浪费编译时间

       首先, 在一个文件中使用强制实例化，如 int add<int, int>(int, int)
       然后，加上 extern 关键字
       如 test.h 中定义模板
       test1.cpp 中声明 extern int add<int, int>(int, int);
       test2.cpp 中不声明
       那么 test1.cpp 中使用 test2.cpp 中实例的函数
     */
    Paragraph("2.5.2 右尖括号");
    // C++11 中支持嵌套模板，如 vector<vector<int>> vec;
    // 在其之前 >> 会解析为右移运算符

    Paragraph("2.5.3 类型别名模板");
    // 注：模板用来产生类型
    /* typedef 定义模板的模板
       template<class T, class U> class Magic {};
       typedef Magic<std::vector<T>, std::string> Magic1; // 不支持

       C++11 支持用 using 定义模板的模板
       template<class T, class U> class Magic {};
       using Magic2 = Magic<std::vector<T>, std::string>;
    */

    Paragraph("2.5.4 变长参数模板");
    coutValue(1, 2, "123");
    coutValue2(3, 4, "345");
    coutValue3(5, 6, "567");

    Paragraph("2.5.5. 折叠表达式");
    cout << sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl;

    Paragraph("2.5.6 非类型模板");
    // array 的模板就是这样的
    cout << nSum<int, 10>(5) << endl;
    // 编译期生成结果
    cout << doubleSum<10>() << endl;

    Paragraph("2.6 面向对象");
    Paragraph("2.6.1 委托构造");
    shared_ptr<Base> base_ptr = make_shared<Base>(20);
    base_ptr->printVal1();
    base_ptr->printVal2();

    Paragraph("2.6.2 继承构造");
    shared_ptr<Subclass> base_ptr2 = make_shared<Subclass>(20);
    base_ptr2->printVal1();
    base_ptr2->printVal2();

    Paragraph("2.6.3 显式虚函数重载");
    // 本质上是要显示标注各虚函数的关系
    // 在编程过程中，由于套了很多层，
    // 在子类中，不想覆盖虚函数时写了一个重名的方法
    // 在父类中，删除了虚函数的接口
    // 所以引入 virtual override final

    Paragraph("2.6.4 显式禁用默认函数");
    shared_ptr<Test> test_ptr = make_shared<Test>();
    cout << test_ptr->val << endl;

    Paragraph("2.6.5 强枚举类型");
    // 传统 C++ 不同枚举类型都是整数，且同命名空间下枚举名不能相同
    // 使用枚举类进行声明

    // 同一作用域下可以进行枚举值比较
    if (new_enum::val3 == new_enum::val4) {
        cout << "enum true" << endl;
    }

    // 使用值时需要强转
    cout << (int)new_enum2::VAL3 << endl;
    cout << new_enum2::VAL4 << endl; // 重载 << 后可以不用强转

    return 0;
}
