#include "../template/head.h"
#include <bits/stdc++.h>
int maxOperations(vector<int> nums) {
    // 学习代码
    int cnt = 1, last = nums[0] + nums[1];
    // 如果 nums.size() - 1 是倒数第二个元素
    // 如果奇数个，停在倒数第三个元素上
    // 如果偶数个，停在倒数第二个元素上
    for (int i = 2; i < nums.size() - 1; i += 2) {
        if (nums[i] + nums[i + 1] == last) {
            cnt++;
        } else {
            break;
        }
    }

    return cnt;
}

int maxOperations_my(vector<int> nums) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)

    if (nums.size() < 2) {
        return 0;
    }

    int cnt = 0;
    int last = -1;
    for (int i = 0; i < nums.size(); i += 2) {
        if (last == -1) {
            last = nums[i] + nums[i + 1];
            cnt = 1;
        } else if (i + 1 == nums.size()) {
            break;
        } else if (nums[i] + nums[i + 1] == last) {
            cnt++;
        } else {
            break;
        }
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 2
    cout << maxOperations({3, 2, 1, 4, 5}) << endl;
    // 1
    cout << maxOperations({3, 2, 6, 1, 4}) << endl;

    return 0;
}
