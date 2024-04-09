#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

// n + 1 个 [1, n] 的数
// 鸽笼原理，最少有两个相同的数

int findDuplicate(vector<int> nums) {
    // 建立下标和值的链表
    // 由于有重复的数字，那么至少有两条边指向一个数字，
    // 那么一定存在环，且环的入口就是重复的数字
    // 记住有这个思路即可，一般想不到

    int fast = 0, slow = 0;

    // 第一次相遇，此时 f = 2s，且 f = s + nb
    // 则 s = nb
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // 走到入口为 a + nb，slow 已经走了 nb，则再走 a，就到入口
    fast = 0;
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int findDuplicate_bsearch(vector<int> nums) {
    // 二分查找
    // 没有重复元素时 cnt[i] <= i
    // 三种情况：不缺失元素，缺失元素小于 i，缺失元素大于 i
    // 都成立, 则找到第一个 cnt[i] > i 的就是结果
    // cnt[i] 是单调递增的，所以考虑用二分

    // 时间 O(nlogn)
    // 空间 O(1)
    int a = 1, b = nums.size() - 1;
    int ans = -1;
    while (a <= b) {
        int mid = a + (b - a) / 2;

        int cnt = 0;
        for (int num : nums) {
            if (num <= mid) {
                cnt++;
            }
        }
        if (cnt <= mid) {
            a = mid + 1;
        } else {
            b = mid - 1;
            ans = mid; // mid 可能是结果
        }
    }

    return ans;
}

int main(void) {
    cout << findDuplicate({1, 2, 3, 4, 2}) << endl;
    cout << findDuplicate({2, 2, 3, 4, 2}) << endl;
    cout << findDuplicate({3, 3, 3, 3, 3, 3}) << endl;
    return 0;
}
