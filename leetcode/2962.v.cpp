#include "../template/head.h"
#include <bits/stdc++.h>

long long countSubarrays(vector<int> nums, int k) {
    // 思路：双指针
    // 时间 O(n)，空间 O(1)

    // 左边界之前的都成立
    // 个数成立，就把左边的加上
    // 个数成立即可，不需要有边界是最大值
    int maxv = *max_element(nums.begin(), nums.end());
    int cnt = 0, sz = nums.size();
    long long res = 0;
    int j = 0;
    for (int i = 0; i < sz; i++) {
        if (nums[i] == maxv) {
            cnt++;
        }

        // 做到左边界是 maxv
        while (cnt == k && nums[j] != maxv) {
            j++;
        }

        while (cnt > k) {
            j++;
            if (nums[j] == maxv) {
                cnt--;
            }
        }

        // 只要成立就可以加，不需要右边界是 maxv
        if (cnt == k) {
            res += j + 1;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    cout << countSubarrays({1, 3, 2, 3, 3}, 2) << endl;                // 6
    cout << countSubarrays({1, 4, 2, 1}, 3) << endl;                   // 0
    cout << countSubarrays({1, 3, 1, 1, 3, 1, 3, 3, 1, 3}, 2) << endl; // 31
    cout << countSubarrays({1, 3, 1, 1, 3, 1, 3}, 2) << endl;          // 9
    cout << countSubarrays({1, 3, 1, 1, 3, 1, 3, 3, 1, 3}, 3) << endl; // 19
    cout << countSubarrays({1, 3, 1, 1, 3, 1, 3, 3, 1, 3}, 4) << endl; // 9
    cout << countSubarrays({1}, 1) << endl;                            // 1
    cout << countSubarrays({2}, 1) << endl;                            // 1
    cout << countSubarrays({2}, 2) << endl;                            // 0
    vector<int> tmp;
    for (int i = 0; i < 100000; i++) {
        tmp.push_back(100000);
    }
    cout << countSubarrays(tmp, 1) << endl;

    return 0;
}
