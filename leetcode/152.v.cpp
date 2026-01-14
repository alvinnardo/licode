#include "../template/head.h"
#include <bits/stdc++.h>

int maxProduct1(vector<int> &&nums) {
    int maxv{nums[0]};

    // 需要栈空间 O(n)，不需要记忆化搜索
    // 即便转为记忆化搜索也是空间 O(n)
    std::function<pair<int, int>(int)> dfs = [&](int pos) -> pair<int, int> {
        if (pos == 0) {
            return {nums[pos], nums[pos]};
        }

        auto ret = dfs(pos - 1);
        int mxv =
            max(max(ret.first * nums[pos], ret.second * nums[pos]), nums[pos]);
        int miv =
            min(min(ret.first * nums[pos], ret.second * nums[pos]), nums[pos]);
        maxv = max(maxv, mxv);
        return {mxv, miv};
    };

    dfs(nums.size() - 1);
    return maxv;
}

// 改为 DP
int maxProduct(vector<int> &&nums) {
    // 思路：DP
    // 时间 O(n)，空间 O(1)
    int maxv{nums[0]}; // 过程中的最大值
    int sz = nums.size();
    int a{nums[0]}, b{nums[0]}, t{};
    for (int i = 1; i < sz; ++i) {
        t = max(max(a * nums[i], b * nums[i]), nums[i]);
        b = min(min(a * nums[i], b * nums[i]), nums[i]);
        a = t;

        maxv = max(a, maxv);
    }

    return maxv;
}

int main(int argc, char *argv[]) {

    // 6
    cout << maxProduct({2, 3, -2, 4}) << endl;
    // 0
    cout << maxProduct({-2, 0, -1}) << endl;
    // 90720
    cout << maxProduct({-2, -1, -7, -3, 10, 1, 4, -1, -3, 9,  1, 2, 0, 3,
                        4,  8,  8,  0,  -3, 1, 7, 9,  10, -1, 2, 3, -1})
         << endl;
    // 2
    cout << maxProduct({-1, -2}) << endl;
    // -1
    cout << maxProduct({-1}) << endl;
    // 0
    cout << maxProduct({0}) << endl;

    return 0;
}
