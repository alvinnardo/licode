#include "../template/head.h"
#include <bits/stdc++.h>

vector<vector<int>> generate(int numRows) {
    // 思路：模拟
    // 时间 O(n2)，空间 O(n2)
    vector<vector<int>> vv{{1}};

    int pos = 0;
    for (int i = 0; i < numRows - 1; i++) {
        vv.push_back({1});
        for (int j = 1; j < vv[pos].size(); j++) {
            vv.back().push_back(vv[pos][j - 1] + vv[pos][j]);
        }
        vv.back().push_back(1);
        pos++;
    }

    return vv;
}

int main(int argc, char *argv[]) {
    // {{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1}}
    cout << generate(5) << endl;
    // {{1}}
    cout << generate(1) << endl;

    return 0;
}
