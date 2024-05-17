#include "../template/head.h"
#include <bits/stdc++.h>

int maxProfitAssignment(vector<int> difficulty, vector<int> profit,
                        vector<int> worker) {
    // 思路：得到每个难度任务的最大收益，相同难度收益大的为准，然后遍历工人得到他能获取的最大收益
    // 时间 O(nlogn + mlogn)，空间 O(logm)
    int n = difficulty.size(), m = worker.size();
    // 先按 difficulty 的大小排序位置，然后根据位置获取 profit
    vector<int> ordered_profit(n);
    iota(ordered_profit.begin(), ordered_profit.end(), 0);
    sort(ordered_profit.begin(), ordered_profit.end(),
         [&](int i, int j) { return difficulty[i] < difficulty[j]; });
    int maxv = INT_MIN;
    for (int i = 0; i < n; i++) {
        maxv = max(maxv, profit[ordered_profit[i]]);
        ordered_profit[i] = maxv;
    }

    sort(difficulty.begin(), difficulty.end());
    // printVector(difficulty);
    // printVector(ordered_profit);

    int sum = 0;
    for (auto w : worker) {
        auto t = upper_bound(difficulty.begin(), difficulty.end(), w) -
                 difficulty.begin() - 1;
        if (t >= 0) {
            sum += ordered_profit[t];
        }
    }

    return sum;
}

int main(int argc, char *argv[]) {
    // 100
    cout << maxProfitAssignment({4, 2, 10, 8, 6}, {20, 10, 50, 40, 30},
                                {4, 5, 6, 7})
         << endl;
    // 0
    cout << maxProfitAssignment({4, 2, 10, 8, 6}, {20, 10, 50, 40, 30}, {1})
         << endl;
    // 0
    cout << maxProfitAssignment({85, 47, 57}, {24, 66, 99}, {40, 25, 25})
         << endl;
    // 190
    cout << maxProfitAssignment({13, 37, 58}, {4, 90, 96}, {34, 73, 45})
         << endl;

    return 0;
}
