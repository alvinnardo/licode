#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> sortArrayByParityII(vector<int> nums) {
    // 思路：双指针
    // 遍历数组，只要和下标奇偶不同就替换，直到相同
    // 遍历完后，两个指针不一定都到了最后，只要结果满足即可
    // 时间 O(n)，空间 O(1)
    int even = 0, odd = 1;
    int t = 0;
    for (int i = 0; i < nums.size();) {
        if ((nums[i] & 1) ^ (i & 1)) { // 奇偶不同
            if (nums[i] & 1) {
                t = nums[odd];
                nums[odd] = nums[i];
                nums[i] = t;
                odd += 2;
            } else {
                t = nums[even];
                nums[even] = nums[i];
                nums[i] = t;
                even += 2;
            }
        } else {
            i++;
        }
    }

    return nums;
}

int main(int argc, char *argv[]) {
    // {4,5,2,7}
    printVector(sortArrayByParityII({4, 2, 5, 7}));
    // {2,3}
    printVector(sortArrayByParityII({2, 3}));
    while (1) {
        vector<int> nums = getNRandom(1, 1000, 20);
        int cnt =
            count_if(nums.begin(), nums.end(), [&](int t) { return t & 1; });
        if (cnt == (nums.size() >> 1)) {
            printVector(nums);
            break;
        }
    }

    return 0;
}
