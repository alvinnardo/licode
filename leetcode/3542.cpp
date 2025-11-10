#include "../template/head.h"
#include <bits/stdc++.h>

int minOperations(vector<int> &&nums) {
    // 思路：优先队列 + 红黑树
    // 时间 O(nlogn)，空间 O(n)

    // 优先队列里保存最小值和位置
    // 红黑树中存放 0 的位置，看用例 3 零分割后的两个子数组不能
    // pair 先存值，再存位置
    // 从大到小排列，小根堆
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   std::greater<pair<int, int>>>
        pq;
    set<int> st;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            st.insert(i);
        } else {
            pq.emplace(nums[i], i);
        }
    }

    // while (!pq.empty()) {
    //     cout << pq.top().first << " " << pq.top().second << endl;
    //     pq.pop();
    // }

    int res{};
    int prev = -1, prep{};
    while (!pq.empty()) {
        auto &t = pq.top();

        if (prev == -1) {
            prev = t.first;
            prep = t.second;
            st.insert(t.second); // 把该位变成 0
            pq.pop();
            res++;                    // 做这一组的开头
        } else if (t.first == prev) { // 要查看和之前的有没有分割
            auto pos = st.upper_bound(prep);
            if (pos != st.end() && *pos < t.second) { // 两个位置之间有 0
                prev = -1;
                continue;
            } else {
                prep = t.second;
                st.insert(t.second); // 把该位变成 0
                pq.pop();
            }
        } else { // 最小值变了，就跳过
            prev = -1;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 1
    cout << minOperations({0, 2}) << endl;
    // 3
    cout << minOperations({3, 1, 2, 1}) << endl;
    // 4
    cout << minOperations({1, 2, 1, 2, 1, 2}) << endl;

    return 0;
}
