#include "../template/head.h"
#include <bits/stdc++.h>

// 简单题
vector<int> occurrencesOfElement(vector<int> nums, vector<int> queries, int x) {
    // 思路：哈希表
    // 时间 O(n)，空间 O(k)
    vector<int> pos_vec, res;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == x) {
            pos_vec.push_back(i);
        }
    }

    for (int i = 0; i < queries.size(); i++) {
        if (pos_vec.size() < queries[i]) {
            res.push_back(-1);
        } else {
            res.push_back(pos_vec[queries[i] - 1]);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {0,-1,2,-1}
    printVector(occurrencesOfElement({1, 3, 1, 7}, {1, 3, 2, 4}, 1));
    // {-1}
    printVector(occurrencesOfElement({1, 2, 3}, {10}, 5));

    return 0;
}
