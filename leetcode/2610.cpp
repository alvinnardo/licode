#include "../template/head.h"
#include <bits/stdc++.h>
vector<vector<int>> findMatrix(vector<int> nums) {
    // 思路：排序
    // 时间 O(nlogn)，空间 O(1)
    // 排序后，相同的数字放在不同行
    sort(nums.begin(), nums.end());
    int level = 0;
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); i++) {
        if (i == 0 || nums[i] != nums[i - 1]) {
            level = 0;
        }
        if (res.size() < level + 1) {
            res.emplace_back();
        }
        res[level++].push_back(nums[i]);
    }

    return res;
}

vector<vector<int>> findMatrix1(vector<int> nums) {
    // 思路：哈希表
    // 时间 O(n)，空间 O(n)
    vector<int> stat(nums.size() + 1);
    int max_cnt = 0;
    for (int num : nums) {
        max_cnt = max(max_cnt, ++stat[num]);
    }

    vector<vector<int>> res(max_cnt);
    for (int i = 0; i < stat.size(); i++) {
        for (int j = 0; j < stat[i]; j++) {
            res[j].push_back(i);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {{1,3,4,2},{1,3},{1}}
    printVectorVector(findMatrix({1, 3, 4, 1, 2, 3, 1}));
    // {{4,3,2,1}}
    printVectorVector(findMatrix({1, 2, 3, 4}));

    return 0;
}
