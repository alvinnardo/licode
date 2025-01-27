#include "../template/head.h"
#include <bits/stdc++.h>

int jump(vector<int> nums) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)

    // 直接就到了，不用跳
    if (nums.size() == 1) {
        return 0;
    }

    int step = 0, now = -1, maxv = 0;
    while (true) {
        step++; // 跳一步
        int t = maxv;
        // 判断这一步能跳到最远的位置
        for (int i = now + 1; i <= t; i++) {
            maxv = max(maxv, i + nums[i]);
            if (maxv >= nums.size() - 1) {
                return step;
            }
        }

        now = t; // 更新下一步的起点
    }

    return 0;
}

int main(int argc, char *argv[]) {
    // 2
    cout << jump({2, 3, 1, 1, 4}) << endl;
    // 2
    cout << jump({2, 3, 0, 1, 4}) << endl;
    // 3
    cout << jump({7,  13, 13, 15, 14, 17, 1,  2,  19, 0,  0,  8, 15, 5, 11,
                  10, 13, 12, 14, 15, 11, 13, 17, 13, 20, 10, 7, 8,  8, 3})
         << endl;
    // 0
    cout << jump({0}) << endl;

    return 0;
}
