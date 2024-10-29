#include "../template/head.h"
#include <bits/stdc++.h>

string getNumString(int n, int num) {
    string tmp(n, '0');
    while (n - 1 >= 0 && num) {
        if (num & 1) {
            tmp[n - 1] = '1';
        }
        n--;
        num >>= 1;
    }
    return tmp;
}

vector<string> validStrings(int n) {
    // 题解：位运算
    // 时间 O(2^n)，空间 O(1)，不参与运算
    vector<string> res;
    int mask = (1 << n) - 1;

    for (int i = 0; i < (1 << n); i++) {
        int t = mask ^ i;
        if ((t >> 1 & t) == 0) {
            res.emplace_back(std::move(getNumString(n, i)));
        }
    }

    return res;
}

// 自己实现
vector<string> validStrings2(int n) {
    // 题解：位运算
    // 时间 O(2^n)，空间 O(1)，不参与运算
    vector<string> res;
    int b = (1 << n) - 1;

    for (int i = 0; i < (1 << n); i++) {
        // 判断相邻，考虑 a 与 (a >> 1) 的关系
        // 对于 10, 01, 11，a ^ (a >> 1) 时，连续的 0 会产生 0
        // 取反，则会产生 01, 10, 00, 11，相与后如果不为 0，那么就有相邻的 1，
        // 则之前有相邻的 0，相反的情况就表示没有相邻的 0
        // cout << i << ": " << ((~i & b) & ((~i & b) >> 1)) << endl;
        if (((~i & b) & ((~i & b) >> 1)) == 0) { // 没有相邻的零
            res.emplace_back(std::move(getNumString(n, i)));
        }
    }

    return res;
}

vector<string> validStrings1(int n) {
    // 思路：贪心 + 模拟
    // 时间 O(n2^n)，空间 O(n2^n)

    list<string> ll;
    if (n == 1) {
        return {"0", "1"};
    }

    ll.emplace_back("0");
    ll.emplace_back("1");
    while (ll.front().size() < n) {
        string t = ll.front();
        if (t.back() == '0') {
            ll.emplace_back(t + "1");
        } else {
            ll.emplace_back(t + "0");
            ll.emplace_back(t + "1");
        }
        ll.pop_front();
    }

    return vector<string>(ll.begin(), ll.end());
}

int main(int argc, char *argv[]) {

    // {"0", "1"}
    printVector(validStrings(1));
    // {"01", "10", "11"}
    printVector(validStrings(2));
    // {"010","011","101","110","111"}
    printVector(validStrings(3));
    // printVector(validStrings(18));

    return 0;
}
