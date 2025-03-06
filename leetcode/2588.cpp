#include "../template/head.h"
#include <bits/stdc++.h>
long long beautifulSubarrays(vector<int> nums) {
    // 之前题读的有些问题，对取两个值然后 {0} 的结果是 1 有疑问
    // 其实题目说的就是任意取两个值，最后使区间内都是 0 即可

    // 前面的做法是按隔数取值做的，有些繁杂
    // 这里优化一下，基本逻辑是不变的
    long long res = 0;
    unordered_map<int, long long> umap;
    umap[0]++;
    int t = 0;
    for (int num : nums) {
        t ^= num;
        if (umap.count(t)) {
            res += umap[t];
        }
        umap[t]++;
    }

    return res;
}

// 玄学：昨天刚做了一道异或前缀和的题
// 今天就推了一道这个类型的题
// 主要昨天的题不是推的，是自己找的
long long beautifulSubarrays1(vector<int> nums) {
    // 思路：异或前缀和 + 哈希表
    // 时间 O(n)，空间 O(n)

    // if (nums.size() < 2) {
    //     return 0;
    // }

    // 求区间先想到用前缀和
    // 然后是偶数个 1，想到用异或，所以用异或前缀和
    // 满足区间内异或前缀和是 0，则 Si ^ Sj = 0，即 Si = Sj 即可
    long long res = 0;
    unordered_map<int, int> umap; // 范围是 1e5，则用哈希表减少时间

    // 注 i < j 的，所以要相隔一个
    int posi = -1, posj = 0; // 指向但不取，循环时取
    int xsumi = 0, xsumj = 0;
    while (posj < nums.size()) {
        // 在这里取
        if (posi < 0) {
            posi++;
        } else {
            xsumi ^= nums[posi++];
        }

        xsumj ^= nums[posj++];
        umap[xsumi]++;

        if (umap.count(xsumj)) {
            res += umap[xsumj];
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 2
    cout << beautifulSubarrays({4, 3, 1, 2, 4}) << endl;
    // 0
    cout << beautifulSubarrays({1, 10, 4}) << endl;
    // 1
    cout << beautifulSubarrays({0}) << endl;
    // 3
    cout << beautifulSubarrays({0, 0}) << endl;
    // 6
    cout << beautifulSubarrays({0, 0, 0}) << endl;

    return 0;
}
