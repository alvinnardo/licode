#include "chapter_06.h"
#include <bits/stdc++.h>
using namespace std;

int main(void) {

    Paragraph("6.1 正则表达式简介");
    // 一般三个目的：a. 检查是否有; b. 有的话替换; c. 提取满足的字符串
    /* 特殊字符（有特殊含义的字符）

        ^ 开头，$ 结尾
        * 零次或多次，+ 一次或多次, ? 零次或一次
        \ 转义，如 \\ 表示 \，\( 表示 (
        | 或
        () 子表达式，[] 中括号表达式，{} 限定符表达式
    */

    /* 限定符：

       * 等价于 {0, }
       + 等价于 {1, }
       ? 等价于 {0,1}
       {n}, n 为非负整数，匹配确定的 n 次，如 o{2} 匹配 oo
       {n, }, n 为非负整数，至少匹配 n 此，如 o{2, } 匹配 ooooo
       {n, m}, m 和 n 为非负整数，n <= m，最少匹配 n 次，最多匹配 m 次
     */

    Paragraph("6.2 std::regex");
    // 正则表达式库
    test_regex();

    return 0;
}
