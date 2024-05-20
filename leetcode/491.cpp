#include "../template/head.h"
#include <bits/stdc++.h>

vector<vector<int>> findSubsequences(vector<int> nums) {
    // 思路：DFS, 选或不选
    // 时间 O(2^n)，空间 O(n)

    int sz = nums.size();
    vector<vector<int>> res;
    vector<int> tmp;
    function<void(int)> dfs = [&](int pos) {
        if (pos == sz) {
            if (tmp.size() > 1) {
                res.emplace_back(tmp);
            }
            return;
        }

        // 去重，获取不重复子集的时候是和自己比较
        // 这里要和过程数组进行比较
        if (tmp.empty() || nums[pos] != tmp.back()) {
            dfs(pos + 1);
        }
        if (tmp.empty() || nums[pos] >= tmp.back()) {
            tmp.push_back(nums[pos]);
            dfs(pos + 1);
            tmp.pop_back();
        }
    };

    dfs(0);
    return res;
}

int main(int argc, char *argv[]) {
    printVectorVector(findSubsequences({4, 6, 7, 7}));
    printVectorVector(findSubsequences({4, 4, 3, 2, 1}));
    printVectorVector(findSubsequences({1, 3, 4, 3, 4, 4}));
    printVectorVector(findSubsequences({1, 3, 2, 3, 2, 4, 3}));

    return 0;
}
