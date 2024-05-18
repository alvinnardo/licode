#include "../template/head.h"
#include <bits/stdc++.h>

int maxDivScore(vector<int> nums, vector<int> divisors) {
    // 思路：哈希表
    // 时间 O(mn), 空间 O(m)
    int val = -1, maxv = INT_MIN;
    unordered_set<int> uset;
    for (auto div : divisors) {
        if (uset.find(div) != uset.end()) {
            continue;
        }
        uset.insert(div);
        int cnt = 0;
        for (auto num : nums) {
            if (num % div == 0) {
                cnt++;
            }
        }
        if (cnt > maxv) {
            val = div;
            maxv = cnt;
        } else if (cnt == maxv) {
            val = min(val, div);
        }
    }

    return val;
}

int main(int argc, char *argv[]) {
    // 3
    cout << maxDivScore({4, 7, 9, 3, 9}, {5, 2, 3}) << endl;

    // 5
    cout << maxDivScore({20, 14, 21, 10}, {5, 7, 5}) << endl;

    // 10
    cout << maxDivScore({12}, {10, 16}) << endl;
    return 0;
}
