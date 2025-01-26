#include "../template/head.h"
#include <bits/stdc++.h>

vector<vector<int>> combinationSum2(vector<int> candidates, int target) {
    // 思路：回溯 + 剪枝
    // 时间 O(2^n)，空间 O(logn)
    sort(candidates.begin(), candidates.end(), std::greater<int>());

    vector<vector<int>> res;
    vector<int> tmp;
    int sum = 0, sz = candidates.size();

    function<void(int)> dfs = [&](int pos) {
        if (sum == target) {
            res.emplace_back(tmp);
        }

        // 在每一层选取 1 个数，选后可以直接判断是否为结果
        for (int i = pos; i < sz; i++) {
            // 这里用到了一个技巧，在同一层中，pos 都相等，
            // 如果出现相邻相同的值，i 的值都大于 pos

            // 如果在不同层中，也可能出现相邻相同的值，删除起始的那个 i 即可
            if (i > pos && candidates[i] == candidates[i - 1]) {
                continue;
            }
            tmp.push_back(candidates[i]);
            sum += candidates[i];
            if (sum <= target) {
                dfs(i + 1);
            }
            sum -= candidates[i];
            tmp.pop_back();
        }
    };

    dfs(0);
    return res;
}

int main(int argc, char *argv[]) {
    // {
    // {1,1,6},
    // {1,2,5},
    // {1,7},
    // {2,6}
    // }
    printVectorVector(combinationSum2({10, 1, 2, 7, 6, 1, 5}, 8));
    // {
    // {1,2,2},
    // {5}
    // }
    printVectorVector(combinationSum2({2, 5, 2, 1, 2}, 5));
    // {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    printVectorVector(combinationSum2(
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
         1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
         1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
         1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
         1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        30));

    return 0;
}
