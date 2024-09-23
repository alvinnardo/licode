#include "../template/head.h"
#include <bits/stdc++.h>
int maxScoreSightseeingPair(vector<int> values) {
    // 思路：遍历
    // 时间 O(n)，空间 O(1)
    // 遍历过程中维护 values[i] + i 的最大值，找 values[j] - j 的最大值
    int sz = values.size(), res = -1, left = values[0];
    for (int i = 1; i < sz; i++) {
        res = max(res, left + values[i] - i);
        left = max(left, values[i] + i);
    }

    return res;
}

int maxScoreSightseeingPair_my(vector<int> values) {
    // 思路：红黑树
    // 时间 O(nlogn)，空间 O(n)
    // 简化为求 (values[i] + i) + (values[j] - j) (i < j) 的最大值
    // 用红黑树保存 values[j] - j 的结果
    int sz = values.size();
    int last = -1, res = -1;
    map<int, int> mmap;
    for (int i = 0; i < sz; i++) {
        mmap[values[i] - i]++;
    }

    for (int i = 0; i < sz; i++) {
        int t = values[i] - i;
        if (mmap[t] == 1) {
            mmap.erase(t);
        } else {
            mmap[t]--;
        }

        t = values[i] + i;
        if (t > last && !mmap.empty()) {
            last = t;
            res = max(res, t + mmap.rbegin()->first);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {

    // 11
    cout << maxScoreSightseeingPair({8, 1, 5, 2, 6}) << endl;
    // 2
    cout << maxScoreSightseeingPair({1, 2}) << endl;
    // 1
    cout << maxScoreSightseeingPair({1, 1}) << endl;
    // 2
    cout << maxScoreSightseeingPair({1, 2}) << endl;

    return 0;
}
