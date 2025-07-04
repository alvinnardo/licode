#include "../template/head.h"
#include <bits/stdc++.h>

char kthCharacter(long long k, vector<int> &&operations) {
    // 思路：前缀和 + DFS
    // 时间 O(logn)，空间 O(n)

    vector<long long> vec;
    vec.push_back(1);
    while (vec.back() < k) {
        vec.push_back(vec.back() << 1);
    }

    function<int(long long, int)> dfs = [&](long long k, int pos) -> int {
        if (pos == 0) {
            return 0;
        }

        long long new_k = vec[pos - 1] - (vec[pos] - k);
        // 找到新 k 的位置，大于等于
        auto new_pos = lower_bound(vec.begin(), vec.end(), new_k) - vec.begin();

        // 翻不翻倍是由前一个元素决定的
        return dfs(new_k, new_pos) + operations[pos - 1];
    };

    int cnt = dfs(k, vec.size() - 1);

    return 'a' + (cnt % 26);
}

int main(int argc, char *argv[]) {
    // "a"
    cout << kthCharacter(5, {0, 0, 0}) << endl;
    // "b"
    cout << kthCharacter(10, {0, 1, 0, 1}) << endl;
    // "g"
    cout << kthCharacter(500,
                         {1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0,
                          1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1,
                          0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0,
                          0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0,
                          1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0,
                          0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0})
         << endl;

    return 0;
}
