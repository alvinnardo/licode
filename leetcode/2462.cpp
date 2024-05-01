#include "../template/head.h"
#include <bits/stdc++.h>

long long totalCost(vector<int> costs, int k, int candidates) {
    // 思路：双指针 + 优先队列(最小堆)，保存最小值和 index 的关系
    // 时间 O(nlogn), 空间 O(n)
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    int sz = costs.size();
    int left = candidates, right = sz - candidates - 1;
    // 把前后的加进去
    // 优化，前后分别加，不用遍历整个数组
    for (int i = 0; i < left; i++) {
        pq.emplace(costs[i], i);
    }
    // 这里注意区间重叠
    for (int i = right < left ? left : right + 1; i < sz; i++) {
        pq.emplace(costs[i], i);
    }

    // 一个一个选
    long long res = 0;
    while (k--) {
        auto t = pq.top();
        res += t.first;
        pq.pop();

        // 中间有数，就向内收缩
        if (left <= right) {
            // 选了左边的，左边收缩
            if (t.second < left) {
                pq.emplace(costs[left], left);
                left++;
            } else { // 右边收缩
                pq.emplace(costs[right], right);
                right--;
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {

    // 11
    cout << totalCost({17, 12, 10, 2, 7, 2, 11, 20, 8}, 3, 4) << endl;
    // 4
    cout << totalCost({1, 2, 4, 1}, 3, 3) << endl;

    return 0;
}
