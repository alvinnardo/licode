#include "../template/head.h"
#include <bits/stdc++.h>

int minZeroArray(vector<int> nums, vector<vector<int>> queries) {
    // 思路：二分 + 差分数组 + 贪心
    // 时间 O(logn(m + n))，空间 O(n)
    int m = nums.size(), n = queries.size();
    int a = 0, b = n, mid = 0;
    vector<int> vec(m + 1);
    int res = -1;
    while (a <= b) {
        mid = a + ((b - a) >> 1);
        for (int i = m - 1; i >= 0; i--) {
            vec[i] = i == 0 ? nums[0] : nums[i] - nums[i - 1];
        }

        for (int i = 0; i < mid; i++) {
            vec[queries[i][0]] -= queries[i][2];
            vec[queries[i][1] + 1] += queries[i][2];
        }

        bool valid = true;
        for (int i = 0; i < m; i++) {
            if (i > 0) {
                vec[i] += vec[i - 1];
            }

            if (vec[i] > 0) {
                valid = false;
                break;
            }
        }

        if (valid) {
            res = mid;
            b = mid - 1;
        } else {
            a = mid + 1;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 2
    cout << minZeroArray({2, 0, 2}, {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}}) << endl;
    // -1
    cout << minZeroArray({4, 3, 2, 1}, {{1, 3, 2}, {0, 2, 1}}) << endl;

    return 0;
}
