#include "../template/head.h"
#include <bits/stdc++.h>

long long distributeCandies(int n, int limit) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    // 遍历第一个，另外两个可以直接计算出来
    if (n > limit * 3) {
        return 0;
    }

    long long res = 0;
    int last_limit = (limit << 1);
    for (int i = 0; i <= min(n, limit); i++) {
        int other = n - i;

        if (other > last_limit) {
            continue;
        }

        // 先尝试全分配给第 2 个人
        // 如果第二个人超了，那么第三个人从 other - two 开始
        // 如果第二个人没超，那么第三个人从 0 开始
        // 第二个人往下降，第三个人往上升
        if (other < limit) {
            res += (other + 1);
        } else {
            res += (limit - other + limit + 1);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 3
    cout << distributeCandies(5, 2) << endl;
    // 10
    cout << distributeCandies(3, 3) << endl;

    return 0;
}
