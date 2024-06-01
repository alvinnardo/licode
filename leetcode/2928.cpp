#include "../template/head.h"
#include <bits/stdc++.h>

int distributeCandies(int n, int limit) {
    // 思路：先判断能否成立，然后固定前两个值
    // 时间 O(limit2)，空间 O(1)
    if (limit * 3 < n) {
        return 0;
    }

    int cnt = 0;
    for (int i = 0; i <= limit; i++) {
        for (int j = 0; j <= limit; j++) {
            int t = n - i - j;
            if (t >= 0 && t <= limit) {
                cnt++;
            }
        }
    }

    return cnt;
}

int main(int argc, char *argv[]) {

    // 3
    cout << distributeCandies(5, 2) << endl;

    // 10
    cout << distributeCandies(3, 3) << endl;

    return 0;
}
