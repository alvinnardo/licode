#include "../template/head.h"
#include <bits/stdc++.h>

int countTriplets(vector<int> arr) {
    // 思路：异或前缀和 + 双指针 + 哈希表
    // 时间 O(n)，空间 O(n)
    // 看了题解的思路
    // 异或前缀和 类似 前缀和
    // 可以快速求两个数之间的异或和

    // 以后的前缀和都加上哨兵，方便加减和树状数组的实现

    // S0 = 0, S1 = a0, ...
    // Si = a0 .. a1 .. a{i-1}
    // Sj ^ Si = i 到 j - 1 之间所有元素的异或和，
    // 因为 i < j，把 0 .. i - 1 的重复的值异或成 0 了

    // 对于给定的 j，前面所有的可能 i .. j - 1 是 Sj ^ Si
    // 后面所有的可能 j .. k 是 S{k+1} ^ Sj
    // 则 Sj ^ Si = S{k+1} ^ Sj
    // 所以在 i < k 下，满足 Si = S{k+1} 即可

    if (arr.size() < 2) {
        return 0;
    }

    // i 从 0 开始，和 k + 1 比较，则从 2 开始
    int pos1 = 0, possk1 = 2;
    // 双指针，保存两个异或前缀和
    // pos 是在 S 数组中的位置
    // 下面是两个异或前缀和的值
    int si = 0, sk1 = arr[0] ^ arr[1];
    int res = 0;
    // umap 保存可能的值以及位置，用于后面统计 j 的个数
    unordered_map<int, vector<int>> umap;

    while (possk1 < arr.size() + 1) {
        umap[si].push_back(pos1);
        if (umap.count(sk1)) {
            for (int num : umap[sk1]) {
                // 如果 Si == S{k + 1}，
                // 则需要获取 j 的可能位置个数为 k + 1 - i - 1
                res += possk1 - num - 1;
            }
        }

        if (possk1 < arr.size()) {
            si ^= arr[pos1];
            sk1 ^= arr[possk1];
        }
        pos1++;
        possk1++;
    }

    return res;
}

int countTriplets2(vector<int> arr) {
    // 思路：枚举 + 哈希表
    // 时间 O(n2)，空间 O(n)
    // 枚举 j 的位置，遍历左边保存在哈希表中，在遍历右边从哈希表里取值
    int len = arr.size(), res = 0;

    unordered_map<int, int> umap;
    for (int j = 1; j < len; j++) {
        umap.clear();
        int tmp = 0;
        // 从 j 往左
        for (int i = j - 1; i >= 0; i--) {
            tmp = i == j - 1 ? arr[i] : tmp ^ arr[i];
            umap[tmp]++;
        }

        tmp = 0;
        // 从 j 往右
        for (int k = j; k < len; k++) {
            tmp = k == j ? arr[j] : tmp ^ arr[k];
            if (umap.count(tmp)) {
                res += umap[tmp];
            }
        }
    }

    return res;
}

int countTriplets1(vector<int> arr) {
    // 思路：模拟
    // 时间 O(n3)，空间 O(n2)
    // 先保存一下中间结果
    int len = arr.size();
    vector<vector<int>> dp(len, vector<int>(len, -1));
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (j == i) {
                dp[i][j] = arr[i];
            } else {
                dp[i][j] = dp[i][j - 1] ^ arr[j];
            }
        }
    }

    int res = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            for (int k = j; k < len; k++) {
                if (dp[i][j - 1] == dp[j][k]) {
                    cout << i << ", " << j << ", " << k << endl;
                }
                res += dp[i][j - 1] == dp[j][k];
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 4
    // cout << countTriplets({2, 3, 1, 6, 7}) << endl;
    // // 10
    // cout << countTriplets({1, 1, 1, 1, 1}) << endl;
    // 0
    cout << countTriplets({2, 3}) << endl;
    // 8
    cout << countTriplets({7, 11, 12, 9, 5, 2, 7, 17, 22}) << endl;

    return 0;
}
