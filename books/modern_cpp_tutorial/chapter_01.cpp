#include <bits/stdc++.h>
using namespace std;

int main(void) {
    // 1.1：被弃用的特性
    char *str = "hello world";
    const char *str2 = "hello world";
    auto str3 = "hello world";

    // 1.2 与 C 的兼容性
    // 将 C 与 C++ 分开编译
    // #ifdef __cplusplus
    //     extern "C" {
    // #endif
    //     int add(int x, int y);
    // #ifdef __cplusplus
    // }
    // #endif

    return 0;
}
