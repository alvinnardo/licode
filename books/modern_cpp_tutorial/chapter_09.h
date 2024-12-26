#include "in.h"
#include <mutex>
#include <thread>

void may_throw() { throw true; }

// 警告
void throw_with_noexcept() noexcept { throw true; }

auto non_block_throw = [] { may_throw(); };

void no_throw() noexcept { return; }
void no_throw_without_noexcept() { return; }

auto block_throw = []() noexcept { no_throw(); };
auto block_throw_without_noexcept = []() { no_throw(); };

void test_noexcept() {
    cout << noexcept(may_throw()) << endl;
    cout << noexcept(non_block_throw()) << endl;
    cout << noexcept(no_throw()) << endl;
    cout << noexcept(no_throw_without_noexcept()) << endl;
    cout << noexcept(block_throw()) << endl;
    cout << noexcept(block_throw_without_noexcept()) << endl;

    try {
        // throw_with_noexcept(); // 宕机
    } catch (...) {
        cout << "except" << endl;
    }

    cout << "continue ..." << endl;
}

void test_raw_string() {
    auto str = "\\\\\\";
    auto raw_str = R"(\\\)";
    cout << str << "\n" << raw_str << endl;
}

string operator"" _wow1(const char *wow1, size_t len) {
    return std::string(wow1) + "wwwwwwwwwwwwoooooooooooowwwwwwww";
}

string operator"" _wow2(unsigned long long i) {
    return std::to_string(i) + "wwwwwwwwwwwwoooooooooooowwwwwwww";
}

int operator"" _wow3(unsigned long long i) { return i + 10000; }
int operator"" _wow4(const char *i) { return int(*i) + 10000; }

// 不仅可以自定义字符串，也可以自定义数字等字面量
void test_defined_string() {
    // 字符串必须用 (const char *, size_t) 做参数
    auto str1 = "abc"_wow1;

    // 整数可以用 unsigned long long, const char * 等，
    // 一般用 unsigned long long 即可
    auto str2 = 1_wow2;
    auto val1 = 1_wow3;
    auto val2 = 1_wow4;
    cout << str1 << endl;
    cout << str2 << endl;
    cout << val1 << endl;
    cout << val2 << endl;
}

struct ST {
    char a = 'a';    // 1 -> 4
    int b = 0;       // 4
    double c = 0.0;  // 8
    long long d = 0; // 8
};

// max_align_t 返回当前平台最大默认内存对齐类型
// 一般是 16，最后对结构体对齐
struct alignas(std::max_align_t) AlignasST {
    char a = 'a';    // 1 -> 4
    int b = 0;       // 4
    double c = 0.0;  // 8
    long long d = 0; // 8
};

// 每个成员变量的对齐数 = min{编译器默认对齐数, 成员大小}
// 结构体总大小 (添加 padding) = 每个成员变量最大对齐数的整数倍
void test_memory_align() {
    cout << "max_align_t: " << alignof(std::max_align_t) << endl;
    ST st;
    cout << "ST: " << endl;
    cout << "&a: " << &st << endl;
    cout << "&b: " << &st.b << endl;
    cout << "&c: " << &st.c << endl;
    cout << "&d: " << &st.d << endl;
    cout << "size: " << sizeof(st) << ", alignof " << alignof(ST) << endl;

    AlignasST ast;
    cout << "AST: " << endl;
    cout << "&a: " << &ast << endl;
    cout << "&b: " << &ast.b << endl;
    cout << "&c: " << &ast.c << endl;
    cout << "&d: " << &ast.d << endl;
    cout << "size: " << sizeof(ast) << ", alignof " << alignof(AlignasST)
         << endl;
}
