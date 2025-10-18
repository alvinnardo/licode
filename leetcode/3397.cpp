#include "../template/head.h"
#include <bits/stdc++.h>

int maxDistinctElements(vector<int> &&nums, int k) {
    // 思路：贪心 + 模拟
    // 时间 O(nlogn)，空间 O(1)

    // 先排序，让小的更小，从小往上尽可能累加
    // 让大的更大，从大往上尽可能减少
    // 因为不好判断这两个的值的结果是否相同，所以都做取最大值

    int sz = nums.size();
    int heap_min = INT_MAX, heap_max = INT_MIN;
    int tmin{}, tmax{}, cnt_min{}, cnt_max{};
    std::ranges::sort(nums);
    for (int i = 0, ri = sz - i - 1; i < sz; i++, ri--) {
        if (i == 0) {
            heap_min = nums[i] - k;
            heap_max = nums[ri] + k;
            cnt_min = cnt_max = 1;
            continue;
        }

        // 累小的，想要贪心的取 heap_min + 1，看范围是否能满足
        tmin = nums[i] - k;
        tmax = nums[i] + k;

        int want = heap_min + 1;
        if (tmin <= want && want <= tmax) {
            cnt_min++;
            heap_min = want;
        } // 由于差距太大，能累加的最小值改成该数能生成的最小值
        else if (tmin > want) {
            cnt_min++;
            heap_min = tmin;
        } // 该数生成的范围不能满足想要的最小值，跳过该数

        tmin = nums[ri] - k;
        tmax = nums[ri] + k;

        want = heap_max - 1;
        if (tmin <= want && want <= tmax) {
            cnt_max++;
            heap_max = want;
        } else if (tmax < want) {
            cnt_max++;
            heap_max = tmax;
        }
    }

    return max(cnt_min, cnt_max);
}

int main(int argc, char *argv[]) {
    // 6
    cout << maxDistinctElements({1, 2, 2, 3, 3, 4}, 2) << endl;
    // 3
    cout << maxDistinctElements({4, 4, 4, 4}, 1) << endl;

    return 0;
}
