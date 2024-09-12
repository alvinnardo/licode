#include "../template/head.h"
#include <bits/stdc++.h>

int maxNumOfMarkedIndices(vector<int> nums) {
    // 思路：贪心 + 双指针，从中间断开，尽可能选中全部
    // 时间 O(nlogn)，空间 O(logn)
    sort(nums.begin(), nums.end());
    int sz = nums.size();
    int pos = (sz & 1) ? (sz >> 1) : (sz >> 1) - 1, cnt = 0;
    int mid = pos + 1;
    for (int i = sz - 1; i >= mid; i--) {
        int t = nums[i] >> 1;
        while (pos >= 0 && nums[pos] > t) {
            pos--;
        }

        if (pos >= 0) {
            cnt += 2;
        }

        pos--; // 该位置不能用了
        if (pos < 0) {
            break;
        }
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 2
    cout << maxNumOfMarkedIndices({3, 5, 2, 4}) << endl;
    // 4
    cout << maxNumOfMarkedIndices({9, 2, 5, 4}) << endl;
    // 0
    cout << maxNumOfMarkedIndices({7, 6, 8}) << endl;
    // 30
    cout << maxNumOfMarkedIndices({464, 217, 940, 58,  479, 856, 170, 716,
                                   726, 518, 198, 523, 565, 78,  163, 370,
                                   823, 759, 429, 128, 202, 740, 190, 308,
                                   124, 819, 874, 407, 804, 377})
         << endl;
    // 6
    cout << maxNumOfMarkedIndices({58, 78, 429, 464, 874, 940}) << endl;
    // 32
    cout << maxNumOfMarkedIndices({32, 19, 44, 7,  64, 82, 59, 84, 41, 69, 7,
                                   50, 40, 22, 52, 12, 17, 37, 78, 98, 27, 40,
                                   26, 82, 30, 3,  98, 37, 96, 61, 54, 27, 79})
         << endl;

    // printVector(getNRandom(1, 5000, 45));
    return 0;
}
