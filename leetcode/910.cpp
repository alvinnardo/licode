#include "../template/head.h"
#include <bits/stdc++.h>

int smallestRangeII(vector<int> nums, int k) {
    // 思路：模拟
    // 先求平均值，再往平均值靠，如果数据中有平均值则分类讨论一下
    // 时间 O(n)，空间 O(1)

    int sum = accumulate(nums.begin(), nums.end(), 0);
    int maxv = INT_MIN, minv = INT_MAX, avg_num = 0;
    double avg = sum * 1.0 / nums.size();
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] * 1.0 < avg) {
            nums[i] += k;
        } else if (nums[i] * 1.0 > avg) {
            nums[i] -= k;
        } else {
            avg_num++;
            continue;
        }

        maxv = max(maxv, nums[i]);
        minv = min(minv, nums[i]);
    }

    int avg_int = (int)avg;
    if (avg_num == 0) {
        return maxv - minv;
    } else if (avg_num == 1) {
        return min(max(maxv, avg_int + k) - min(minv, avg_int + k),
                   max(maxv, avg_int - k) - min(minv, avg_int - k));
    }

    vector<int> vec{
        max(maxv, avg_int + k) - min(minv, avg_int + k), // up up
        max(maxv, avg_int + k) - min(minv, avg_int - k), // up down
        max(maxv, avg_int - k) - min(minv, avg_int - k)  // down down
    };
    return *min_element(vec.begin(), vec.end());
}

int main(int argc, char *argv[]) {

    // // 0
    // cout << smallestRangeII({1}, 0) << endl;
    // // 6
    // cout << smallestRangeII({0, 10}, 2) << endl;
    // // 3
    // cout << smallestRangeII({1, 3, 6}, 3) << endl;
    // // 0
    // cout << smallestRangeII({1, 1, 1, 1, 1}, 3) << endl;
    // 47
    cout << smallestRangeII({45, 81, 58, 1, 92, 66, 96, 52, 7, 78, 94, 8, 17,
                             65, 93, 43, 77},
                            24)
         << endl;

    // printVector(getNRandom(1, 100, 17));
    cout << getRandom(10, 26) << endl;
    cout << getRandom(10, 26) << endl;
    cout << getRandom(10, 26) << endl;
    cout << getRandom(10, 26) << endl;
    cout << getRandom(10, 26) << endl;
    cout << getRandom(10, 26) << endl;

    return 0;
}
