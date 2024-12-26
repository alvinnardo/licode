#include "chapter_09.h"
#include <bits/stdc++.h>
using namespace std;

// 其他杂项
int main(void) {

    Paragraph("9.1 新类型");
    // C++11 之前就有 long long int 类型，C++11 正式把该类型纳入标准库
    // 规定一个 long long int 类型至少具备 64 位的比特数

    Paragraph("9.2 noexcept 的修饰和操作");
    // C++ 定义了一套完整的异常处理机制

    // 在函数声明后添加 noexcept 关键字来声明该函数不能抛出任何异常
    // 如果 noexcept 修饰过的函数抛出了异常，
    // 编译器使用 std::terminate() 来立即终止程序运行
    // 能够阻止异常的扩散传播，有效地让编译器最大限度优化我们的代码

    // noexcept 还可以做操作符，判断函数是否标记了 noexcept
    test_noexcept();

    Paragraph("9.3 字面量");
    Paragraph("9.3.1 原始字符串字面量");
    // 用于解决有大量转义字符的字符串
    // 引入 R 修饰该字符串表示原始字符串字面量
    test_raw_string();

    Paragraph("9.3.2 自定义字面量");
    // 重载双引号后缀运算符
    // 1.整型字面量，如 1_xxx 传入 1，返回任何类型的值。
    //   重载时参数必须使用 unsigned long long, const char * 等，
    //   一般用 unsigned long long 即可
    // 2.浮点型字面量，一般用 long double 即可
    // 3.字符串字面量，必须使用 (const char *, size_t) 的参数列表
    // 4.字符字面量，一般用 char 即可

    // 这里的自定义字面量指 自定义一个字面量产生其他结果
    // 1_xxx 自定义整形字面量
    // "abc"_xxx 自定义字符串字面量
    test_defined_string();

    Paragraph("9.4 内存对齐");
    // C++11 引入 alignof 和 alignas 支持对内存对齐进行控制
    // alignof 获得与平台相关的 std::size_t 类型的值，
    //         查询该平台对该变量的对齐方式
    // alignas(align as) 重新修改某个结构的对齐方式
    test_memory_align();

    return 0;
}
