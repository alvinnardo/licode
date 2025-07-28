#include "../template/head.h"
#include <bits/stdc++.h>

int countMaxOrSubsets(vector<int> &&nums) {
    // 思路：DFS
    // 时间 O(2^n)，空间 O(n)
    // 选或不选
    int cnt = 0, maxv = 0;

    function<void(int, int)> dfs = [&](int pos, int tmp) {
        if (pos == nums.size()) {
            if (tmp > maxv) {
                maxv = tmp;
                cnt = 1;
            } else if (tmp == maxv) {
                cnt++;
            }
            return;
        }

        dfs(pos + 1, tmp);
        dfs(pos + 1, tmp | nums[pos]);
    };

    dfs(0, 0);
    return cnt;
}

int main(int argc, char *argv[]) {
    // 2
    cout << countMaxOrSubsets({3, 1}) << endl;
    // 7
    cout << countMaxOrSubsets({2, 2, 2}) << endl;
    // 6
    cout << countMaxOrSubsets({3, 2, 1, 5}) << endl;

    return 0;
}
