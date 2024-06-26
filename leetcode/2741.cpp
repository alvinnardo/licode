#include "../template/head.h"
#include <bits/stdc++.h>

/**
  排列型回溯 和 状压 DP 时间复杂度的区别
  以 [1, 2, 3, 4] 为例,
  1. a. 排列型回溯 需要保留位置的信息，[1, 3] 和 [3. 1] 是两次不同的遍历，
     b. 状压 DP 中不需要保留位置的信息，[1, 3] 和 [3, 1] 是相同的状态 1010，、
   并保存在一个 DP 数组中
  2. a. 排列型回溯 的时间复杂度为 O(n!)
     b. 状压 DP 的时间复杂度为 O(n * 2^n)，2^n 个状态，
   每个状态中需要遍历 n位， 判断是否用过 c.
   当 n > 4 时，O(n!) > O(n * 2^n)
  3. 状压 DP 中对主因素进行状态压缩，不需要对因变量进行压缩
*/
int specialPerm(vector<int> nums) {
    // 思路：二维状压 DP，每个特殊排列都是之前特殊排列尾部接上的
    // 一个维度保存状态，一个维度保存结束位置的下标
    // 时间 O(n^2 * 2^n)，空间 (n * 2^n)

    const int mod = 1e9 + 7;
    int sz = nums.size();
    int n = 1 << sz;
    vector<vector<long long>> dp(n, vector<long long>(sz));
    // 注意：由于数字的位置和数组的位置是相反的
    // 那么后面都按相反的做即可，不需要再进行多余的转换
    // 比如 0001 就是表示 [1,2,3,4] 中的 [1]，这样容易比较
    int mask = 1;
    for (int i = 0; i < sz; i++) {
        dp[mask][i] = 1;
        mask <<= 1;
    }

    for (int i = 1; i < n; i++) {      // 一维状态
        for (int j = 0; j < sz; j++) { // 二维结尾
            // 判断是否有该数字结尾
            if ((i & (1 << j))) {
                for (int k = 0; k < sz; k++) { // 找其他数
                    // 如果没处理过，则进行尝试
                    if ((i & (1 << k)) == 0 &&
                        (nums[j] % nums[k] == 0 || nums[k] % nums[j] == 0)) {
                        dp[i ^ (1 << k)][k] += dp[i][j];
                    }
                }
            }
        }
    }

    long long sum = 0;
    for (int i = 0; i < sz; i++) {
        sum = (sum + dp[n - 1][i]) % mod;
    }
    return sum;
}

int specialPerm1(vector<int> nums) {
    // 思路：回溯 + 剪枝
    // 时间 O(n!)，空间 O(n)
    // 14 个数，时间是 O(14!)，一般 10 个数用回溯不会超时

    int sz = nums.size();
    const int mod = 1e9 + 7;

    function<int(int)> dfs = [&](int pos) {
        if (pos == sz) {
            return 1;
        }

        int cnt = 0;
        for (int i = pos; i < sz; i++) {
            if (pos == 0 || nums[i] % nums[pos - 1] == 0 ||
                nums[pos - 1] % nums[i] == 0) {
                swap(nums[pos], nums[i]);
                cnt = ((long long)cnt + dfs(pos + 1)) % mod;
                swap(nums[pos], nums[i]);
            }
        }

        return cnt;
    };

    return dfs(0);
}

int main(int argc, char *argv[]) {
    // 2
    cout << specialPerm({2, 6}) << endl;
    // 2
    cout << specialPerm({2, 3, 6}) << endl;
    // 2
    cout << specialPerm({1, 4, 3}) << endl;
    cout << specialPerm({1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024}) << endl;
    cout << specialPerm({1, 2, 4, 6, 8, 10}) << endl;
    cout << specialPerm({1, 4, 3, 2}) << endl;
    cout << specialPerm({1, 2, 3, 4}) << endl;
    cout << specialPerm({1, 2, 4, 8}) << endl;

    return 0;
}
