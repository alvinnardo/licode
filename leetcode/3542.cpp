#include "../template/head.h"
#include <bits/stdc++.h>

int minOperations(vector<int> &&nums) {
    // 题解：单调栈
    // 时间 O(n)，空间 O(n)

    // 这个思路比较难想
    // 延迟删除的思想，单调栈中从小到大放置，表示延迟删除
    // 当遇到更小的表示大的需要删除，小的还是处于延迟删除状态
    // 且删除后，就是有一个 0 分割，后面更大的可以直接加入栈中

    // 如果数字是 0，那么表示分割，清空即可
    int res{};

    vector<int> vec; // 模拟栈
    for (int num : nums) {
        if (num == 0) {
            res += vec.size();
            vec.clear();
            continue;
        }

        while (!vec.empty() && num < vec.back()) {
            res++;
            vec.pop_back();
        }

        if (vec.empty() || num > vec.back()) {
            vec.push_back(num);
        }
    }

    return res + vec.size();
}
int minOperations1(vector<int> &&nums) {
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
