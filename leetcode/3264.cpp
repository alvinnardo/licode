#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> getFinalState(vector<int> nums, int k, int multiplier) {
    // 思路：堆
    // 时间 O(klogn)，空间 O(n)
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   std::greater<pair<int, int>>>
        pq;

    for (int i = 0; i < nums.size(); i++) {
        pq.emplace(nums[i], i);
    }

    while (k--) {
        auto t = pq.top();
        // cout << t.first << ": " << t.second << endl;
        pq.pop();
        t.first *= multiplier;

        nums[t.second] = t.first;

        pq.emplace(t.first, t.second);
    }

    return nums;
}

int main(int argc, char *argv[]) {
    // {8,4,6,5,6}
    printVector(getFinalState({2, 1, 3, 5, 6}, 5, 2));
    // {6,8,6,5,6}
    printVector(getFinalState({3, 1, 3, 5, 6}, 5, 2));
    // {16,8}
    printVector(getFinalState({1, 2}, 3, 4));

    return 0;
}
