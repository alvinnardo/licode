#include "../template/head.h"
#include <bits/stdc++.h>

int lenLongestFibSubseq(vector<int> arr) {
    // 思路：DP + 哈希表
    // 时间 O(n2), 空间 O(n)

    using ll = long long;
    unordered_set<int> uset(arr.begin(), arr.end());
    unordered_set<ll> visited;
    int sz = arr.size();

    int res = 0;

    auto getHash = [](ll a, ll b) { return (a << 32) + b; };

    // 对每一对进行测试
    int last = arr.back() >> 1;
    for (int i = 0; i < sz - 1; i++) {
        if (arr[i] > last) {
            break;
        }

        for (int j = i + 1; j < sz; j++) {
            if (arr[i] + arr[j] > arr.back()) { // 优化时间
                break;
            }

            if (visited.count(getHash(arr[i], arr[j]))) {
                continue;
            }

            int cnt = 0, p = arr[i], q = arr[j];
            while (true) {
                int t = p + q;
                if (uset.count(t)) {
                    visited.insert(getHash(arr[i], arr[j]));
                    p = q;
                    q = t;
                } else {
                    break;
                }
                cnt = cnt == 0 ? 3 : cnt + 1;
            }

            res = max(res, cnt);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 5
    cout << lenLongestFibSubseq({1, 2, 3, 4, 5, 6, 7, 8}) << endl;
    // 3
    cout << lenLongestFibSubseq({1, 3, 7, 11, 12, 14, 18}) << endl;

    return 0;
}
