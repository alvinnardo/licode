#include "../template/head.h"
#include <bits/stdc++.h>

int findNumbers(vector<int> nums) {
    // 思路：遍历
    // 时间 O(nlogk)，空间 O(1)

    int sz = nums.size();
    int cnt = 0;
    auto check = [](int num) {
        int t = 0;
        while (num) {
            num /= 10;
            t++;
        }

        return t % 2 == 0;
    };

    for (int num : nums) {
        cnt += check(num);
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 2
    cout << findNumbers({12, 345, 2, 6, 7896}) << endl;
    // 1
    cout << findNumbers({555, 901, 482, 1771}) << endl;

    return 0;
}
