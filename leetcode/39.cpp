#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> combinationSum(vector<int> candidates, int target) {

    // 思路: DP, 中间有去重的要求，只要保证后加的数字不要比数组最后一个小即可
    int sz = candidates.size();
    vector<vector<vector<int>>> dp(target + 1);

    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < sz; j++) {
            if (i - candidates[j] == 0) {
                dp[i].push_back({candidates[j]});
            } else if (i - candidates[j] > 0 &&
                       !dp[i - candidates[j]].empty()) {
                for (auto &t : dp[i - candidates[j]]) {
                    if (candidates[j] >= t.back()) {
                        dp[i].push_back(t);
                        dp[i].back().push_back(candidates[j]);
                    }
                }
            }
        }
    }

    return dp[target];
}

int main(void) {

    printVectorVector(combinationSum({2, 3, 6, 7}, 7));
    printVectorVector(combinationSum({1, 3, 6, 7}, 40));

    return 0;
}
