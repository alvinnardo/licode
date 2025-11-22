#include "../template/head.h"
#include <bits/stdc++.h>

int minimumOperations(vector<int> &&nums) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    int res{}, t{};
    for (auto num : nums) {
        t = num % 3;
        res += min(t, 3 - t);
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 3
    cout << minimumOperations({1, 2, 3, 4}) << endl;
    // 0
    cout << minimumOperations({3, 6, 9}) << endl;

    return 0;
}
