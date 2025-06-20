#include "../template/head.h"
#include <bits/stdc++.h>

int maxDistance(string s, int k) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    int a{}, b{}, c{}, d{};
    int res = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'N') {
            a++;
        } else if (s[i] == 'S') {
            b++;
        } else if (s[i] == 'E') {
            c++;
        } else {
            d++;
        }

        // 每走一步测试一下
        int mintot = min(a, b) + min(c, d); // 最小的和，然后用 k 去补
        // 把负的变成正的，看负的和能弥补的多少
        // 如果能弥补，把弥补的变成正的，剩下的负的还是需要减去的
        int t = k;
        if (mintot < t) {
            t = mintot;
            mintot = 0;
        } else {
            mintot -= t;
        }
        res = max(res, max(a, b) + max(c, d) + t - mintot);
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 3
    cout << maxDistance("NWSE", 1) << endl;
    // 6
    cout << maxDistance("NSWWEW", 3) << endl;

    return 0;
}
