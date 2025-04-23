#include "../template/head.h"
#include <bits/stdc++.h>

int countLargestGroup(int n) {
    // 思路：枚举
    // 时间 O(n)，空间 O(klogn)

    int m = to_string(n).size();
    vector<int> vec(9 * m + 1); // 每一位都是 9 最大
    int max_cnt = 0, max_group = 0;

    auto getNum = [&](int t) {
        int tot = 0;
        while (t) {
            tot += t % 10;
            t /= 10;
        }
        return tot;
    };

    for (int i = 1; i <= n; i++) {
        int t = getNum(i);
        vec[t]++;
        if (vec[t] == max_cnt) {
            max_group++;
        } else if (vec[t] > max_cnt) {
            max_cnt = vec[t];
            max_group = 1;
        }
    }

    return max_group;
}

int main(int argc, char *argv[]) {
    // 4
    cout << countLargestGroup(13) << endl;
    // 2
    cout << countLargestGroup(2) << endl;
    // 6
    cout << countLargestGroup(15) << endl;
    // 5
    cout << countLargestGroup(24) << endl;

    return 0;
}
