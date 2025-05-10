#include "../template/head.h"
#include <bits/stdc++.h>

long long minSum(vector<int> nums1, vector<int> nums2) {
    // 思路：分类讨论
    // 时间 O(m + n)，空间 O(1)

    // 根据两边拥有 0 的个数讨论
    // 把 0 改成最小值 1 进行比较
    long long suma = 0, sumb = 0;
    int cnta = 0, cntb = 0;
    for (int i = 0; i < nums1.size(); i++) {
        suma += nums1[i];
        cnta += nums1[i] == 0;
    }
    for (int i = 0; i < nums2.size(); i++) {
        sumb += nums2[i];
        cntb += nums2[i] == 0;
    }

    // 取两个的较大值
    if (cnta == 0 && cntb == 0) {
        return suma == sumb ? suma : -1;
    } else if (cnta == 0) {
        return suma < sumb + cntb ? -1 : suma;
    } else if (cntb == 0) {
        return sumb < suma + cnta ? -1 : sumb;
    }

    return max(suma + cnta, sumb + cntb);
}

int main(int argc, char *argv[]) {
    // 12
    cout << minSum({3, 2, 0, 1, 0}, {6, 5, 0}) << endl;
    // -1
    cout << minSum({2, 0, 2, 0}, {1, 4}) << endl;

    return 0;
}
