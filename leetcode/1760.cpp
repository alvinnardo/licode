#include "../template/head.h"
#include <bits/stdc++.h>

int minimumSize(vector<int> nums, int maxOperations) {
    // 思路：二分查找
    // 时间 O(nlogk)，空间 O(1)
    // 最开始的思路是红黑树 + 贪心，先求平均值，再每次取最大的拆分
    // 但结果不正确，也没有办法合理地证明
    // 快 0 点了，先 CV，扫到用 二分查找的方法了
    int maxv = *max_element(nums.begin(), nums.end());
    int i = 1, j = maxv, res = maxv;
    auto test = [&](int mid, int mops) -> bool {
        for (int num : nums) {
            if (num > mid) {
                int t = num / mid + (int)(num % mid > 0) - 1;
                if (t > mops) {
                    return false;
                }
                mops -= t;
            }
        }

        return true;
    };

    while (i <= j) {
        int mid = i + ((j - i) >> 1);
        if (test(mid, maxOperations)) {
            res = min(mid, res);
            j = mid - 1;
        } else {
            i = mid + 1;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 3
    cout << minimumSize({9}, 2) << endl;
    // 2
    cout << minimumSize({2, 4, 8, 2}, 4) << endl;
    // 7
    cout << minimumSize({7, 17}, 2) << endl;
    // 49
    cout << minimumSize({44, 27, 49, 100, 74, 30, 49, 43, 39, 25,
                         62, 10, 64, 93,  40, 94, 71, 63, 98, 11},
                        11)
         << endl;

    return 0;
}
