#include "../template/head.h"
#include <bits/stdc++.h>

using namespace std;
int wiggleMaxLength(vector<int> nums) {
    // 优化为 O(n)
    // 比较后面和前面的两个即可
    // 如果后面的更大，那么能够从前面为负数的摆动递增过来，且另一个值不变
    // 如果后面的更小，那么能够从前面为正数的摆动递增过来，且另一个值不变
    int a = 1, b = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1]) {
            b = a + 1;
        } else if (nums[i] < nums[i - 1]) {
            a = b + 1;
        }
    }

    return max(a, b);
}

int wiggleMaxLength_my(vector<int> nums) {

    // dp[i].first 以当前 nums[i] 为结尾的，正数长度
    // dp[i].second 以当前 nums[i] 为结尾了，负数长度
    vector<pair<int, int>> dp(nums.size(), pair<int, int>({1, 1}));

    int max_first = 1, max_second = 1;
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] - nums[j] > 0) {
                dp[i].first = max(dp[i].first, dp[j].second + 1);
                max_first = max(dp[i].first, max_first);
            } else if (nums[i] - nums[j] < 0) {
                dp[i].second = max(dp[i].second, dp[j].first + 1);
                max_second = max(dp[i].second, max_second);
            }
        }
    }

    return max(max_first, max_second);
}

int main(void) {
    // 6
    cout << wiggleMaxLength({1, 7, 4, 9, 2, 5}) << endl;
    // 7
    cout << wiggleMaxLength({1, 17, 5, 10, 13, 15, 10, 5, 16, 8}) << endl;
    // 2
    cout << wiggleMaxLength({1, 2, 3, 4, 5, 6, 7, 8, 9}) << endl;
    // 2
    cout << wiggleMaxLength({1, 2}) << endl;
    // 1
    cout << wiggleMaxLength({1}) << endl;
    // 2
    cout << wiggleMaxLength({2, 1}) << endl;

    return 0;
}
