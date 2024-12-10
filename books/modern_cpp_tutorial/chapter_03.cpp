#include "chapter_03.h"

// 第 3 章：语言运行期的强化
int main(int argc, char *argv[]) {
    Paragraph("3.1 lambda 表达式");
    // 除了值捕获，引用捕获，还可以表达式捕获
    // 值捕获 和 引用捕获是左值捕获，使用表达式可以捕获右值
    lambda_expression_capture();

    Paragraph("3.2 函数对象包装器");
    // lambda 表示式本质是一个闭包对象，捕获列表为空时，可以使用函数指针传递
    // C++11 提供 function 通用函数封装
    lambda_test_func();

    // 使用 bind 函数对函数的参数进行占位，后期只需要提供占位的参数即可
    bind_example();

    Paragraph("3.3 右值引用");
    Paragraph("3.3.1 左右值");
    /* clang-format off */
    // 左值：赋值符号左边的值，表达式后依然存在的对象
    // 右值：赋值符号右边的值，表达式后不再存在的临时对象
    //    纯右值：纯粹的右值，纯粹的字面量，或匿名临时对象。lambda 表达式也是纯右值
    //            *** 字面量中字符串字面量是 const char 数组，是左值，其它的都是纯右值
    //    将亡值：右值引用，即将被释放，但能够被移动的值。常用于返回值来构造对象。
    /* clang-format on */
    test_literal();

    Paragraph("3.3.2 左右值引用");
    // 1. 使用 T && 得到一个将亡值，让临时值的声明周期延长。
    // 2. 使用 std::move 将左值转为右值
    // 常量左值引用和右值引用都能够延长临时值的生命周期，右值引用可以修改临时值
    test_rvalue();

    Paragraph("3.3.3 移动语义");
    test_return_rvalue();
    test_vector();

    Paragraph("3.3.4 完美转发");
    // 在模板类型推导的情况下分析该问题
    // 右值引用是左值，那么给传参转发带来了问题
    test_pass();
    // 完美转发：为了实现左引用保持左引用，右引用保持右引用

    return 0;
}
