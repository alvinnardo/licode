#include "../template/head.h"
#include <bits/stdc++.h>

int countTriples(int n) {
    // 思路：哈希表
    // 时间 O(n2logn)，空间 O(n)
    vector<int> vec;
    for (int i = 1; i <= n; i++) {
        vec.push_back(i * i);
    }

    int t{}, res{};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            t = i * i + j * j;
            auto pos = std::ranges::lower_bound(vec, t) - vec.begin();
            if (pos < vec.size() && vec[pos] == t) {
                ++res;
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 2
    cout << countTriples(5) << endl;
    // 4
    cout << countTriples(10) << endl;

    return 0;
}
