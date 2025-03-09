#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> findingUsersActiveMinutes(vector<vector<int>> logs, int k) {
    // 思路：排序 + 统计
    // 时间 O(nlogn)，空间 O(logn)
    // 同一用户相同时间的记录不算，所以排序计算一下
    // 如果用哈希表存的多，而且遍历还慢，不如直接排序
    sort(logs.begin(), logs.end(), [](const auto &a, const auto &b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    });

    vector<int> res(k);
    int user = -1, times = -1, last = -1;
    for (int i = 0; i < logs.size(); i++) {
        if (logs[i][0] != user) {
            user = logs[i][0];
            times = 1;
        } else if (logs[i][1] != last) {
            times++;
        }

        last = logs[i][1];

        if (i == logs.size() - 1 || user != logs[i + 1][0]) {
            if (times <= k) {
                res[times - 1]++;
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {0,2,0,0,0}
    printVector(
        findingUsersActiveMinutes({{0, 5}, {1, 2}, {0, 2}, {0, 5}, {1, 3}}, 5));
    // {1,1,0,0}
    printVector(findingUsersActiveMinutes({{1, 1}, {2, 2}, {2, 3}}, 4));

    return 0;
}
