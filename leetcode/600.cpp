#include "../template/head.h"
#include <bits/stdc++.h>

int findIntegers(int n) {
    // 思路：BFS
    // 时间 O(logn)，空间 O(logn)
    // 1. 首先，我先用循环模拟了个数，发现不相邻的个数要比相邻个数要少得多
    //    且小于等于 1e9 的结果是 2e6 个，复杂度并不高
    // 2. 根据末尾数字的递推关系，以 0 结尾可以接 0 和 1；以 1 结尾的只能接 0

    int cnt = 0;
    queue<int> qu;
    qu.push(0);

    int target = (n >> 1) + 1;
    while (!qu.empty()) {
        int t = qu.front(); // 这里强转一下，以防溢出
        qu.pop();
        if (t > n) { // 不继续了
            break;
        }

        cnt++;

        if (t > target) {
            continue;
        }

        if (t & 1) { // 以 1 结尾的只能接 0
            qu.push(t << 1);
        } else {
            if (t != 0) { // 注意 0 只需要接 1 即可
                qu.push(t << 1);
            }
            qu.push((t << 1) + 1);
        }
    }

    return cnt;
}

int main(int argc, char *argv[]) {
    // 5
    cout << findIntegers(5) << endl;
    // 2
    cout << findIntegers(1) << endl;
    // 3
    cout << findIntegers(2) << endl;
    // // 2178309
    cout << findIntegers(1000000000) << endl;
    // cout << findIntegers(929561861) << endl;

    return 0;
}
