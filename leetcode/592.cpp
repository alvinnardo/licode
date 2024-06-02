#include "../template/head.h"
#include <bits/stdc++.h>
#include <numeric>

string fractionAddition(string expression) {
    // 思路：模拟
    // 时间 O(n)，空间 O(k)
    vector<int> vec1, vec2; // 存放分子
    int len = expression.length();
    int com = 1, up = 0, down = 0;
    bool neg = 0, bk = 0;
    for (int i = 0; i < len; i++) {
        if (expression[i] == '-') {
            neg = 1;
        } else if (expression[i] == '+') {
        } else if (expression[i] == '/') {
            bk = 1;
            vec1.push_back(neg ? -up : up);
        } else {
            if (bk) {
                down = down * 10 + (int)(expression[i] - '0');
            } else {
                up = up * 10 + (int)(expression[i] - '0');
            }
        }
        if (i + 1 < len &&
                (expression[i + 1] == '-' || expression[i + 1] == '+') ||
            i == len - 1) {
            vec2.push_back(down);
            com = std::lcm(com, down);

            up = 0;
            down = 0;
            bk = 0;
            neg = 0;
        }
    }

    int res = 0;
    for (int i = 0; i < vec1.size(); i++) {
        res += com / vec2[i] * vec1[i];
        // cout << vec1[i] << " " << vec2[i] << endl;
    }

    if (res == 0) {
        return "0/1";
    }

    string ng = res < 0 ? "-" : "";
    res = abs(res);
    int c = std::gcd(res, com);

    return ng + to_string(res / c) + "/" + to_string(com / c);
}

int main(int argc, char *argv[]) {
    // "0/1"
    cout << fractionAddition("-1/2+1/2") << endl;
    // "1/3"
    cout << fractionAddition("-1/2+1/2+1/3") << endl;
    // "-1/6"
    cout << fractionAddition("1/3-1/2") << endl;
    cout << fractionAddition("33/100+12/33-17/12-9/8+100/1000") << endl;

    return 0;
}
