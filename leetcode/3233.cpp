#include "../template/head.h"
#include <bits/stdc++.h>

int nonSpecialCount(int l, int r) {
    // 思路：素筛
    // 本质上就是找素数的个数
    // 时间 O(logn)，空间 O(logn)

    int cnt = 0, len = sqrt(r);
    vector<int> vec(len + 1, 1);
    for (int i = 2; i <= sqrt(len); i++) {
        if (vec[i] == 0) {
            continue;
        }
        int j = i;
        while (true) {
            j += i;
            if (j > len) {
                break;
            }
            vec[j] = 0;
        }
    }

    int left = sqrt(l);
    if (left * left < l) {
        left++;
    }
    for (int i = max(2, left); i <= len; i++) {
        cnt += vec[i];
    }

    return r - l + 1 - cnt;
}

int main(int argc, char *argv[]) {
    // 3
    cout << nonSpecialCount(5, 7) << endl;
    // 11
    cout << nonSpecialCount(4, 16) << endl;

    return 0;
}
