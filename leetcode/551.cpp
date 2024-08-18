#include "../template/head.h"
#include <bits/stdc++.h>

bool checkRecord(string s) {
    // 思路：遍历
    // 优化：中间不满足条件，直接退出
    // 时间 O(n)，空间 O(1)
    int a_cnt = 0, l_cnt = 0;
    for (char c : s) {
        if (c == 'A') {
            a_cnt++;
            if (a_cnt >= 2) {
                return false;
            }
            l_cnt = 0;
        } else if (c == 'L') {
            l_cnt++;
            if (l_cnt >= 3) {
                return false;
            }
        } else {
            l_cnt = 0;
        }
    }

    return true;
}

int main(int argc, char *argv[]) {
    // 1
    cout << checkRecord("PPALLP") << endl;
    // 0
    cout << checkRecord("PPALLL") << endl;
    // 1
    cout << checkRecord("LALL") << endl;

    return 0;
}
