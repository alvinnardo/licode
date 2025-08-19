#include "../template/head.h"
#include <bits/stdc++.h>

long long zeroFilledSubarray(vector<int> &&nums) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    long long tmp{}, res{};
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            tmp++;
        } else {
            tmp = 0;
        }

        res += tmp;
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 6
    cout << zeroFilledSubarray({1, 3, 0, 0, 2, 0, 0, 4}) << endl;
    // 9
    cout << zeroFilledSubarray({0, 0, 0, 2, 0, 0}) << endl;
    // 0
    cout << zeroFilledSubarray({2, 10, 2019}) << endl;

    return 0;
}
