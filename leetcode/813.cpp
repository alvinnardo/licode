#include "../template/head.h"
#include <bits/stdc++.h>

double largestSumOfAverages_dfs(vector<int> nums, int k) {
    // 思路：记忆化搜索
    // 时间 O(n2k)，空间 O(nk)

    vector<vector<double>> mem(nums.size(), vector<double>(k + 1, -1));
    function<double(int, int)> dfs = [&](int pos, int level) -> double {
        if (mem[pos][level] != -1) {
            return mem[pos][level];
        }

        if (level == 1) {
            double res = accumulate(nums.begin(), nums.begin() + pos + 1, 0) *
                         1.0 / (pos + 1);

            mem[pos][level] = res;
            return res;
        }

        int j = pos, sum = 0;
        double maxv = -1;
        while (j >= level - 1) {
            sum += nums[j];
            maxv = max(maxv, dfs(j - 1, level - 1) + sum * 1.0 / (pos - j + 1));
            j--;
        }

        mem[pos][level] = maxv;
        return maxv;
    };
    return dfs(nums.size() - 1, k);
}

double largestSumOfAverages_dp(vector<int> nums, int k) {
    // 思路：DP
    // 时间 O(n2k)，空间 O(nk)，省去了调用栈的空间和时间
    /* clang-format off */
    // 前面是组号
    // 递推公式: dp[k][i + j] = max{dp[k-1][i - 1] + sum(i - j .. i) / j}
    /* clang-format on */

    vector<vector<double>> dp(k + 1, vector<double>(nums.size()));
    double sum = 0;

    // 组成第 1 组的
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        dp[1][i] = sum / (i + 1);
    }

    // 组成后续组的
    for (int p = 2; p <= k; p++) {
        for (int i = p - 1; i < nums.size(); i++) {
            double sum = 0;
            for (int j = 0; j < nums.size() - i; j++) {
                sum += nums[i + j];
                dp[p][i + j] =
                    max(dp[p][i + j], dp[p - 1][i - 1] + sum / (j + 1));
            }
        }
    }

    return dp[k][nums.size() - 1];
};
double largestSumOfAverages(vector<int> nums, int k) {
    // 思路：DP
    // 只和上一组有关，优化空间
    // 时间 O(n2k)，空间 O(n)

    vector<double> dp(nums.size());

    // 第一组只能从头开始，放在下面的循环中，每一个都能做开头了
    double sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        dp[i] = sum / (i + 1);
    }

    for (int p = 2; p <= k; p++) {
        // 会更改上一组的记录，所以需要存一下
        vector<double> level(nums.size());
        for (int i = p - 1; i < nums.size(); i++) {
            double sum = 0;
            for (int j = 0; j < nums.size() - i; j++) {
                sum += nums[i + j];
                level[i + j] = max(level[i + j], dp[i - 1] + sum / (j + 1));
            }
        }
        dp = level;
    }
    return dp[nums.size() - 1];
}

int main(int argc, char *argv[]) {
    // 20
    cout << largestSumOfAverages({9, 1, 2, 3, 9}, 3) << endl;
    // 20.5
    cout << largestSumOfAverages({1, 2, 3, 4, 5, 6, 7}, 4) << endl;

    return 0;
}
