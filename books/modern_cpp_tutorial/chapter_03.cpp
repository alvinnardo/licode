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

    // 左值：赋值符号左边的值，表达式后依然存在的对象
    // 右值：赋值符号右边的值，表达式后不再存在的临时对象
    //    纯右值：纯粹的右值，纯粹的字面量，或匿名临时对象。lambda 表达式也是纯右值
    //            *** 字面量中字符串字面量是 const char 数组，是左值，其它的都是纯右值
    //    将亡值


    return 0;
}
