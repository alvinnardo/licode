#include "../template/head.h"
#include <bits/stdc++.h>

int findClosestNumber(vector<int> nums) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    int res = INT_MAX;
    for (int num : nums) {
        int ta = abs(num), tb = abs(res);
        if (ta < tb) {
            res = num;
        } else if (ta == tb && num > res) {
            res = num;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 1
    cout << findClosestNumber({-4, -2, 1, 4, 8}) << endl;
    // 1
    cout << findClosestNumber({2, -1, 1}) << endl;

    return 0;
}
