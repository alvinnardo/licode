#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> lexicalOrder(int n) {
    vector<int> res;

    // O(n)，每个数只遍历了一次
    function<void(int)> dfs = [&](int pfx) {
        for (int i = 0; i < 10; i++) {
            int t = pfx + i;
            if (t == 0) { // 去掉 0，每次从 x0 - x9
                continue;
            }

            if (t > n) {
                return;
            }
            res.push_back(t);
            dfs(t * 10);
        }
    };

    dfs(0);
    return res;
}

int main(void) {
    printVector(lexicalOrder(123));

    return 0;
}
