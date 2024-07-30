#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> getGoodIndices(vector<vector<int>> variables, int target) {
    // 思路：快速幂
    // 时间 O(nlogk)，空间 O(1)

    // up 不为 0
    auto getVal = [&](int down, int up, int mod) -> int {
        if (down == 0) {
            return 0 % mod;
        }
        if (down == 1) {
            return 1 % mod;
        }

        long long sum = 1;
        long long die = down;
        while (up) {
            if (up & 1) {
                sum = (sum * die) % mod;
            }
            up >>= 1;
            die = (die * die) % mod;
        }

        return sum % mod;
    };

    vector<int> res;
    for (int i = 0; i < variables.size(); i++) {
        auto &it = variables[i];
        int f = getVal(it[0], it[1], 10);
        int s = getVal(f, it[2], it[3]);
        if (s == target) {
            res.push_back(i);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {0,2}
    printVector(getGoodIndices({{2, 3, 3, 10}, {3, 3, 3, 1}, {6, 1, 1, 4}}, 2));
    // {}
    printVector(getGoodIndices({{39, 3, 1000, 1000}}, 17));

    return 0;
}
