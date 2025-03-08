#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> maximumBeauty(vector<vector<int>> items, vector<int> queries) {
    // 思路：排序 + 二分
    // 时间: O(nlogn + mlogn)，空间 O(n)
    sort(items.begin(), items.end(),
         [](const auto &a, const auto &b) { return a[0] < b[0]; });

    // 从前往后获取最大值
    for (int i = 1; i < items.size(); i++) {
        items[i][1] = max(items[i - 1][1], items[i][1]);
    }

    // 二分
    auto bi = [&](int left, int right, int val) {
        int res = items.size();
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (items[mid][0] > val) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return res;
    };

    for (int i = 0; i < queries.size(); i++) {
        auto pos = bi(0, items.size() - 1, queries[i]) - 1;
        if (pos == -1) {
            queries[i] = 0;
        } else {
            queries[i] = items[pos][1];
        }
    }

    return queries;
}

int main(int argc, char *argv[]) {
    // {2,4,5,5,6,6}
    printVector(maximumBeauty({{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}},
                              {1, 2, 3, 4, 5, 6}));
    // {4}
    printVector(maximumBeauty({{1, 2}, {1, 2}, {1, 3}, {1, 4}}, {1}));
    // {0}
    printVector(maximumBeauty({{10, 1000}}, {5}));

    return 0;
}
