#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> nums) {
    // 算法思路：统计负数的位置和个数
    // 遇到一次 0或者到末尾，处理一次
    int cnt = 0;
    int first_pos = -1, second_pos = -1; // 保存第一个和最后一个负数的位置
    int begin_pos = 0;
    long long maxv = INT_MIN;

    for (int i = 0; i <= nums.size(); i++) {
        if (i < nums.size() && nums[i] > maxv) {
            maxv = nums[i];
        }

        if (i < nums.size() && nums[i] == 0 || i == nums.size()) {
            // handle
            if (cnt & 1) { // 比较前 cnt - 1 个，和 后 cnt - 1 个的大小
                int next_pos = second_pos == -1 ? first_pos : second_pos;
                long long a = INT_MIN, b = INT_MIN;
                for (int j = begin_pos; j < next_pos; j++) {
                    if (a == INT_MIN) {
                        a = 1;
                    }
                    a *= nums[j];
                }
                for (int j = first_pos + 1; j < i; j++) {
                    if (b == INT_MIN) {
                        b = 1;
                    }
                    b *= nums[j];
                }
                maxv = a > b ? max(maxv, a) : max(maxv, b);
            } else { // 全相乘
                long long a = INT_MIN;
                for (int j = begin_pos; j < i; j++) {
                    if (a == INT_MIN) {
                        a = 1;
                    }
                    a *= nums[j];
                }
                maxv = max(maxv, a);
            }
            cnt = 0;
            begin_pos = i + 1;
            first_pos = -1;
            second_pos = -1;
        } else if (nums[i] < 0) {
            if (first_pos == -1) {
                first_pos = i;
            } else {
                second_pos = i;
            }
            cnt++;
        }
    }
    return maxv;
}

int main(void) {
    cout << maxProduct({2, 3, -2, 4}) << endl;
    cout << maxProduct({-2, 0, -1}) << endl;
    cout << maxProduct({-2, -1, -7, -3, 10, 1, 4, -1, -3, 9,  1, 2, 0, 3,
                        4,  8,  8,  0,  -3, 1, 7, 9,  10, -1, 2, 3, -1})
         << endl;
    cout << maxProduct({-1, -2}) << endl;
    cout << maxProduct({-1}) << endl;
    cout << maxProduct({0}) << endl;

    return 0;
}
