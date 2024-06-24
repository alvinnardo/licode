#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> kthSmallestPrimeFraction(vector<int> arr, int k) {
    // 思路：优先队列
    // 时间 O(klogn)，空间 O(n)
    // 分子除以分母，优先队列是最小堆
    auto cmp = [&](const pair<int, int> &a, const pair<int, int> &b) -> bool {
        double ta = arr[a.first] * 1.0 / arr[a.second];
        double tb = arr[b.first] * 1.0 / arr[b.second];
        return ta > tb;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(
        cmp);
    int sz = arr.size();
    for (int i = 1; i < sz; i++) {
        pq.emplace(0, i);
    }

    pair<int, int> res;
    while (k--) {
        auto t = pq.top();
        pq.pop();
        res.first = t.first;
        res.second = t.second;
        if (++t.first < t.second) {
            pq.emplace(t.first, t.second);
        }
    }

    return {arr[res.first], arr[res.second]};
}

int main(int argc, char *argv[]) {
    // {2,5}
    printVector(kthSmallestPrimeFraction({1, 2, 3, 5}, 3));
    // {1,7}
    printVector(kthSmallestPrimeFraction({1, 7}, 1));

    return 0;
}
