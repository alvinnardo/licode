#include "../template/head.h"
#include <bits/stdc++.h>

int maxDistance(vector<vector<int>> arrays) {
    // 题解：一次遍历
    // 遍历时保存最大值和最小值，先计算再更新值能保证不在一行
    // 时间 O(n)，空间 O(1)
    int minv = INT_MAX, maxv = INT_MIN;
    int sz = arrays.size(), res = -1;
    for (int i = 0; i < arrays.size(); i++) {
        if (i == 0) {
            minv = arrays[i][0];
            maxv = arrays[i].back();
            continue;
        }

        res = max(res,
                  max(abs(arrays[i][0] - maxv), abs(arrays[i].back() - minv)));
        minv = min(minv, arrays[i][0]);
        maxv = max(maxv, arrays[i].back());
    }

    return res;
}

int maxDistance_my(vector<vector<int>> arrays) {
    // 思路：哈希表
    // 最大值 - 最小值的最大值
    // 时间 O(mlogm)，空间 O(m)
    int sz = arrays.size();
    map<int, int> mm;
    for (int i = 0; i < sz; i++) {
        mm[arrays[i].back()]++;
    }

    int res = -1, t = -1;
    for (int i = 0; i < sz; i++) {
        t = arrays[i].back();
        if (--mm[t] == 0) {
            mm.erase(t);
        }
        res = max(res, abs(mm.rbegin()->first - arrays[i][0]));
        mm[t]++;
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 4
    cout << maxDistance({{1, 2, 3}, {4, 5}, {1, 2, 3}}) << endl;
    // 0
    cout << maxDistance({{1}, {1}}) << endl;

    return 0;
}
