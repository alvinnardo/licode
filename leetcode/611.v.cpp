#include "../template/head.h"
#include <bits/stdc++.h>

int triangleNumber(vector<int> &&nums) {
    // 思路：排序 + 双指针
    // 时间 O(n2)，空间 O(1)
    sort(nums.begin(), nums.end());
    int sz = nums.size();
    int res{};
    for (int i = 0; i < sz; i++) {
        int k = i + 2;
        if (k == sz) {
            break;
        }

        int tot{};
        for (int j = i + 1; j < sz; j++) {
            tot = nums[i] + nums[j];
            while (k <= j || (k + 1 < sz && nums[k + 1] < nums[i] + nums[j])) {
                k++;
            }

            if (k < sz && nums[k] < tot) {
                res += k - j;
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 3
    cout << triangleNumber({2, 2, 3, 4}) << endl;
    // 4
    cout << triangleNumber({4, 2, 3, 4}) << endl;

    return 0;
}
