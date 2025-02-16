#include "../template/head.h"
#include <bits/stdc++.h>

int numberOfBeams(vector<string> bank) {
    // 思路：模拟
    // 时间 O(mn)，空间 O(1)
    int pre = 0, cnt = 0, res = 0;
    for (int i = 0; i < bank.size(); i++) {
        cnt = 0;
        for (int j = 0; j < bank[i].size(); j++) {
            if (bank[i][j] == '1') {
                cnt++;
            }
        }

        if (cnt > 0) {
            res += pre * cnt;
            pre = cnt;
            cnt = 0;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 8
    cout << numberOfBeams({"011001", "000000", "010100", "001000"}) << endl;
    // 0
    cout << numberOfBeams({"000", "111", "000"}) << endl;

    return 0;
}
