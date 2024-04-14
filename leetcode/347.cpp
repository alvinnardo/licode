#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> nums, int k) {
    // 时间 O(n + klogk)
    // O(n) < O(nlogn); k < n => O(klogk) < O(nlogn)
    vector<pair<int, int>> res; // 次数和数字
    unordered_map<int, int> umap;

    for (auto &num : nums) {
        umap[num]++;
    }

    for (auto &it : umap) {
        res.emplace_back(it.second, it.first);
    }

    sort(res.begin(), res.end(), greater<pair<int, int>>());

    vector<int> ans;
    for (int i = 0; i < k; i++) {
        ans.push_back(res[i].second);
    }

    return ans;
}

int main(void) {
    printVector(topKFrequent({1, 1, 1, 2, 2, 3}, 2));
    printVector(topKFrequent({1}, 1));

    return 0;
}
