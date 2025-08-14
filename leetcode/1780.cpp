#include "../template/head.h"
#include <bits/stdc++.h>
bool checkPowersOfThree(int n) {
    // 题解：模拟
    // 时间 O(logn)，空间 O(1)
    // 直接转三进制

    while (n) {
        if (n % 3 == 2) {
            return false;
        }
        n /= 3;
    }

    return true;
}

bool checkPowersOfThree2(int n) {
    // 思路：模拟
    // 时间 O(k)，空间 O(k)
    // 模拟三进制

    vector<int> vec{14348907, 4782969, 1594323, 531441, 177147, 59049,
                    19683,    6561,    2187,    729,    243,    81,
                    27,       9,       3,       1};

    bool find = true;
    for (int i = 0; i < vec.size(); i++) {
        if (n >= vec[i]) {
            n -= vec[i];       // one-hot
            if (n >= vec[i]) { // 只能有一个
                find = false;
                break;
            }
        }
    }

    return find;
}

bool checkPowersOfThree1(int n) {
    // 思路：DFS
    // 时间 O(2^k)，空间 O(logk)
    // 选或不选，根据题目范围，k 最大值 14
    vector<int> vec{1};
    while (vec.back() < n) {
        vec.push_back((vec.back() << 1) + vec.back());
    }

    bool find = false;

    std::function<void(int, int)> dfs = [&](int pos, int sum) {
        if (sum == n) {
            find = true;
            return;
        }

        if (find || pos == vec.size()) {
            return;
        }

        dfs(pos + 1, sum);
        dfs(pos + 1, sum + vec[pos]);
    };

    dfs(0, 0);
    return find;
}

int main(int argc, char *argv[]) {
    // 1
    cout << checkPowersOfThree(12) << endl;
    // 1
    cout << checkPowersOfThree(91) << endl;
    // 0
    cout << checkPowersOfThree(21) << endl;
    // 0
    cout << checkPowersOfThree(10000000) << endl;

    return 0;
}
