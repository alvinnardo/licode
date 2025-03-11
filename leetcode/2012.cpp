#include "../template/head.h"
#include <bits/stdc++.h>

int sumOfBeauties(vector<int> nums) {
    // 思路：模拟
    // 时间 O(n)，空间 O(n)
    int res = 0;
    int sz = nums.size();
    vector<int> min_vec(sz, INT_MAX); // 保存最小值
    min_vec[sz - 1] = nums[sz - 1];
    for (int i = sz - 2; i >= 0; i--) {
        min_vec[i] = min(nums[i], min_vec[i + 1]);
    }

    int maxv = nums[0];
    for (int i = 1; i < sz - 1; i++) {
        if (nums[i] > maxv && nums[i] < min_vec[i + 1]) {
            res += 2;
        } else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1]) {
            res++;
        }
        maxv = max(maxv, nums[i]);
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 2
    cout << sumOfBeauties({1, 2, 3}) << endl;
    // 1
    cout << sumOfBeauties({2, 4, 6, 4}) << endl;
    // 0
    cout << sumOfBeauties({3, 2, 1}) << endl;
    // 2
    cout << sumOfBeauties({3502, 68932, 7686, 44181, 64025, 44001, 8302, 2099,
                           58053, 73269, 16957, 49532})
         << endl;

    return 0;
}
