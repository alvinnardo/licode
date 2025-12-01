#include "../template/head.h"
#include <bits/stdc++.h>

long long maxSubarraySum(vector<int> &&nums, int k) {
    // 题解：前缀和 + 数学
    // 时间 O(n)，空间 O(k)

    // 灵神的思路
    // 求前缀和之差 s[j]-s[i] 的最大值，满足 j > i，且 j 和 i 与 k 同余
    // 同余是说，i 加上 几倍的 k 能到 j
    // 过程中保存 s[i] 的最小值

    /*
    0 0
    1 a0
    2 a0 + a1
    3 a0 + a1 + a2
    4 a0 + a1 + a2 + a3
    5 a0 + a1 + a2 + a3 + a4
    6 a0 + a1 + a2 + a3 + a4 + a5
     */
    int sz = nums.size();
    vector<long long> vec(k, LLONG_MAX);
    long long pre{}, res{LLONG_MIN};
    int t{};
    vec[0] = 0;
    for (int i = 1; i <= sz; i++) {
        t = i % k;
        pre += nums[i - 1];
        if (i >= k) {
            res = max(res, pre - vec[t]);
        }
        vec[t] = min(vec[t], pre);
    }

    return res;
}

// 这道题想了 4 天左右
// 不管所有想法都是 O(n2) 的复杂度
// 后面想到试差分，最后试到前缀和
long long maxSubarraySum1(vector<int> &&nums, int k) {
    // 思路：前缀和 + 贪心
    // 时间 O(n)，空间 O(n)

    // 先计算能够成立的最大长度
    // 再计算能够形成最大长度的串的个数
    // 对于每一个最长串，按每 k 个获取子数组的和，用前缀和数组
    // 贪心获取最大的数

    // 测试 0 ~ k-1 开头的串，每个串进行贪心
    // 串的次数 (len - i) / k
    // 总的次数经过计算得到 len - (k - 1) / 2
    // 上面的式子经过模拟是 O(n - k/2) 时间的
    int len = nums.size();
    vector<long long> psum(len + 1);
    psum[0] = 0;
    for (int i = 0; i < len; i++) {
        psum[i + 1] = psum[i] + nums[i];
    }

    auto getSub = [&](int bng, int end) -> long long {
        return psum[end + 1] - psum[bng];
    };

    long long res = LLONG_MIN, pre = LLONG_MIN;
    long long t{};
    for (int i = 0; i < k; i++) {
        pre = LLONG_MIN;
        t = 0;

        // 左闭右闭
        int head = i, tail = head + k - 1;
        while (tail < len) { // 贪心
            t = getSub(head, tail);
            if (pre > 0 || t < pre) {
                pre += t;
            } else if (t > pre) {
                pre = t;
            }

            res = max(res, pre);
            head += k;
            tail = head + k - 1;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 3
    cout << maxSubarraySum({1, 2}, 1) << endl;
    // -10
    cout << maxSubarraySum({-1, -2, -3, -4, -5}, 4) << endl;
    // 4
    cout << maxSubarraySum({-5, 1, 2, -3, 4}, 2) << endl;
    // 40
    cout << maxSubarraySum({-22, -26, -36, -2, 17, 16, -44, -27, 7,  -46,
                            -48, -14, -33, 15, 25, 14, -37, 3,   -3, -16},
                           2)
         << endl;
    // 16
    cout << maxSubarraySum({0,  6, 0,  5,  -8, -7, 2,  -3, -7, 1,
                            -3, 6, -4, -4, 7,  -7, -9, 6,  9,  7},
                           2)
         << endl;

    return 0;
}
