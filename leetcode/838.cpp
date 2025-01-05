#include "../template/head.h"
#include <bits/stdc++.h>

string pushDominoes(string dominoes) {
    // 思路：模拟
    // 比较当前位置离哪个操作更近
    // 时间 O(n)，空间 O(n)
    int len = dominoes.size();
    vector<int> vv(len);
    int t = INT_MAX;
    for (int i = 0; i < len; i++) {
        if (dominoes[i] == 'R') {
            t = 0;
        } else if (t != INT_MAX) {
            t++;
        }

        vv[i] = t;
        if (dominoes[i] == 'L') {
            t = INT_MAX;
        }
    }

    string res(len, ' ');
    t = INT_MAX;
    for (int i = len - 1; i >= 0; i--) {
        if (dominoes[i] == 'L') {
            t = 0;
        } else if (t != INT_MAX) {
            t++;
        }

        if (vv[i] == INT_MAX) {
            if (t == INT_MAX) {
                res[i] = '.';
            } else {
                res[i] = 'L';
            }
        } else {
            if (t == INT_MAX || vv[i] < t) {
                res[i] = 'R';
            } else if (vv[i] == t) {
                res[i] = '.';
            } else {
                res[i] = 'L';
            }
        }

        if (dominoes[i] == 'R') {
            t = INT_MAX;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // "RR.L"
    cout << pushDominoes("RR.L") << endl;
    // "LL.RR.LLRRLL.."
    cout << pushDominoes(".L.R...LR..L..") << endl;

    return 0;
}
