#include "../template/head.h"
#include <bits/stdc++.h>
bool predictTheWinner(vector<int> nums) {
    // 思路：模拟 + DFS
    // 时间 O(2^n), 空间 O(n)
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum == 0) {
        return true;
    }

    int sz = nums.size();
    int target = sum & 1 ? sum / 2 + 1 : sum / 2;

    function<int(int, int, int, int, int)> dfs =
        [&](int chooser, int left, int right, int sum1, int sum2) {
            if (sum & 1) {
                if (sum1 >= target) {
                    return 1;
                }
                if (sum2 >= target) {
                    return 0;
                }
            } else {
                if (chooser) {
                    if (sum1 >= target) {
                        return 1;
                    }
                } else {
                    if (sum2 > target) {
                        return 0;
                    }
                }
            }

            if (chooser) {
                if (dfs(0, left + 1, right, sum1 + nums[left], sum2) ||
                    dfs(0, left, right - 1, sum1 + nums[right], sum2)) {
                    return 1;
                }
                return 0;
            }

            if (!dfs(1, left + 1, right, sum1, sum2 + nums[left]) ||
                !dfs(1, left, right - 1, sum1, sum2 + nums[right])) {
                return 0;
            }
            return 1;
        };

    return dfs(1, 0, sz - 1, 0, 0);
}

int main(int argc, char *argv[]) {
    // 0
    cout << predictTheWinner({1, 5, 2}) << endl;
    // 1
    cout << predictTheWinner({1, 5, 233, 7}) << endl;
    // 1
    cout << predictTheWinner({1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
                              11, 12, 13, 14, 15, 16, 17, 18, 19, 20})
         << endl;
    // 1
    cout << predictTheWinner({1, 1, 1}) << endl;
    // 1
    cout << predictTheWinner({1, 1, 1, 1}) << endl;
    // 1
    cout << predictTheWinner({1, 1, 1, 1, 1}) << endl;
    // 1
    cout << predictTheWinner({20, 3, 1, 2, 4, 5, 7, 6, 8}) << endl;
    // 1
    cout << predictTheWinner(
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0})
         << endl;

    // 1
    cout << predictTheWinner({1, 5, 2, 4, 6}) << endl;

    return 0;
}
