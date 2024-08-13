#include "../template/head.h"
#include <bits/stdc++.h>

bool isArraySpecial(vector<int> nums) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    bool first = (nums[0] & 1) ? 1 : 0; // 偶数
    bool second = !first;               // 奇数

    // 循环展开优化
    for (int i = 0; i < nums.size(); i += 2) {
        if ((nums[i] & 1) != first) {
            return false;
        }
        if (i + 1 < nums.size()) {
            if ((nums[i + 1] & 1) != second) {
                return false;
            }
        }
    }

    return 1;
}

int main(int argc, char *argv[]) {

    // 1
    cout << isArraySpecial({1}) << endl;
    // 1
    cout << isArraySpecial({2, 1, 4}) << endl;
    // 0
    cout << isArraySpecial({4, 3, 1, 6}) << endl;

    return 0;
}
