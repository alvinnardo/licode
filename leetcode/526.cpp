#include "../template/head.h"
#include <bits/stdc++.h>

int countArrangement(int n) {
    // 思路：全排列
    // 时间 O(n!)，空间 O(n)
    vector<int> vec(n);
    iota(vec.begin(), vec.end(), 1);

    int cnt = 0;
    function<void(int)> dfs = [&](int pos) {
        if (pos == n) {
            cnt++;
            return;
        }

        for (int i = pos; i < n; i++) {
            // 及时剪枝
            if (vec[i] % (pos + 1) == 0 || (pos + 1) % vec[i] == 0) {
                swap(vec[pos], vec[i]);
                dfs(pos + 1);
                swap(vec[pos], vec[i]);
            }
        }
    };

    dfs(0);
    return cnt;
}

int main(int argc, char *argv[]) {
    for (int i = 1; i <= 15; i++) {
        cout << i << ": " << countArrangement(i) << endl;
    }
    return 0;
}
