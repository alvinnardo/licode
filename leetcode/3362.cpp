#include "../template/head.h"
#include <bits/stdc++.h>

int maxRemoval(vector<int> nums, vector<vector<int>> queries) {
    // 思路：贪心 + 优先队列
    // 时间 O(nlogn)，空间 O(logn)

    // 先求最少留下即可，则是最多删除几个
    // 贪心：每次选择的范围应该是第一个没有被删除干净的
    //       确定了左范围后，右范围要尽量大，才能多删少留

    sort(queries.begin(), queries.end(),
         [](const auto &a, const auto &b) { return a[0] < b[0]; });

    priority_queue<int> pq;
    int sz = nums.size();
    for (int i = sz - 1; i > 0; i--) {
        nums[i] -= nums[i - 1];
    }
    nums.push_back(0);

    int cur = 0;
    int j = 0, cnt = 0;
    for (int i = 0; i < sz; i++) {
        cur += nums[i];
        // 删除无效的
        while (!pq.empty() && pq.top() < i) {
            pq.pop();
        }
        // 插入新的范围
        while (j < queries.size() && queries[j][0] <= i) {
            pq.push(queries[j][1]);
            j++;
        }

        while (cur > 0) {
            if (pq.empty()) {
                return -1;
            }

            int t = pq.top();
            pq.pop();
            if (t < i) { // 因为是大根堆，所以后面的小值可能不成立
                continue;
            }
            cur--;
            nums[t + 1]++;
            cnt++;
        }
    }

    return queries.size() - cnt;
}

int main(int argc, char *argv[]) {
    // 1
    cout << maxRemoval({2, 0, 2}, {{0, 2}, {0, 2}, {1, 1}}) << endl;
    // 2
    cout << maxRemoval({1, 1, 1, 1}, {{1, 3}, {0, 2}, {1, 3}, {1, 2}}) << endl;
    // -1
    cout << maxRemoval({1, 2, 3, 4}, {{0, 3}}) << endl;
    // -1
    cout << maxRemoval({0, 0, 3}, {{0, 2}, {1, 1}, {0, 0}, {0, 0}}) << endl;

    return 0;
}
