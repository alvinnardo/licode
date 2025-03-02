#include "../template/head.h"
#include <bits/stdc++.h>

int countMaxOrSubsets(vector<int> nums) {
    // 思路：DFS + 位运算
    // 选或不选
    // 时间 O(2^n)，空间 O(logn)
    int res = 0;

    int tmp = 0;
    for (int num : nums) {
        tmp |= num;
    }

    function<void(int, int)> dfs = [&](int t, int pos) {
        if (pos >= nums.size()) {
            res += t == tmp;
            return;
        }

        dfs(t, pos + 1);
        dfs(t | nums[pos], pos + 1);
    };

    dfs(0, 0);
    return res;
}

int main(int argc, char *argv[]) {
    // 2
    cout << countMaxOrSubsets({3, 1}) << endl;
    // 7
    cout << countMaxOrSubsets({2, 2, 2}) << endl;
    // 6
    cout << countMaxOrSubsets({3, 2, 1, 5}) << endl;

    return 0;
}
