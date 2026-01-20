#include "../template/head.h"
#include <bits/stdc++.h>

int hIndex(vector<int> &&citations) {
    // 思路：统计 + 前缀和
    // 时间 O(n)，空间 O(n)

    // 从后往前进行前缀和
    // 用下标表示论文个数
    int sz = citations.size();
    vector<int> vec(sz + 1);
    for (auto cita : citations) {
        if (cita > sz) {
            cita = sz;
        }

        ++vec[cita];
    }

    int res{};
    for (int i = sz; i >= 0; --i) {
        if (i < sz) {
            vec[i] += vec[i + 1];
        }

        // 引用论文次数比论文数多或相等
        if (vec[i] >= i) {
            res = i;
            break;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 3
    cout << hIndex({3, 0, 6, 1, 5}) << endl;
    // 1
    cout << hIndex({1, 3, 1}) << endl;
    // 0
    cout << hIndex({0, 0, 0}) << endl;

    return 0;
}
