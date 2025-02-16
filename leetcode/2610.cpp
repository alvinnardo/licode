#include "../template/head.h"
#include <bits/stdc++.h>

vector<vector<int>> findMatrix(vector<int> nums) {
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
