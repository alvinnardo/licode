#include "../template/head.h"
#include <bits/stdc++.h>

string solveEquation(string equation) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    int len = equation.length();
    int dp[2][2]{};
    int pos = 0;
    int num = 0;
    bool neg = false;
    auto reset = [&]() {
        num = 0;
        neg = false;
    };
    for (int i = 0; i <= len; i++) {
        if (i == len || equation[i] == '=') {
            dp[pos][0] += neg ? -num : num;
            reset();
            pos = 1;
        } else if (equation[i] == '-') {
            dp[pos][0] += neg ? -num : num;
            reset();
            neg = true;
        } else if (equation[i] == '+') {
            dp[pos][0] += neg ? -num : num;
            reset();
        } else if (equation[i] == 'x') {
            if (num == 0) {
                // "0x=0"
                dp[pos][1] +=
                    neg ? -1
                        : (i == 0 || i - 1 >= 0 && equation[i - 1] != '0' ? 1
                                                                          : 0);
            } else {
                dp[pos][1] += neg ? -num : num;
            }
            reset();
        } else {
            num = num * 10 + (int)(equation[i] - '0');
        }
    }

    // x 移到左边，数字移到右边
    dp[0][1] -= dp[1][1];
    dp[1][0] -= dp[0][0];

    if (dp[0][1] == 0) {
        if (dp[1][0] == 0) {
            // 左边恒等于右边
            return "Infinite solutions";
        } else {
            // 左右值不一样
            return "No solution";
        }
    }

    // 不是整数
    if (abs(dp[1][0]) % abs(dp[0][1]) != 0) {
        return "No solution";
    }

    return std::string("x=") + std::to_string(dp[1][0] / dp[0][1]);
}

int main(int argc, char *argv[]) {
    // "x=2"
    cout << solveEquation("x+5-3+x=6+x-2") << endl;
    // "Infinite solutions"
    cout << solveEquation("x=x") << endl;
    // "x=0"
    cout << solveEquation("2x=x") << endl;
    // "No solution"
    cout << solveEquation("3x=1") << endl;
    // "x=-1"
    cout << solveEquation("3x+x=-4") << endl;
    // "x=20"
    cout << solveEquation("13x=x+240") << endl;
    // "x=1"
    cout << solveEquation("4x+8=12") << endl;
    // "x=-9"
    cout << solveEquation("-10x+x+1=1-9+18+72") << endl;
    // "Infinite solutions"
    cout << solveEquation("0x=0") << endl;

    return 0;
}
