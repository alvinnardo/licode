#include <bits/stdc++.h>
using namespace std;

// 最大元素出现个数的子数组个数
long long countSubarrays(const vector<int> &nums, int k) {
    // 双指针

    // 比如 1 3 3 是 2 个,
    // 1 3 3 1 是 2 + 2 个，
    // 1 3 3 1 1 是 2 + 2 + 2 个
    // 1 3 3 1 1 3 是 2 + 2 + 2 + 3 个

    // 双指针内保持 k 个最大值
    int left = 0, right = 0;
    int max_cnt = 0;
    int cur_cnt = 0;
    int64_t tot = 0;
    int sz = nums.size();

    int maxv = *max_element(nums.begin(), nums.end());
    while (right < sz) {
        if (nums[right] == maxv) {
            max_cnt++;
            while (max_cnt > k) { // 先把多的去掉
                if (nums[left] == maxv) {
                    max_cnt--;
                }
                left++;
            }
            if (max_cnt == k) { // 再把左边不是的去掉
                while (nums[left] != maxv) {
                    left++;
                }
                cur_cnt = left + 1;
            }
        }
        right++;

        tot += cur_cnt;
    }

    return tot;
}

int main(void) {
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
