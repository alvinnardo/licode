#include "../template/head.h"
#include <bits/stdc++.h>

bool doesAliceWin(string s) {
    // 思路：贪心
    // 时间 O(n)，空间 O(1)
    // 题目的要求是必须要拿到任意非空

    // 如果总共奇数个元音，则 Alice 一次全拿走整个串
    // 如果总共偶数个元音，则 Alice 第一次剩一个元音字母，
    //   无论 Bob 拿多少，下一次 Alice 把剩下拿走就行

    // 所以只要有元音字母，Alice 就能获胜
    return s.find_first_of("aeiou") != std::string::npos;
}

int main(int argc, char *argv[]) {
    // true
    cout << doesAliceWin("leetcoder") << endl;
    // false
    cout << doesAliceWin("bbcd") << endl;

    return 0;
}
