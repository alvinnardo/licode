#include "../template/head.h"
#include <bits/stdc++.h>

int countTriplets(vector<int> arr) {
    // 思路：异或前缀和
    // 时间 O(n)，空间 O(n)
    // 看了题解的思路
    // 异或前缀和 类似 前缀和
    // 可以快速求两个数之间的异或和
    // Si ^ Sj = i + 1 到 j 之间所有元素的异或和，
    // 因为 i < j，把 0 .. i 的重复的值异或成 0 了

    // 对于给定的 j，前面所有的可能 i .. j - 1 是 S{i-1} ^ S{j-1}
    // 后面所有的可能 j .. k 是 S{j-1} ^ S{k}
    // 则 S{i - 1} ^ S{j - 1} = S{j - 1} ^ S{k}
    // 所以在 i < k 下，满足 S{i - 1} = S{k} 即可

    int tmp = -1;
    unordered_map<int, int> umap;
    for (int a : arr) {
        tmp = tmp < 0 ? a : tmp ^ a;
        umap[tmp]++;
    }

    tmp = 0;
    int res = 0;
    res += umap[0];
    for (int a : arr) {
        tmp = tmp < 0 ? a : tmp ^ a;
        umap[tmp]--;
        if (umap[tmp]) {
            res += umap[tmp];
        }
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
                res += dp[i][j - 1] == dp[j][k];
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 4
    cout << countTriplets({2, 3, 1, 6, 7}) << endl;
    // 10
    cout << countTriplets({1, 1, 1, 1, 1}) << endl;
    // 0
    cout << countTriplets({2, 3}) << endl;
    // 8
    cout << countTriplets({7, 11, 12, 9, 5, 2, 7, 17, 22}) << endl;

    return 0;
}
