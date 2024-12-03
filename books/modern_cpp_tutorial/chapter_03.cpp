#include "chapter_03.h"

// 第 3 章：语言运行期的强化
int main(int argc, char *argv[]) {
    Paragraph("3.1 lambda 表达式");
    // 除了值捕获，引用捕获，还可以表达式捕获
    lambda_expression_capture();

    return 0;
}
